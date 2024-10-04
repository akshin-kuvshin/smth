// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli score(lli, const vector<lli>&, const vector<lli>&, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N,
        K,
        PB,
        PS;
    cin >> N >> K >> PB >> PS;
    --PB; --PS;

    vector<lli> p(N);
    for (int i = 0; i < (int)N; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector<lli> A(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    

    lli score_B = score(PB, p, A, N, K),
        score_S = score(PS, p, A, N, K);

    if (score_B > score_S)
        cout << "Bodya\n";
    else if (score_B < score_S)
        cout << "Sasha\n";
    else
        cout << "Draw\n";
    return;
}

lli score(lli pos, const vector<lli> &p, const vector<lli> &A, lli N, lli k) {
    lli l = min(k, N);
    
    vector<lli> S(l);
    lli ppos = pos;
    for (int i = 0; i < (int)l; ++i) {
        S[i] = A[ppos];
        ppos = p[ppos];
    }

    vector<lli> pref_sum(l),
                pref_max(l);
    pref_sum[0] = pref_max[0] = S[0];
    for (int i = 1; i < (int)l; ++i) {
        pref_sum[i] = pref_sum[i - 1] + S[i];
        pref_max[i] = max(pref_max[i - 1], S[i]);
    }

    vector<lli> scores(l);
    for (int i = 0; i < (int)l; ++i) {
        --k;
        scores[i] = pref_sum[i] + k * pref_max[i];
    }

    return *max_element(scores.begin(), scores.end());
}
