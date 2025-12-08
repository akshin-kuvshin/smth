# author: Danila "akshin_" Axyonov

from typing import Any
from copy import deepcopy
from operator import itemgetter
import requests
from tqdm import tqdm
import pandas as pd
base_url = r'https://api.hh.ru/'

# План-капкан:
# 1) Делаем запрос всех зон (areas), ищем там Россию, а в ней - Томскую и Новосибирскую области (точнее говоря, их id-шники);
# 2) Делаем запрос всех сфер деятельности и профессий внутри них, например: 'Автомобильный бизнес', 'Юристы', и др.;
# 3) Делаем запрос всех вакансий по Томской и Новосибирской областям с классификацией их по сферам деятельности и профессиям;
# 4) Пихаем все данные в pd.DataFrame-ы и пишем в .csv-файлы.

def get_area(areas: list[dict[str, Any]], area_name: str) -> dict[str, Any]:
    for country in areas:
        if country['name'] == area_name:
            return country
    print(f'[ERROR]: \'{area_name}\' was not founded.')
    exit(1)

def main() -> None:
    # 1
    areas_response = requests.get(base_url + 'areas')
    if areas_response.status_code != 200:
        print(f'[ERROR]: areas_response.status_code = {areas_response.status_code}.')
        return
    areas = areas_response.json()
    
    russia = get_area(areas, 'Россия')

    region_names = ['Томская область', 'Новосибирская область']
    region_ids = list(map(
        lambda region_name: get_area(russia['areas'], region_name)['id'],
        region_names
    ))
    
    for region_name, region_id in zip(region_names, region_ids):
        print(f'id({region_name}) = {region_id}.')
    print()
    
    # 2
    professional_roles_response = requests.get(base_url + 'professional_roles')
    if professional_roles_response.status_code != 200:
        print(f'[ERROR]: professional_roles_response.status_code = {professional_roles_response.status_code}.')
        return

    professional_roles = professional_roles_response.json()['categories']
    roles = []
    subroles = []
    roles_tree = dict() # {(subrole_id, subrole_name): (role_id, role_name)}
    for professional_role in professional_roles:
        roles.append((professional_role['id'], professional_role['name']))

        for professional_subrole in professional_role['roles']:
            subroles.append((professional_subrole['id'], professional_subrole['name']))

            roles_tree[(professional_subrole['id'], professional_subrole['name'])] \
                      = (professional_role['id'], professional_role['name'])
    print(f'Total roles exist: {len(roles_tree)}.')
    print()

    # 3
    max_pages = 20

    all_vacancies = {
        'id': [],
        'name': [],
        'url': [],
        'region_id': [],
        'role_id': [],
        'subrole_id': [],
        'salary_from': [],
        'salary_to': [],
        'salary_currency': [],
        'salary_gross': [],
        'salary_mode_id': [],
        'salary_frequency_id': [],
        'schedule_id': []
    }
    salary_modes = set()
    salary_frequencies = set()
    schedules = set()
    params = {
        'per_page': 100, # maximum possible
        'only_with_salary': True
    }
    with tqdm(desc='Requests', total=len(region_ids)*len(roles_tree)) as pbar:
        for region_id in region_ids:
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
                        all_vacancies['subrole_id'].append(subrole_id)
                        all_vacancies['salary_from'].append(vacancy['salary_range']['from'])
                        all_vacancies['salary_to'].append(vacancy['salary_range']['to'])
                        all_vacancies['salary_currency'].append(vacancy['salary_range']['currency'])
                        all_vacancies['salary_gross'].append(vacancy['salary_range']['gross'])
                        all_vacancies['salary_mode_id'].append(vacancy['salary_range']['mode']['id'])
                        all_vacancies['salary_frequency_id'].append(vacancy['salary_range']['frequency']['id'] if vacancy['salary_range']['frequency'] else None)
                        all_vacancies['schedule_id'].append(vacancy['schedule']['id'])

                        salary_modes.add((vacancy['salary_range']['mode']['id'], vacancy['salary_range']['mode']['name']))
                        if vacancy['salary_range']['frequency']:
                            salary_frequencies.add((vacancy['salary_range']['frequency']['id'], vacancy['salary_range']['frequency']['name']))
                        schedules.add((vacancy['schedule']['id'], vacancy['schedule']['name']))

                    pages = vacancies_response.json()['pages']
                    page += 1
                
                pbar.update(1)
    print()
    
    total_vacancies = len(all_vacancies['id'])
    print(f'Total vacancies found: {total_vacancies}.')
    print()

    # 4
    def to_id_name_dict(data: list[tuple[Any, Any]] | set[tuple[Any, Any]]) -> dict[str, list[Any]]:
        sorted_data = sorted(data)
        id_name_dict = {
            'id': list(map(itemgetter(0), sorted_data)),
            'name': list(map(itemgetter(1), sorted_data))
        }
        return id_name_dict

    regions = {'id': region_ids, 'name': region_names}
    roles = to_id_name_dict(roles)
    subroles = to_id_name_dict(subroles)
    salary_modes = to_id_name_dict(salary_modes)
    salary_frequencies = to_id_name_dict(salary_frequencies)
    schedules = to_id_name_dict(schedules)

    pd.DataFrame(regions).to_csv('regions.csv', index=False)
    print(f'Regions have been recorded to regions.csv.')
    pd.DataFrame(roles).to_csv('roles.csv', index=False)
    print(f'Roles have been recorded to roles.csv.')
    pd.DataFrame(subroles).to_csv('subroles.csv', index=False)
    print(f'Subroles have been recorded to subroles.csv.')
    pd.DataFrame(salary_modes).to_csv('salary_modes.csv', index=False)
    print(f'Salary modes have been recorded to salary_modes.csv.')
    pd.DataFrame(salary_frequencies).to_csv('salary_frequencies.csv', index=False)
    print(f'Salary frequencies have been recorded to salary_frequencies.csv.')
    pd.DataFrame(schedules).to_csv('schedules.csv', index=False)
    print(f'Schedules have been recorded to schedules.csv.')
    pd.DataFrame(all_vacancies).to_csv('vacancies.csv', index=False)
    print(f'All vacancies have been recorded to vacancies.csv.')

if __name__ == '__main__':
    main()
