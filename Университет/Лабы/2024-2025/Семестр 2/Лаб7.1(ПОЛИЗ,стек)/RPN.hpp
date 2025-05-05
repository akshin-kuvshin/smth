#ifndef __RPN
#define __RPN

int priority(char operation);
void convert_to_RPN(const char* traditional, char* RPN);
double count_RPN(const char* RPN);
void highlight_position_cerr(int pos);

#endif
