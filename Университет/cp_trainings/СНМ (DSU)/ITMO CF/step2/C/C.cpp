// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;



class DSU {
private:
    vector<int> p;
    vector<int> size;
    set<pii> S; // contains consistent disjoint segments

public:
    DSU(int original_size) {
        this->p.resize(original_size);
        this->size.resize(original_size);
        for (int i = 0; i < original_size; ++i) {
            this->p[i] = i;
            this->size[i] = 1;
            this->S.insert({i, i});
        }
        return;
    }

    int get(int a) {
        if (this->p[a] != a)
            this->p[a] = this->get(this->p[a]);
        return this->p[a];
    }

    void unite(int a, int b) {
        a = this->get(a);
        b = this->get(b);
        if (a == b)
            return;
        if (this->size[a] < this->size[b])
            swap(a, b);
        this->p[b] = a;
        this->size[a] += this->size[b];
        return;
    }

    void seg_unite(int a, int b) {
        auto it1 = this->S.lower_bound({a, a}); // (it1) points to segment which contains (a)
        if (it1 == this->S.end() or a < it1->first) --it1; // case when required segment start not from (a)
        pii cur = *it1; // the segment itself
        for (auto it2 = this->S.lower_bound({cur.second + 1, cur.second + 1}); // segment after (cur)
             it2 != this->S.end() and it2->first <= b;
             it2 = this->S.lower_bound({cur.second + 1, cur.second + 1}))
        {
            // uniting segments
            cur.second = it2->second;
            this->unite(cur.first, cur.second);

            // correcting (S) and (it1)
            S.erase(it1); S.erase(it2);
            S.insert(cur);
            it1 = S.find(cur);
        }

        return;
    }
};



void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    int n,
        q;
    cin >> n >> q;

    DSU dsu(n);
    while (q--) {
        int type,
            x,
            y;
        cin >> type >> x >> y;
        --x, --y;

        if (type == 1)
            dsu.unite(x, y);
        else if (type == 2)
            dsu.seg_unite(x, y);
        else // type == 3
            cout << ((dsu.get(x) == dsu.get(y)) ? "YES" : "NO") << '\n';
    }
    
    return;
}
