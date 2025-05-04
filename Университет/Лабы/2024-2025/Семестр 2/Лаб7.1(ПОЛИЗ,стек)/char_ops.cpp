#include "char_ops.hpp"

bool is_digit(char c) {
    return '0' <= c and c <= '9';
}

bool is_operation(char c) { // операцию возведения в степень не будем рассматривать для простоты.
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
