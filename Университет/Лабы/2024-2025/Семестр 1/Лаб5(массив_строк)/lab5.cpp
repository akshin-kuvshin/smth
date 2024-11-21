// ЗАДАЧА: Дан текст. Группы символов, разделённые пробелами (одним или несколькими), будем называть словами. Найти все слова, содержащие наибольшее количество гласных латинских букв (a, e, i, o, u).

#include <cstdio>
#include "_string.hpp"  // Моя библиотека с некоторыми функциями для работы над строками/текстами/словами

int main() {
    const int MAX_WORDS_NUMBER = 100,
              MAX_TEXT_LEN     = 10000;
    char **words = new char*[MAX_WORDS_NUMBER];
    for (int i = 0; i < MAX_WORDS_NUMBER; ++i)
        words[i] = nullptr;
    char *text = new char[MAX_TEXT_LEN];

    printf_s("\nВведите Ваш текст в одну строку:\n");
    gets(text);
    int len = text_to_words(text, words);

    int *vowel_cnt = new int[len]; // Параллельный массив-счётчик гласных букв в слове
    for (int i = 0; i < len; ++i)
        vowel_cnt[i] = count_vowels(words[i]);
    
    int max_cnt = vowel_cnt[0];
    for (int i = 1; i < len; ++i)
        if (max_cnt < vowel_cnt[i])
            max_cnt = vowel_cnt[i];
    
    printf_s("\nСлова с наибольшим (%d) количеством гласных букв в них:\n", max_cnt);
    for (int i = 0; i < len; ++i)
        if (vowel_cnt[i] == max_cnt)
            puts(words[i]);

    // DELETING
    for (int i = 0; i < MAX_WORDS_NUMBER; ++i) {
        if (!words[i]) break;
        delete[] words[i];
    }
    delete[] words;
    delete[] text;
    delete[] vowel_cnt;
    return 0;
}
