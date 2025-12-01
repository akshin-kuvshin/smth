# author: Danila "akshin_" Axyonov

import requests
from tqdm import tqdm
import pandas as pd
base_url = r'https://api.hh.ru/'

# План-капкан:
# 1) Запрос всех зон (areas), ищем там Россию, а в ней - Томскую и Новосибирскую области (точнее
#    говоря, их id-шники);
# 2) Запрос всех сфер деятельности и профессий внутри них, например: 'Автомобильный бизнес',
#    'Юристы', и др.;
# 3) Запрос всех вакансий по Томской и Новосибирской областям с классификацией их по сферам
#    деятельности и профессиям;
# 4) Пихаем все данные в pd.DataFrame;
# 5) Пишем получившийся pd.DataFrame в .csv-файл;
# 6) EDA (в другом скрипте/ноутбуке).

# TODO:
# 1) get_country;
# 2) get_region;
# 3) Добавить парсинг проф. навыков (скиллов);
# 4) Посчитать статистики по скиллам + сферам деятельности.

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
    roles_tree = dict() # {(subrole_id, subrole_name): (role_id, role_name)}
    for professional_role in professional_roles:
        for professional_subrole in professional_role['roles']:
            roles_tree[(professional_subrole['id'], professional_subrole['name'])] \
                      = (professional_role['id'], professional_role['name'])
    print(f'Total roles exist: {len(roles_tree)}.')

    # 3
    max_pages = 20

    all_vacancies = {
        'id': [],
        'name': [],
        'url': [],
        'region_id': [],
        'role_id': [],
        'role_name': [],
        'subrole_id': [],
        'subrole_name': [],
        'salary_from': [],
        'salary_to': [],
        'salary_currency': [],
        'salary_gross': [],
        'salary_mode_id': [],
        'salary_mode_name': [],
        'salary_frequency_id': [],
        'salary_frequency_name': [],
        'schedule_id': [],
        'schedule_name': []
    }
    params = {
        'per_page': 100, # maximum possible
        'only_with_salary': True
    }
    with tqdm(desc='Requests', total=2*len(roles_tree)) as pbar:
        for region_id in [tomsk_id, novosib_id]:
            params['area'] = region_id
            for subrole in roles_tree:
                role = roles_tree[subrole]
                role_id, role_name, subrole_id, subrole_name = role[0], role[1], subrole[0], subrole[1]

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
                        all_vacancies['id'].append(vacancy['id'])
                        all_vacancies['name'].append(vacancy['name'])
                        all_vacancies['url'].append(vacancy['url'])
                        all_vacancies['region_id'].append(region_id)
                        all_vacancies['role_id'].append(role_id)
                        all_vacancies['role_name'].append(role_name)
                        all_vacancies['subrole_id'].append(subrole_id)
                        all_vacancies['subrole_name'].append(subrole_name)
                        all_vacancies['salary_from'].append(vacancy['salary_range']['from'])
                        all_vacancies['salary_to'].append(vacancy['salary_range']['to'])
                        all_vacancies['salary_currency'].append(vacancy['salary_range']['currency'])
                        all_vacancies['salary_gross'].append(vacancy['salary_range']['gross'])
                        all_vacancies['salary_mode_id'].append(vacancy['salary_range']['mode']['id'])
                        all_vacancies['salary_mode_name'].append(vacancy['salary_range']['mode']['name'])
                        all_vacancies['salary_frequency_id'].append(vacancy['salary_range']['frequency']['id'] if vacancy['salary_range']['frequency'] else None)
                        all_vacancies['salary_frequency_name'].append(vacancy['salary_range']['frequency']['name'] if vacancy['salary_range']['frequency'] else None)
                        all_vacancies['schedule_id'].append(vacancy['schedule']['id'])
                        all_vacancies['schedule_name'].append(vacancy['schedule']['name'])

                    pages = vacancies_response.json()['pages']
                    page += 1
                
                pbar.update(1)
    
    total_vacancies = len(all_vacancies['id'])
    print(f'Total vacancies found: {total_vacancies}.')

    # 4
    all_vacancies = pd.DataFrame(all_vacancies)

    # 5
    all_vacancies.to_csv('all_vacancies.csv', index=False)
    print(f'All vacancies have been recorded to all_vacancies.csv.')

if __name__ == '__main__':
    main()
