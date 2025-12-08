# author: Danila "akshin_" Axyonov
# не получается сделать >20к запросов, т.к. сайт просит пройти капчу :(

import requests
from tqdm import tqdm
import pandas as pd
base_url = r'https://api.hh.ru/'

# План-капкан:
# 1) Читаем файл со всеми вакансиями (all_vacancies.csv);
# 2) Для каждой вакансии делаем запрос, из которого вытаскиваем key_skills;
# 3) Ведём подсчёт появления того или иного key_skill для каждой role и subrole;
# 4) Пихаем все данные в pd.DataFrame-ы и пишем в .csv-файлы.

def main() -> None:
    # 1
    vacancies = pd.read_csv('vacancies.csv')

    # 2 & 3
    key_skills = set()
    role_key_skills_counter = {}
    subrole_key_skills_counter = {}
    with tqdm(desc='Requests', total=len(vacancies)) as pbar:
        for _, row in vacancies[['id', 'role_id', 'subrole_id']].iterrows():
            id, role_id, subrole_id = row['id'], row['role_id'], row['subrole_id']
            
            vacancy_response = requests.get(base_url + f'vacancies/{id}')
            if vacancy_response.status_code != 200:
                print(f'[ERROR]: vacancy_response.status_code = {vacancy_response.status_code}.')
                print(f'Params: vacancy_id = {id}.')
                return
            vacancy = vacancy_response.json()

            for key_skill in vacancy['key_skills']:
                key_skills.add(key_skill['name'])

                role_key_skills_counter.setdefault(role_id, {})
                role_key_skills_counter[role_id][key_skill['name']] = \
                    role_key_skills_counter[role_id].get(key_skill['name'], 0) + 1

                subrole_key_skills_counter.setdefault(role_id, {})
                subrole_key_skills_counter[role_id][key_skill['name']] = \
                    subrole_key_skills_counter[role_id].get(key_skill['name'], 0) + 1
            
            pbar.update(1)
    
    # 4
    role_ids = sorted(vacancies['role_id'].unique())
    subrole_ids = sorted(vacancies['subrole_id'].unique())
    key_skills = sorted(key_skills)

    role_key_skills_counter_dict = {
        'role_id': role_ids
    }
    subrole_key_skills_counter_dict = {
        'subrole_id': subrole_ids
    }
    for key_skill in key_skills:
        for role_id in role_ids:
            role_key_skills_counter_dict.setdefault(key_skill, []) \
                .append(role_key_skills_counter[role_id].get(key_skill, 0))
        for subrole_id in subrole_ids:
            subrole_key_skills_counter_dict.setdefault(key_skill, []) \
                .append(subrole_key_skills_counter[subrole_id].get(key_skill, 0))

    pd.DataFrame(role_key_skills_counter_dict).to_csv('role_key_skills.csv', index=False)
    print(f'role_key_skills.csv has been successfull recorded.')
    pd.DataFrame(subrole_key_skills_counter_dict).to_csv('subrole_key_skills.csv', index=False)
    print(f'subrole_key_skills.csv has been successfull recorded.')

    return

if __name__ == '__main__':
    main()
