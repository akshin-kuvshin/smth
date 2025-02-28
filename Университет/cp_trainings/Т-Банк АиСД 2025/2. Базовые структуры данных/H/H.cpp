// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define val                 first
#define ind                 second

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& x : a)
        cin >> x;
    
    vector<lli> pref(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        pref[i + 1] = pref[i] + a[i];
    
    stack<plli> st;
    vector<lli> _front(n);
    for (int i = 0; i < (int)n; ++i) {
        while (not st.empty() and st.top().val >= a[i])
            st.pop();
        _front[i] = (st.empty() ? 0LL : (st.top().ind + 1LL));
        st.push(mp(a[i], (lli)i));
    }

    st = stack<plli>();
    vector<lli> _back(n);
    lli ans = 0LL;
    for (int i = (int)n - 1; i >= 0; --i) {
        while (not st.empty() and st.top().val >= a[i])
            st.pop();
        _back[i] = (st.empty() ? n : st.top().ind);
        st.push(mp(a[i], (lli)i));

        ans = max(
            ans,
            (pref[_back[i]] - pref[_front[i]]) * a[i]
        );
    }
    
    cout << ans << '\n';
    return;
}
