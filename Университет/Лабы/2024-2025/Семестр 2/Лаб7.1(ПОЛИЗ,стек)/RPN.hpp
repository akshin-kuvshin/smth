#ifndef __RPN
#define __RPN

#define MAX_VARS_NUMBER 100
#define MAX_VAR_NAME_LEN 100
#define NOT_FOUND -1

int priority(char operation);
void convert_to_RPN(const char* traditional, char* RPN);
int find_var(const char v[MAX_VAR_NAME_LEN], const char vars[MAX_VARS_NUMBER][MAX_VAR_NAME_LEN], int vars_top);
    // ^
    // |
    // Возвращает индекс или -1.
double count_RPN(const char* RPN); // сюда тоже можно пихать переменные (буквы/слова).
void highlight_position_cerr(int pos);

#endif
