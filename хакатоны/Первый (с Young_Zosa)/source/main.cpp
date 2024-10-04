/*  /-------------------------------------------\
    |  made by Danila "akshin_" Aksionov,       |
    |       by Daniil "Young_Zosa" Zassimuk.    |
    |___________________________________________|  */










#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <dos.h>
#include "rapidjson/document.h"
typedef long long int lli;










// ОБЪЯВЛЕНИЯ КЛАССОВ

class Date {
private:
    lli day;                // день
    lli month;              // месяц
    lli year;               // год

public:
    lli get_day() { return day; }
    lli get_month() { return month; }
    lli get_year() { return year; }

    void set_day(const lli _day) { day = _day; return; }
    void set_month(const lli _month) { month = _month; return; }
    void set_year(const lli _year) { year = _year; return; }

    void print() {
        std::cout << (day / 10LL) << (day % 10LL) << '.'
                  << (month / 10LL) << (month % 10LL) << '.'
                  << (year / 1000LL) << ((year / 100LL) % 10LL) << ((year / 10LL) % 10LL) << (year % 10LL);
        return;
    }
};

// КОНВЕРТИРУЮЩИЕ ФУНКЦИИ (для удобного парсинга .json-файла)
// Строку формата "YYYY-MM-DD" в дату
Date string_to_date(const std::string S) {
    Date result;
    result.set_year(1000LL * (lli)(S[0] - '0') + 100LL * (lli)(S[1] - '0') + 10LL * (lli)(S[2] - '0') + (lli)(S[3] - '0'));
    result.set_month(10LL * (lli)(S[5] - '0') + (lli)(S[6] - '0'));
    result.set_day(10LL * (lli)(S[8] - '0') + (lli)(S[9] - '0'));
    return result;
}
// Строку в число
lli string_to_lli(const std::string S) {
    lli result = 0LL;
    for (char c : S) {
        if (c == '+') continue; // потому что также обрабатываются телефонные номера, а они начинаются с символа '+'
        result = result * 10LL + (c - '0');
    }
    return result;
}

// ПРОДОЛЖЕНИЕ ОБЪЯВЛЕНИЯ КЛАССОВ

class Education {
private:
    std::string education_type;             // тип образования (среднее, бакалавриат, магистратура и т.д.)
    std::string university;                 // учебное образование
    Date education_start;                   // начало образования
    Date education_finish;                  // конец образования

public:
    void set_university(const std::string org) { university = org; return; }
    void set_start(const Date start_date) { education_start = start_date; return; }
    void set_finish(const Date finish_date) { education_finish = finish_date; return; }
    void set_type(const std::string type) { education_type = type; return; }

    void print() {
        std::cout << "Образование:\t\t\t\t" << education_type << std::endl;
        std::cout << "   Учебное заведение:\t\t\t" << university << std::endl;
        std::cout << "   Начало получения:\t\t\t"; education_start.print(); std::cout << std::endl;
        std::cout << "   Конец получения:\t\t\t"; education_finish.print(); std::cout << std::endl;
        return;
    }
};

class Job {
private:
    std::string organization;           // учебное заведение
    std::string post;                   // занимаемая должность
    Date job_start;                     // дата вступления в должность
    Date job_finish;                    // дата ухода с должности
    std::string description;            // описание работы
    lli duration;                       // продолжительность (в годах)
    std::string skills;                 // приобретённые навыки

public:
    lli get_duration() { return duration; }

    void set_organization(std::string org) { organization = org; return; }
    void set_post(std::string _post) { post = _post; return; }
    void set_start(Date start_date) { job_start = start_date; return; }
    void set_finish(Date finish_date) { job_finish = finish_date; return; }
    void set_description(std::string _description) { description = _description; return; }
    void set_duration(lli _duration) { duration = _duration; return; }
    void set_skills(std::string _skills) { skills = _skills; return; }

    void print() {
        std::cout << "Место работы:\t\t\t" << organization << std::endl;
        std::cout << "   Должность:\t\t\t\t" << post << std::endl;
        std::cout << "   Дата вступления в должность:\t\t"; job_start.print(); std::cout << std::endl;
        std::cout << "   Дата ухода с должности:\t\t"; job_finish.print(); std::cout << std::endl;
        std::cout << "   Описание выполняемой работы:\t\t" << description << std::endl;
        std::cout << "   Длительность (в годах):\t\t" << duration << std::endl;
        std::cout << "   Приобретённые навыки:\t\t" << skills << std::endl;
        return;
    }
};

class Candidate {
public:
    std::string name;                           // ФИО
    std::string sex;                            // пол ('М' - мужчина - или 'Ж' - женщина)
    Date DOB;                                   // дата рождения
    lli age;                                    // возраст
    std::string address;                        // место проживания
    std::string country;                        // гражданство
    std::string email;                          // электронный адрес (почта)
    lli phone_number;                           // номер телефона
    std::string wished_post;                    // желаемая должность
    lli salary;                                 // желаемая зарплата
    std::vector<Education> educations;          // сведения об образовании
    std::vector<Job> jobs;                      // сведения об опыте работы

public:
    std::string get_sex() { return sex; }
    lli get_age() { return age; }
    std::string get_post() { return wished_post; }
    lli get_salary() { return salary; }
    lli get_exp() {
        lli general_exp = 0LL;
        for (std::size_t i = 0U; i < jobs.size(); ++i)
            general_exp += jobs[i].get_duration();
        return general_exp;
    }

    // ПАРСИНГ .json-файла В ЭКЗЕМПЛЯР КЛАССА Candidate
    void input(std::ifstream &fin) {
        std::string content((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));

        rapidjson::Document document;
        document.Parse(content.c_str());

        educations.clear();
        jobs.clear();

        name = document["fullname"].GetString();
        sex = document["gender"].GetString();
        DOB = string_to_date(document["birthdate"].GetString());
        age = string_to_lli(document["age"].GetString());
        address = document["residence"].GetString();
        country = document["citizenship"].GetString();
        email = document["email"].GetString();
        phone_number = string_to_lli(document["phone"].GetString());
        wished_post = document["jobtitle"][(rapidjson::SizeType)0].GetString();
        salary = string_to_lli(document["money"][(rapidjson::SizeType)0].GetString());

        std::size_t educations_number = document["education"].Size();
        educations.resize(educations_number);
        for (std::size_t i = 0U; i < educations_number; ++i) {
            educations[i].set_university(document["education"][(rapidjson::SizeType)i].GetString());
            educations[i].set_start(string_to_date(document["edu_start_date"][(rapidjson::SizeType)i].GetString()));
            educations[i].set_finish(string_to_date(document["edu_end_date"][(rapidjson::SizeType)i].GetString()));
            educations[i].set_type(document["high_edu_level"][(rapidjson::SizeType)i].GetString());
        }

        std::size_t jobs_number = document["orgName"].Size();
        jobs.resize(jobs_number);
        for (std::size_t i = 0U; i < jobs_number; ++i) {
            jobs[i].set_organization(document["orgName"][(rapidjson::SizeType)i].GetString());
            jobs[i].set_post(document["post"][(rapidjson::SizeType)i].GetString());
            jobs[i].set_start(string_to_date(document["workStartDate"][(rapidjson::SizeType)i].GetString()));
            jobs[i].set_finish(string_to_date(document["workEndDate"][(rapidjson::SizeType)i].GetString()));
            jobs[i].set_description(document["workDescription"][(rapidjson::SizeType)i].GetString());
            jobs[i].set_duration(string_to_lli(document["experience"][(rapidjson::SizeType)i].GetString()));
            jobs[i].set_skills(document["skills"][(rapidjson::SizeType)i].GetString());
        }
        
        return;
    }

    void print() {
        std::cout << "ФИО:\t\t\t\t\t" << name << std::endl;
        std::cout << "Пол:\t\t\t\t\t" << sex << std::endl;
        std::cout << "Дата рождения:\t\t\t\t"; DOB.print(); std::cout << std::endl;
        std::cout << "Возраст:\t\t\t\t" << age << std::endl;
        std::cout << "Место проживания:\t\t\t" << address << std::endl;
        std::cout << "Гражданство:\t\t\t\t" << country << std::endl;
        std::cout << "Адрес электронной почты:\t\t" << email << std::endl;
        std::cout << "Номер телефона:\t\t\t\t+" << phone_number << std::endl;
        std::cout << "Претендуемая должность:\t\t\t" << wished_post << std::endl;
        std::cout << "Желаемая зарплата:\t\t\t" << salary << std::endl;
        std::cout << std::endl;
        std::cout << "Кол-во образований:\t\t\t" << educations.size() << std::endl;
        for (std::size_t i = 0U; i < educations.size(); ++i) {
            std::cout << (char)(i + 'a') << ") ";
            educations[i].print();
        }
        std::cout << std::endl;
        std::cout << "Кол-во прошлых мест работы:\t\t" << jobs.size() << std::endl;
        std::cout << "Общий опыт работы:\t\t\t" << get_exp() << std::endl;
        for (std::size_t i = 0U; i < jobs.size(); ++i) {
            std::cout << (char)(i + 'a') << ") ";
            jobs[i].print();
        }
        return;
    }
};

// КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССОВ










// ФУНКЦИИ-КОМПАРАТОРЫ ДЛЯ ФИЛЬТРОВ И ПОД-ФИЛЬТРОВ
bool comp_age_increasing(Candidate &c1, Candidate &c2) {
    return c1.get_age() < c2.get_age();
}

bool comp_age_reducing(Candidate &c1, Candidate &c2) {
    return c1.get_age() > c2.get_age();
}

bool comp_salary_increasing(Candidate &c1, Candidate &c2) {
    return c1.get_salary() < c2.get_salary();
}

bool comp_salary_reducing(Candidate &c1, Candidate &c2) {
    return c1.get_salary() > c2.get_salary();
}

bool comp_exp_increasing(Candidate &c1, Candidate &c2) {
    return c1.get_exp() < c2.get_exp();
}

bool comp_exp_reducing(Candidate &c1, Candidate &c2) {
    return c1.get_exp() > c2.get_exp();
}










// ФУНКЦИЯ ОБНОВЛЕНИЯ БАЗЫ ДАННЫХ (массива candidates)

void database_update(std::vector<Candidate> &candidates) {
    candidates.clear();

    intptr_t res;
    _finddata_t _finddata_;

    // Ищем первый попавшийся файл с расширением .json
    if ((res = _findfirst(".\\json\\*.json", &_finddata_)) != -1) {
        Candidate tmp_candidate;
        std::string filename = "";
        filename += ".\\json\\";
        filename += _finddata_.name;
        std::ifstream fin(filename);
        tmp_candidate.input(fin);
        fin.close();
        candidates.push_back(tmp_candidate);
    }

    // Ищем следующие
    while (_findnext(res, &_finddata_) != -1) {
        Candidate tmp_candidate;
        std::string filename = "";
        filename += ".\\json\\";
        filename += _finddata_.name;
        std::ifstream fin(filename);
        tmp_candidate.input(fin);
        fin.close();
        candidates.push_back(tmp_candidate);
    }

    return;
}










int main(int argc, char **argv) {
    system("cls");
    
    std::vector<Candidate> candidates;
    database_update(candidates);




    
    if (argc == 1) { // ПРИВЕТСТВИЕ ПРИ ВХОДЕ В ПРОГРАММУ
        std::cout << "\t\t\t   Здравствуйте! Приветствуем Вас в системе обработки заявок" << std::endl;
        std::cout << "\t\t\t\t\t     компании ИНТЕГРО." << std::endl;
        std::cout << std::endl;
        std::cout << "\t   Для удобного просмотра заявок выберите фильтр, согласно которому будут выбраны или" << std::endl;
        std::cout << "\t\t\t\t отсортированы имеющиеся в базе данных заявки:" << std::endl;

        bool is_end = false;
        while (!is_end) {
            
            
            
            // РЕГУЛЯРНО ОБНОВЛЯЕМ БАЗУ ДАННЫХ
            database_update(candidates);



            std::cout << std::endl;
            std::cout << "\t1) Просмотр заявок без фильтра;" << std::endl;
            std::cout << "\t2) Фильтр по возрасту;" << std::endl;
            std::cout << "\t3) Фильтр по полу;" << std::endl;
            std::cout << "\t4) Фильтр по желаемой должности;" << std::endl;
            std::cout << "\t5) Фильтр по желаемой заработной плате;" << std::endl;
            std::cout << "\t6) Фильтр по общему опыту работы;" << std::endl;
            std::cout << "\t7) Выйти из системы обработки заявок." << std::endl;

            std::cout << std::endl;
            std::cout << "\tВведите номер выбранного вами варианта:" << std::endl;
            std::cout << "\t>> ";

            lli filter;
            std::cin >> filter;

            if (filter < 1LL or 7LL < filter) {
                system("cls");
                std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз!" << std::endl;
                std::cout << std::endl;
                std::cout << "\t  Для удобного просмотра заявок ещё раз выберите фильтр, согласно которому будут выбраны или" << std::endl;
                std::cout << "\t\t\t\t отсортированы имеющиеся в базе данных заявки:" << std::endl;
            } else {
                if (filter == 7LL) {
                    is_end = true;
                    system("cls");
                    std::cout << "\t\t\t\t   Спасибо, что выбрали нас! До свидания!" << std::endl;
                    std::cout << "\t\t\t\t      ";
                    system("pause");
                } else {
                    std::string request = "";
                    request += "main.exe ";
                    request += std::to_string(filter);
                    system(request.c_str());

                    system("cls");
                    std::cout << "\t  Для удобного просмотра заявок ещё раз выберите фильтр, согласно которому будут выбраны или" << std::endl;
                    std::cout << "\t\t\t\t отсортированы имеющиеся в базе данных заявки:" << std::endl;
                }
            }
        }
    } else { // argc == 2 // ФИЛЬТР ВЫБРАН => ФИЛЬТРУЕМ
        if (argv[1][0] == '1') { // без фильmра
            bool flag = false;
            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
            for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                flag = true;

                std::cout << ind++ << ')' << std::endl;
                candidates[i].print();
                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
            }
            if (!flag) {
                system("cls");
                std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                std::cout << "\t\t\t\t      ";
            } else
                std::cout << std::endl;
            system("pause");
        }





        else if (argv[1][0] == '2') { // по возрасту
            bool is_good_answer = false;
            while (!is_good_answer) {
                std::cout << "\tВыберите подфильтр фильтра \"Возраст\":" << std::endl;
                std::cout << std::endl;
                std::cout << "\t1) По возрастанию;" << std::endl;
                std::cout << "\t2) По убыванию;" << std::endl;
                std::cout << "\t3) Выбрать промежуток." << std::endl;
                std::cout << std::endl;
                std::cout << "\tВведите номер выбранного Вами варианта ответа:" << std::endl;
                std::cout << "\t>> ";

                lli subfilter;
                std::cin >> subfilter;

                if (subfilter < 1LL or 3LL < subfilter) {
                    system("cls");
                    std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз." << std::endl;
                    std::cout << std::endl;
                } else {
                    is_good_answer = true;
                    system("cls");

                    if (subfilter == 1LL) { // по возрастанию
                        sort(candidates.begin(), candidates.end(), comp_age_increasing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else if (subfilter == 2LL) { // по убыванию
                        sort(candidates.begin(), candidates.end(), comp_age_reducing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else { // subfilter == 3LL // выбираем промежуток
                        bool is_right_interval = false;
                        while (!is_right_interval) {
                            std::cout << "\tВведите концы промежутка (в одну строчку) [l; r], в котором будут лежать" << std::endl << "\t\t\tудовлетворяющие Вас возрасты кандидатов:" << std::endl;
                            std::cout << "\t>> ";

                            lli _l,
                                _r;
                            std::cin >> _l >> _r;

                            if (_l > _r) {
                                system("cls");
                                std::cout << "\tВведён некорректный промежуток! Левая граница не может быть больше правой. Попробуйте ещё раз!" << std::endl;
                            } else {
                                is_right_interval = true;
                                system("cls");
                                
                                sort(candidates.begin(), candidates.end(), comp_age_increasing);
                                bool flag = false;
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                                    lli age = candidates[i].get_age();
                                    if (_l <= age and age <= _r) {
                                        flag = true;

                                        std::cout << ind++ << ')' << std::endl;
                                        candidates[i].print();
                                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                    }
                                }
                                if (!flag) {
                                    system("cls");
                                    std::cout << "\t\t\t  В базе данных нет кандидатов указанного Вами возраста!" << std::endl;
                                    std::cout << "\t\t\t\t      ";
                                } else
                                    std::cout << std::endl;
                                system("pause");
                            }
                        }
                    }
                }
            }
        }





        else if (argv[1][0] == '3') { // по полу
            bool is_good_answer = false;
            while (!is_good_answer) {
                std::cout << "\tВыберите подфильтр фильтра \"Пол\":" << std::endl;
                std::cout << std::endl;
                std::cout << "\t1) Отобразить мужские заявки;" << std::endl;
                std::cout << "\t2) Отобразить женские заявки." << std::endl;
                std::cout << std::endl;
                std::cout << "\tВведите номер выбранного Вами варианта ответа:" << std::endl;
                std::cout << "\t>> ";

                lli subfilter;
                std::cin >> subfilter;

                if (subfilter < 1LL or 2LL < subfilter) {
                    system("cls");
                    std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз." << std::endl;
                    std::cout << std::endl;
                } else {
                    is_good_answer = true;
                    system("cls");

                    if (subfilter == 1LL) { // выводим мужчин
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            if (candidates[i].get_sex() == "male") {
                                flag = true;

                                std::cout << ind++ << ')' << std::endl;
                                candidates[i].print();
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                            }
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет мужских заявок!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else { // subfilter == 2LL // выводим женщин
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            if (candidates[i].get_sex() == "female") {
                                flag = true;

                                std::cout << ind++ << ')' << std::endl;
                                candidates[i].print();
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                            }
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет женских заявок!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }
                }
            }
        }





        else if (argv[1][0] == '4') { // по желаемой должности
            if (!candidates.size()) {
                std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                std::cout << "\t\t\t\t      ";
                system("pause");
            } else {
                std::set<std::string> posts;
                for (std::size_t i = 0U; i < candidates.size(); ++i)
                    posts.insert(candidates[i].get_post());
                
                bool is_good_answer = false;
                while (!is_good_answer) {
                    std::cout << "\tИмеющиеся должности:" << std::endl;
                    std::cout << std::endl;
                    std::set<std::string>::iterator it = posts.begin();
                    for (std::size_t i = 0U; i < posts.size(); ++i) {
                        std::cout << '\t' << (i + 1U) << ") ";
                        std::cout << *(it++) << ((i == posts.size() - 1U) ? '.' : ';');
                        std::cout << std::endl;
                    }

                    std::cout << std::endl;
                    std::cout << "\tВыберите должность, кандидатов желающих которую Вы хотите увидеть:" << std::endl;
                    std::cout << "\t>> ";

                    lli subfilter;
                    std::cin >> subfilter;

                    if (subfilter < 1LL or (lli)posts.size() < subfilter) {
                        system("cls");
                        std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз." << std::endl;
                        std::cout << std::endl;
                    } else {
                        is_good_answer = true;
                        system("cls");

                        it = posts.begin();
                        --subfilter;
                        while (subfilter--) ++it;

                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            if (candidates[i].get_post() == *it) {
                                std::cout << ind++ << ')' << std::endl;
                                candidates[i].print();
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                            }
                        }
                        std::cout << std::endl;
                        system("pause");
                    }
                }
            }
        }





        else if (argv[1][0] == '5') { // по желаемой заработной плате
            bool is_good_answer = false;
            while (!is_good_answer) {
                std::cout << "\tВыберите подфильтр фильтра \"Заработная плата\":" << std::endl;
                std::cout << std::endl;
                std::cout << "\t1) По возрастанию;" << std::endl;
                std::cout << "\t2) По убыванию;" << std::endl;
                std::cout << "\t3) Выбрать промежуток." << std::endl;
                std::cout << std::endl;
                std::cout << "\tВведите номер выбранного Вами варианта ответа:" << std::endl;
                std::cout << "\t>> ";

                lli subfilter;
                std::cin >> subfilter;

                if (subfilter < 1LL or 3LL < subfilter) {
                    system("cls");
                    std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз." << std::endl;
                    std::cout << std::endl;
                } else {
                    is_good_answer = true;
                    system("cls");

                    if (subfilter == 1LL) { // по возрастанию
                        sort(candidates.begin(), candidates.end(), comp_salary_increasing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else if (subfilter == 2LL) { // по убыванию
                        sort(candidates.begin(), candidates.end(), comp_salary_reducing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else { // subfilter == 3LL // выбираем промежуток
                        bool is_right_interval = false;
                        while (!is_right_interval) {
                            std::cout << "\tВведите концы промежутка (в одну строчку) [l; r], в котором будут лежать" << std::endl << "\t\t\tудовлетворяющие Вас зарплаты кандидатов:" << std::endl;
                            std::cout << "\t>> ";

                            lli _l,
                                _r;
                            std::cin >> _l >> _r;

                            if (_l > _r) {
                                system("cls");
                                std::cout << "\tВведён некорректный промежуток! Левая граница не может быть больше правой. Попробуйте ещё раз!" << std::endl;
                            } else {
                                is_right_interval = true;
                                system("cls");
                                
                                sort(candidates.begin(), candidates.end(), comp_salary_increasing);
                                bool flag = false;
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                                    if (_l <= candidates[i].get_salary() and candidates[i].get_salary() <= _r) {
                                        flag = true;

                                        std::cout << ind++ << ')' << std::endl;
                                        candidates[i].print();
                                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                    }
                                }
                                if (!flag) {
                                    system("cls");
                                    std::cout << "\t\tВ базе данных нет кандидатов, желающих иметь выбранную Вами заработную плату!" << std::endl;
                                    std::cout << "\t\t\t\t      ";
                                } else
                                    std::cout << std::endl;
                                system("pause");
                            }
                        }
                    }
                }
            }
        }





        else { // argv[1][0] = '6' // по общему опыту работы
            bool is_good_answer = false;
            while (!is_good_answer) {
                std::cout << "\tВыберите подфильтр фильтра \"Общий опыт работы\":" << std::endl;
                std::cout << std::endl;
                std::cout << "\t1) По возрастанию;" << std::endl;
                std::cout << "\t2) По убыванию;" << std::endl;
                std::cout << "\t3) Выбрать промежуток." << std::endl;
                std::cout << std::endl;
                std::cout << "\tВведите номер выбранного Вами варианта ответа:" << std::endl;
                std::cout << "\t>> ";

                lli subfilter;
                std::cin >> subfilter;

                if (subfilter < 1LL or 3LL < subfilter) {
                    system("cls");
                    std::cout << "\t\t\tОшибка! Выбранного Вами варианта ответа нет! Попробуйте ещё раз." << std::endl;
                    std::cout << std::endl;
                } else {
                    is_good_answer = true;
                    system("cls");

                    if (subfilter == 1LL) { // по возрастанию
                        sort(candidates.begin(), candidates.end(), comp_exp_increasing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else if (subfilter == 2LL) { // по убыванию
                        sort(candidates.begin(), candidates.end(), comp_exp_reducing);
                        bool flag = false;
                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                            flag = true;

                            std::cout << ind++ << ')' << std::endl;
                            candidates[i].print();
                            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                        }
                        if (!flag) {
                            system("cls");
                            std::cout << "\t\t\t\t\tВ базе данных нет кандидатов!" << std::endl;
                            std::cout << "\t\t\t\t      ";
                        } else
                            std::cout << std::endl;
                        system("pause");
                    }



                    else { // subfilter == 3LL // выбираем промежуток
                        bool is_right_interval = false;
                        while (!is_right_interval) {
                            std::cout << "\tВведите концы промежутка (в одну строчку) [l; r], в котором будут лежать" << std::endl << "\t\t\tкандидаты с удовлетворяющим Вас общим опытом работы:" << std::endl;
                            std::cout << "\t>> ";

                            lli _l,
                                _r;
                            std::cin >> _l >> _r;

                            if (_l > _r) {
                                system("cls");
                                std::cout << "\tВведён некорректный промежуток! Левая граница не может быть больше правой. Попробуйте ещё раз!" << std::endl;
                            } else {
                                is_right_interval = true;
                                system("cls");
                                
                                sort(candidates.begin(), candidates.end(), comp_exp_increasing);
                                bool flag = false;
                                std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                for (std::size_t i = 0U, ind = 1U; i < candidates.size(); ++i) {
                                    if (_l <= candidates[i].get_exp() and candidates[i].get_exp() <= _r) {
                                        flag = true;

                                        std::cout << ind++ << ')' << std::endl;
                                        candidates[i].print();
                                        std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
                                    }
                                }
                                if (!flag) {
                                    system("cls");
                                    std::cout << "\t\tВ базе данных нет кандидатов, имеющих выбранный Вами общий опыт работы!" << std::endl;
                                    std::cout << "\t\t\t\t      ";
                                } else
                                    std::cout << std::endl;
                                system("pause");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
