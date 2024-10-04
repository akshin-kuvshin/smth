#include <iostream>
#include <set>
#define set_iterator set<int>::iterator
using namespace std;

int sz1,
    sz2,
    tmp,
    sz_ans;
set<int> set1,
         set2,
         set_ans;

set<int> symmetric_difference(set<int>*, set<int>*);

int main() {
    cin >> sz1;
    for (int i = 0; i < sz1; ++i) {
        cin >> tmp;
        set1.insert(tmp);
    }
    cin >> sz2;
    for (int i = 0; i < sz2; ++i) {
        cin >> tmp;
        set2.insert(tmp);
    }

    set_ans = symmetric_difference(&set1, &set2);
    sz_ans = set_ans.size();

    cout << sz_ans << '\n';
    for (set_iterator i = set_ans.begin(); i != set_ans.end(); ++i)
        cout << *i << ' ';
    cout << '\n';

    return 0;
}

set<int> symmetric_difference(set<int> *A, set<int> *B) {
    set<int> result;

    for (set_iterator i = A->begin(); i != A->end(); ++i)
        if (B->find(*i) == B->end())
            result.insert(*i);
    for (set_iterator i = B->begin(); i != B->end(); ++i)
        if (A->find(*i) == A->end())
            result.insert(*i);
    
    return result;
}
