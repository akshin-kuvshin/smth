#ifndef __STUD
#define __STUD

const int __MAX_NAME_LEN    = 20,
          __SUBJECTS_AMOUNT = 3;

struct Stud {
    char last_name[__MAX_NAME_LEN];
    char first_name[__MAX_NAME_LEN];
    char patronymic[__MAX_NAME_LEN];
    int group;
    int marks[__SUBJECTS_AMOUNT];
    int marks_sum;
};

#endif
