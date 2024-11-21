#include <cstring>

// P.S.: эта функция и следующая могут вернуть нуль-терминатор
int nearest_space(char *text, int from) {
    for (; text[from] and text[from] != ' '; ++from);
    return from;
}

int nearest_char(char *text, int from) {
    for (; text[from] and text[from] == ' '; ++from);
    return from;
}

int text_to_words(char *text, char **words) {
    int top = 0; // текущее кол-во найденных слов = первый незанятый индекс для слова в words

    int word_begin = nearest_char(text, 0);
    while (text[word_begin]) {
        int word_end = nearest_space(text, word_begin);
        // Теперь знаем, что текущее слово внутри text занимает позиции word_begin..word_end-1
        int word_len = word_end - word_begin;

        words[top] = new char[word_len + 1]; // +1 для нуль-терминатора
        strncpy(words[top], text + word_begin, word_len);
        words[top][word_len] = '\0';

        ++top;
        word_begin = nearest_char(text, word_end);
    }

    return top;
}

int count_vowels(char *S) {
    int vowels_number = 0;
    for (int i = 0; S[i]; ++i)
        if (S[i] == 'a' or S[i] == 'e' or S[i] == 'i' or S[i] == 'o' or S[i] == 'u')
            ++vowels_number;
    return vowels_number;
}
