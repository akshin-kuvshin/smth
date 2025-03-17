#include "natural_merge.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>

void print_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    assert(file and "Ошибка открытия файла. Возможно, файла с введённым Вами именем не существует.");
    printf("%s: ", filename);
    char c;
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
    putchar('\n');
    return;
}

bool empty(const char* filename) {
    FILE* file = fopen(filename, "r");
    assert(file and "Ошибка открытия файла. Возможно, файла с введённым Вами именем не существует.");
    int tmp;
    bool result = (fscanf(file, "%d", &tmp) == EOF);
    fclose(file);
    return result;
}

void split_and_log(const char* input_filename) {
    FILE* F = fopen(input_filename, "r");
    FILE* G[2];
    G[0] = fopen("G1.txt", "w");
    G[1] = fopen("G2.txt", "w");
    assert(F and G[0] and G[1] and "Ошибка открытия файла. Возможно, файла с введённым Вами именем не существует.");



    int n = 0,
        x1,
        x2;
    fscanf(F, "%d", &x1);
    while (not feof(F)) {
        fprintf(G[n], "%d ", x1);
        fscanf(F, "%d", &x2);
        if (x1 > x2)
            n = 1 - n;
        x1 = x2;
    }



    fclose(F);
    fclose(G[0]);
    fclose(G[1]);

    print_file("G1.txt");
    print_file("G2.txt");
    return;
}

void merge_and_log(const char* input_filename) {
    FILE* F = fopen(input_filename, "w");
    FILE* G[2];
    G[0] = fopen("G1.txt", "r");
    G[1] = fopen("G2.txt", "r");
    assert(F and G[0] and G[1] and "Ошибка открытия файла. Возможно, файла с введённым Вами именем не существует.");



    int n,
        x[2],
        y[2];
    fscanf(G[0], "%d", &x[0]);
    fscanf(G[1], "%d", &x[1]);
    while (not feof(G[0]) and not feof(G[1])) {
        if (x[0] <= x[1])
            n = 0;
        else // x[0] > x[1]
            n = 1;
        
        fprintf(F, "%d ", x[n]);
        fscanf(G[n], "%d", &y[n]);
        if (x[n] <= y[n])
            x[n] = y[n];
        else { // x[n] > y[n]
            fprintf(F, "%d ", x[1 - n]);
            fscanf(G[1 - n], "%d", &y[1 - n]);
            while (not feof(G[1 - n]) and x[1 - n] <= y[1 - n]) {
                x[1 - n] = y[1 - n];
                fprintf(F, "%d ", x[1 - n]);
                fscanf(G[1 - n], "%d", &y[1 - n]);
            }
            x[0] = y[0];
            x[1] = y[1];
        }
    }

    while (not feof(G[0])) {
        fprintf(F, "%d ", x[0]);
        fscanf(G[0], "%d", &x[0]);
    }

    while (not feof(G[1])) {
        fprintf(F, "%d ", x[1]);
        fscanf(G[1], "%d", &x[1]);
    }



    fclose(F);
    fclose(G[0]);
    fclose(G[1]);

    print_file(input_filename);
    return;
}
