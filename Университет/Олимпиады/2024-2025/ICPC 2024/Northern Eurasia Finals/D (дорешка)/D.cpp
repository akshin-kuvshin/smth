// author: Danila "akshin_" Axyonov

// 1) CE
// 2) WA 67
// 3) WA 185
// 4) WA 224
// 5) AC!
//
// 1) До топологической сортировки допёр, только заглянув в tutorial.
// 2) Всё решение из tutorial-а целиком я вроде понял, а вроде не смог запрогать один раз. Больше не пытался - заебался.
// 3) Я решил, но это снова не принесло мне такой радости, как раньше. Теперь я просто спокоен, хоть и немного опустошён.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
using lli = long long int;
 
#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)
 
#define ST                  0LL // set true
#define SF                  1LL // set false
#define UT                  2LL // unset true
#define UF                  3LL // unset false
 
#define LF                  0b1000LL
#define RF                  0b100LL
#define LB                  0b10LL
#define RB                  0b1LL
 
const lli NO = -1LL;
 
void solve();
void top_sort(lli, const vector<vector<lli>>&, vector<plli>&, lli&, bool);
void top_sort(lli, const vector<vector<lli>>&, unordered_map<lli, lli>&, lli&, bool);
 
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
    unordered_map<lli, lli> cnt;
    vector<vector<lli>> inds(4);
    for (int i = 0; i < (int)n; ++i) {
        string type,
               result;
        cin >> type >> result;
        if (type == "set") {
            if (result == "true")
                a[i] = ST;
            else // result == "false"
                a[i] = SF;
        } else { // type == "unset"
            if (result == "true")
                a[i] = UT;
            else // result == "false"
                a[i] = UF;
        }
        ++cnt[a[i]];
        inds[a[i]].pb((lli)i);
    }
 
    lli m;
    cin >> m;
    set<plli> op;
    for (int i = 0; i < (int)m; ++i) {
        lli u,
            v;
        cin >> u >> v;
        op.insert(mp(--u, --v));
    }
 
    if (not cnt[ST] and not cnt[UT]) {
        if (cnt[SF]) {
            cout << "-1\n";
            return;
        }
        
        vector<vector<lli>> G(n);
        for (auto [u, v] : op)
            G[v].pb(u);
        vector<plli> order(n);
        for (int i = 0; i < (int)n; ++i)
            order[i] = mp(NO, (lli)i);
        lli tout = 0LL;
        for (int i = 0; i < (int)n; ++i)
            top_sort((lli)i, G, order, tout, true);
        sort(order.begin(), order.end());
        for (auto [_, ind] : order)
            cout << (ind + 1LL) << ' ';
        cout << '\n';
    } else if (not cnt[ST] and cnt[UT]) {
        cout << "-1\n";
    } else if (cnt[ST] == 1LL and not cnt[UT]) { // UF UF UF ... UF   ST   SF SF SF ... SF
        for (auto [u, v] : op) {
            if (a[u] == a[v])
                continue;
            if ((a[u] == ST and a[v] == UF) or
                 a[u] == SF /* and a[v] == ST or
                 a[u] == SF and a[v] == UF */)
            {
                cout << "-1\n";
                return;
            }
        }
        
        vector<vector<lli>> G_UF(n);
        for (auto [u, v] : op)
            if (a[u] == UF and a[v] == UF)
                G_UF[v].pb(u);
        unordered_map<lli, lli> order_map_UF;
        for (auto ind : inds[UF])
            order_map_UF[ind] = NO;
        lli tout = 0LL;
        for (auto ind : inds[UF])
            top_sort(ind, G_UF, order_map_UF, tout, true);
        vector<plli> order_UF;
        for (auto [ind, ord] : order_map_UF)
            order_UF.pb(mp(ord, ind));
        sort(order_UF.begin(), order_UF.end());
        for (auto [_, ind] : order_UF)
            cout << (ind + 1LL) << ' ';
 
        cout << (inds[ST][0] + 1LL) << ' ';
 
        vector<vector<lli>> G_SF(n);
        for (auto [u, v] : op)
            if (a[u] == SF and a[v] == SF)
                G_SF[v].pb(u);
        unordered_map<lli, lli> order_map_SF;
        for (auto ind : inds[SF])
            order_map_SF[ind] = NO;
        tout = 0LL;
        for (auto ind : inds[SF])
            top_sort(ind, G_SF, order_map_SF, tout, true);
        vector<plli> order_SF;
        for (auto [ind, ord] : order_map_SF)
            order_SF.pb(mp(ord, ind));
        sort(order_SF.begin(), order_SF.end());
        for (auto [_, ind] : order_SF)
            cout << (ind + 1LL) << ' ';
        
        cout << '\n';
    } else if (cnt[ST] == 2LL and not cnt[UT]) {
        cout << "-1\n";
    } else { // cnt[ST] == 1LL and cnt[UT] == 1LL
        // UF*   ST   SF*   UT   UF*
        unordered_set<lli> UF_front,
                           UF_back;
        for (auto [u, v] : op) {
            if (a[u] == a[v])
                continue;
            if (a[u] == UF) {
                UF_front.insert(u);
                continue;
            }
            if (a[v] == UF) {
                UF_back.insert(v);
                continue;
            }
            if ((a[u] == SF and a[v] == ST) or
                 a[u] == UT /* and a[v] == SF or
                 a[u] == UT and a[v] == ST */)
            {
                cout << "-1\n";
                return;
            }
        }
        for (auto ind : UF_front)
            if (UF_back.contains(ind)) {
                cout << "-1\n";
                return;
            }
        
        unordered_map<lli, lli> others;
        for (auto ind : inds[UF])
            if (not UF_front.contains(ind) and not UF_back.contains(ind))
                others[ind] = 0LL;
        for (auto [u, v] : op) {
            if (a[u] != UF or a[v] != UF)
                continue;
            if (UF_back.contains(u) and UF_front.contains(v)) {
                cout << "-1\n";
                return;
            }
            if ((others.contains(u) and others.contains(v)) or
                ((UF_front.contains(u) or UF_back.contains(u)) and (UF_front.contains(v) or UF_back.contains(v))))
                continue;
            // теперь одна из вершин содержится в UF_front или UF_back, а другая содержится в others.
 
            if (UF_front.contains(u))
                others[v] |= RF;
            else if (UF_front.contains(v))
                others[u] |= LF;
            else if (UF_back.contains(u))
                others[v] |= RB;
            else // UF_back.contains(v)
                others[u] |= LB;
        }
        for (auto [ind, flags] : others) {
            if (flags & LF and flags & RB) {
                cout << "-1\n";
                return;
            }
            if (flags & RB)
                UF_back.insert(ind);
            else // not (flags & RB)
                UF_front.insert(ind);
        }
 
 
 
        vector<vector<lli>> G_UF_front(n);
        for (auto [u, v] : op)
            if (UF_front.contains(u) and UF_front.contains(v))
                G_UF_front[v].pb(u);
        unordered_map<lli, lli> order_map_UF_front;
        for (auto ind : UF_front)
            order_map_UF_front[ind] = NO;
        lli tout = 0LL;
        for (auto ind : UF_front)
            top_sort(ind, G_UF_front, order_map_UF_front, tout, true);
        vector<plli> order_UF_front;
        for (auto [ind, ord] : order_map_UF_front)
            order_UF_front.pb(mp(ord, ind));
        sort(order_UF_front.begin(), order_UF_front.end());
        for (auto [_, ind] : order_UF_front)
            cout << (ind + 1LL) << ' ';
        
        cout << (inds[ST][0] + 1LL) << ' ';
 
        vector<vector<lli>> G_SF(n);
        for (auto [u, v] : op)
            if (a[u] == SF and a[v] == SF)
                G_SF[v].pb(u);
        unordered_map<lli, lli> order_map_SF;
        for (auto ind : inds[SF])
            order_map_SF[ind] = NO;
        tout = 0LL;
        for (auto ind : inds[SF])
            top_sort(ind, G_SF, order_map_SF, tout, true);
        vector<plli> order_SF;
        for (auto [ind, ord] : order_map_SF)
            order_SF.pb(mp(ord, ind));
        sort(order_SF.begin(), order_SF.end());
        for (auto [_, ind] : order_SF)
            cout << (ind + 1LL) << ' ';
 
        cout << (inds[UT][0] + 1LL) << ' ';
        
        vector<vector<lli>> G_UF_back(n);
        for (auto [u, v] : op)
            if (UF_back.contains(u) and UF_back.contains(v))
                G_UF_back[v].pb(u);
        unordered_map<lli, lli> order_map_UF_back;
        for (auto ind : UF_back)
            order_map_UF_back[ind] = NO;
        tout = 0LL;
        for (auto ind : UF_back)
            top_sort(ind, G_UF_back, order_map_UF_back, tout, true);
        vector<plli> order_UF_back;
        for (auto [ind, ord] : order_map_UF_back)
            order_UF_back.pb(mp(ord, ind));
        sort(order_UF_back.begin(), order_UF_back.end());
        for (auto [_, ind] : order_UF_back)
            cout << (ind + 1LL) << ' ';
        
        cout << '\n';
    }
    
    return;
}
 
void top_sort(lli vertex, const vector<vector<lli>>& G, vector<plli>& order, lli& tout, bool root) {
    if (order[vertex].first != NO)
        return;
    if (G[vertex].empty() and root)
        return;
    for (auto ns : G[vertex])
        top_sort(ns, G, order, tout, false);
    order[vertex].first = tout++;
    return;
}
 
void top_sort(lli vertex, const vector<vector<lli>>& G, unordered_map<lli, lli>& order, lli& tout, bool root) {
    if (order[vertex] != NO)
        return;
    if (G[vertex].empty() and root)
        return;
    for (auto ns : G[vertex])
        top_sort(ns, G, order, tout, false);
    order[vertex] = tout++;
    return;
}
