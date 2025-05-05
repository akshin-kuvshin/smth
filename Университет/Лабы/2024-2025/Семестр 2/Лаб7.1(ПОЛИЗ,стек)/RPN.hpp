#ifndef __RPN
#define __RPN

int priority(char operation);
void convert_to_RPN(const char* traditional, char* RPN);
void check_RPN(const char* RPN);    // если ПОЛИЗ-выражение некорректно -
                                    // выбрасывает соответствующую ошибку.
double count_RPN(const char* RPN);
void highlight_position_cerr(int pos);

#endif
