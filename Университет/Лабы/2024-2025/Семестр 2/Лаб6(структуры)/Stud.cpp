#include "Stud.hpp"

int marks_sum(Stud s) {
    int res = 0;
    for (int i = 0; i < __SUBJECTS_AMOUNT; ++i)
        res += s.marks[i];
    return res;
}
