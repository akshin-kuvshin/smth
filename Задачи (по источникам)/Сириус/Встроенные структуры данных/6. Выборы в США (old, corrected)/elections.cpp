// ОСТОРОЖНО!!!
// ВОЗМОЖЕН ПСИХИЧЕСКИЙ DAMAGE ИЗ-ЗА ЛЮТОГО ГОВНОКОДА.
// У МЕНЯ ВЕСЬ РЕДАКТОР ИМ ПРОПАХ...
// ПРОСТИ. ПРОЩАЙ. ПОКА.





// TODO (сука, 2 теста не проходят)
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define int long long

const int MAX_SIZE = 1e5;

int N,
    tmp;
map<string, int> voters_by_states;

int M;
string state,
       name;
map<string, map<string, int> > counter;

map<string, pair<string, int> > winners_in_states;

map<string, int> votes;

pair<string, int> candidates[MAX_SIZE + 5];
int top;

bool comp(const pair<string, int>&, const pair<string, int>&);

signed main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> state >> tmp;
        voters_by_states[state] = tmp;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> state >> name;
        ++counter[state][name];
        votes[name] = 0;
    }



    // План:
    // 1) Определить победителя в каждом штате
    // 2) Подсчитать количество голосов у каждого из кандидатов
    // 3) sort
    // 4) cout



    // ПУНКТ 1

    // "Инициализация" - по сути, бесполезно, но зато
    // есть ощущение определённости.
    for (map<string, int>::iterator it = voters_by_states.begin(); it != voters_by_states.end(); ++it)
        winners_in_states[it->first] = make_pair("", 0);
    
    for (map<string, map<string, int> >::iterator it = counter.begin(); it != counter.end(); ++it)
        for (map<string, int>::iterator tits = (it->second).begin(); tits != (it->second).end(); ++tits)
            if ((tits->second) == (winners_in_states[it->first].second)) {
                winners_in_states[it->first].first = min(winners_in_states[it->first].first, tits->first);
            } else if (tits->second > winners_in_states[it->first].second) {
                winners_in_states[it->first].first = tits->first;
                winners_in_states[it->first].second = tits->second;
            }
    


    // ПУНКТ 2

    for (map<string, pair<string, int> >::iterator it = winners_in_states.begin(); it != winners_in_states.end(); ++it)
        votes[(it->second).first] += voters_by_states[it->first];
    


    // ПУНКТ 3

    for (map<string, int>::iterator it = votes.begin(); it != votes.end(); ++it)
        candidates[top++] = *it;
    
    sort(candidates, candidates + top, comp);



    // ПУНКТ 4

    for (int i = 0; i < top; ++i)
        cout << candidates[i].first << ' ' << candidates[i].second << '\n';

    return 0;
}

bool comp(const pair<string, int> &x, const pair<string, int> &y) {
    if (x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}
