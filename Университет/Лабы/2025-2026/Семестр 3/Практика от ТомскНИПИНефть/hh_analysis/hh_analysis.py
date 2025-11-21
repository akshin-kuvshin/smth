import requests
import json
base_url = r'https://api.hh.ru/'

# План-капкан:
# 1) Запрос всех зон (areas), ищем там Россию, а в ней - Томскую и Новосибирскую области (точнее
#    говоря, их id-шники);
# 2) Запрос всех сфер деятельности, например: 'Автомобильный бизнес', 'Юристы', и др.;
# 3) Запрос всех вакансий по Томской и Новосибирской областям с классификацией их по сферам
#    деятельности;
# 4) EDA. [TODO]

def main() -> None:
    # 1
    areas_response = requests.get(base_url + 'areas')
    if areas_response.status_code != 200:
        print(f'[ERROR]: areas_response.status_code = {areas_response.status_code}.')
        return
    
    areas = areas_response.json()
    for country in areas:
        if country['name'] == 'Россия':
            areas_of_russia = country['areas']
            break
    else:
        print(f'[ERROR]: \'Россия\' was not founded in areas.')
        return
    
    tomsk_id = novosib_id = None
    for region in areas_of_russia:
        if region['name'] == 'Томская область':
            tomsk_id = region['id']
        elif region['name'] == 'Новосибирская область':
            novosib_id = region['id']
        
        if tomsk_id and novosib_id:
            break
    else:
        print(f'[ERROR]: Either \'Томская область\' or \'Новосибирская область\' was not founded in areas_of_russia.')
        return
    
    print(f'tomsk_id = {tomsk_id}, novosib_id = {novosib_id}.')
    
    # 2
    professional_roles_response = requests.get(base_url + 'professional_roles')
    if professional_roles_response.status_code != 200:
        print(f'[ERROR]: professional_roles_response.status_code = {professional_roles_response.status_code}.')
        return

    professional_roles = professional_roles_response.json()['categories']
    all_roles = dict() # {role_id: (role_name, [subrole_id, subrole_name])}
    for professional_role in professional_roles:
        for professional_subrole in professional_role['roles']:
            all_roles.setdefault(professional_role['id'], (professional_role['name'], [])) \
                     [1] \
                     .append((professional_subrole['id'], professional_subrole['name']))
    print(f'Total roles exist: {sum(len(all_roles[role_id][1]) for role_id in all_roles)}.')

    # 3
    max_pages = 20

    all_vacancies = dict()
    params = {
        'per_page': 100, # maximum possible
        'only_with_salary': True
    }
    for region_id in [tomsk_id, novosib_id]:
        params['area'] = region_id
        for role_id in all_roles:
            for subrole_id, _ in all_roles[role_id][1]:
                params['professional_role'] = subrole_id
                pages, page = max_pages, 0
                while page < pages:
                    params['page'] = page

                    vacancies_response = requests.get(base_url + 'vacancies', params=params)
                    if vacancies_response.status_code != 200:
                        print(f'[ERROR]: vacancies_response.status_code = {vacancies_response.status_code}.')
                        print(f'Params: page = {page}, region_id = {region_id}, role_id = {role_id}.')
                        return
                    
                    vacancies = vacancies_response.json()['items']
                    for vacancy in vacancies:
                        all_vacancies.setdefault(region_id, dict()) \
                                     .setdefault(role_id, dict()) \
                                     .setdefault(subrole_id, []) \
                                     .append({
                                         'id': vacancy['id'],
                                         'name': vacancy['name'],
                                         'salary_range': vacancy['salary_range'],
                                         'url': vacancy['url']
                                     })

                    pages = vacancies_response.json()['pages']
                    page += 1
    
    total_vacancies = 0
    for _, roles_ in all_vacancies.items():
        for _, subroles_ in roles_.items():
            for _, vacancies_ in subroles_.items():
                total_vacancies += len(vacancies_)
    print(f'Total vacancies found: {total_vacancies}.')

    # Saving results to .json-file
    output_filename = 'all_vacancies.json'
    with open(output_filename, 'w') as output_file:
        json.dump(all_vacancies, output_file, indent=4)
    print(f'All {total_vacancies} vacancies have been successfully recorded to \'{output_filename}\'.')

    # 4 [TODO]

if __name__ == '__main__':
    main()
