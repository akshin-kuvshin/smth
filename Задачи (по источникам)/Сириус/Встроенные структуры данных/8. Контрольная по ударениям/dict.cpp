// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
string dict_word;
unordered_map<string, vector<string>> m;
string exam,
       exam_word;
lli errors;

void solve();
string lower(string);
bool is_upper(char);

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    while (N--) {
        cin >> dict_word;
        m[lower(dict_word)].pb(dict_word);
    }

    cin.ignore();
    getline(cin, exam);
    exam.push_back(' ');
    for (char c : exam) {
        if (c == ' ') {
            if (exam_word.empty())
                continue;

            string lower_exam_word = lower(exam_word);
            if ((lli)count_if(exam_word.begin(), exam_word.end(), is_upper) != 1LL)
                ++errors;
            else if (!m[lower_exam_word].empty() and find(m[lower_exam_word].begin(), m[lower_exam_word].end(), exam_word) == m[lower_exam_word].end())
                ++errors;
            exam_word.clear();
            continue;
        }
        exam_word += c;
    }
    
    cout << errors << '\n';
    return;
}

string lower(string S) {
    for (char &c : S)
        if ('A' <= c and c <= 'Z')
            c -= 'A' - 'a';
    return S;
}

bool is_upper(char c) {
    return ('A' <= c and c <= 'Z');
}
