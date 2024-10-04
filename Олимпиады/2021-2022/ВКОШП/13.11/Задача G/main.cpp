#include <fstream>
#include <string>
using namespace std;

// Constants
const int letters_amount = 26;

// Variables
int _size,
    pows[letters_amount + 5];
string S;
bool do_we_have_brackets;

// Functions
void input();
void solution();
void output();
void open_brackets();
void count_pows();

int main() {
    input();
    solution();
    output();

    return 0;
}

void input() {
    ifstream fin("frac.in");
    getline(fin, S);
    fin.close();
    return;
}

void solution() {
    do
        open_brackets();
    while (do_we_have_brackets);
    count_pows();

    return;
}

void output() {
    ofstream fout("frac.out");

    bool is_found_znamenatel = false;
    for (int i = 0; i < letters_amount; i++) {
        if (pows[i] > 0) {
            if (is_found_znamenatel)
                fout << '*';

            fout << (char)(i + 'a');

            if (pows[i] > 1)
                fout << '^' << pows[i];

            is_found_znamenatel = true;
        }
    }

    if (!is_found_znamenatel)
        fout << 1;

    for (int i = 0; i < letters_amount; i++) {
        if (pows[i] < 0) {
            fout << '/' << (char)(i + 'a');
            if (pows[i] < -1)
                fout << '^' << -pows[i];
        }
    }

    fout.close();
    return;
}

void open_brackets() {
    do_we_have_brackets = false;

    _size = S.size();

    int cnt;
    for (int i = 0; i < _size;) {
        if ( (S[i] == '(') and (i == 0) ) {
            S.erase(0, 1);
            _size = S.size();

            cnt = 1;
            while (cnt != 0) {
                if (S[i] == '(') {
                    cnt++;
                    do_we_have_brackets = true;
                } else if (S[i] == ')') {
                    cnt--;
                    do_we_have_brackets = true;
                }
                i++;
            }
            i--;

            S.erase(i, 1);
            _size = S.size();
        } else if ( (S[i] == '(') and (S[i - 1] == '*') ) {
            S.erase(i, 1);
            _size = S.size();

            cnt = 1;
            while (cnt != 0) {
                if (S[i] == '(') {
                    cnt++;
                    do_we_have_brackets = true;
                } else if (S[i] == ')') {
                    cnt--;
                    do_we_have_brackets = true;
                }
                i++;
            }
            i--;

            S.erase(i, 1);
            _size = S.size();
        } else if ( (S[i] == '(') and (S[i - 1] == '/') ) {
            S.erase(i, 1);
            _size = S.size();

            cnt = 1;
            while (cnt != 0) {
                if (S[i] == '(') {
                    cnt++;
                    do_we_have_brackets = true;
                } else if (S[i] == ')') {
                    cnt--;
                    do_we_have_brackets = true;
                } else if (S[i] == '*')
                    S[i] = '/';
                else if (S[i] == '/')
                    S[i] = '*';
                i++;
            }
            i--;

            S.erase(i, 1);
            _size = S.size();
        } else
            i++;
    }
}

void count_pows() {
    _size = S.size();
    pows[S[0] - 'a']++;

    for (int i = 1; i < _size; i += 2) {
        if (S[i] == '*')
            pows[S[i + 1] - 'a']++;
        else
            pows[S[i + 1] - 'a']--;
    }

    return;
}
