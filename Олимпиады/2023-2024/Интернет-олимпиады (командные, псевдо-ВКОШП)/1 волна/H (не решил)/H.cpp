// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
#define bit_str first
#define danger second
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 1024LL;

lli N;
int K;
lli K2; // K2 = 2^K
lli A[MAX_SIZE + 5LL];
pair<string, lli> variants[MAX_SIZE + 5LL],
                  answer;

void solve();
string get_bit_str(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    K2 = (1LL << K);
    for (int i = 0; i < (int)K2; ++i)
        cin >> A[i];
    
    for (int v = 0LL; v < (int)K2; ++v) {
        variants[v].bit_str = get_bit_str(v);
        variants[v].danger = A[v];

        lli prev = v;
        for (int i = K; i < (int)N; ++i) {
            prev <<= 1;
            if (prev >= (1LL << K))
                prev -= (1LL << K);

            lli next_0 = prev,
                next_1 = prev + 1LL;
            
            if (A[next_0] < A[next_1]) {
                variants[v].bit_str.push_back('0');
                variants[v].danger += A[next_0];
                prev = next_0;
            } else if (A[next_0] > A[next_1]) {
                variants[v].bit_str.push_back('1');
                variants[v].danger += A[next_1];
                prev = next_1;
            } else {
                // что делать, если опасности одинаковые?
                // просчитывать оба варианта нельзя, потому что это будет долго в случае, когда все опасности подстрок длины k одинаковые.
                // хз => скипаю задачу.
            }
        }
    }

    answer = variants[0];
    for (int v = 1; v < (int)K2; ++v)
        if (variants[v].danger < answer.danger)
            answer = variants[v];
    
    cout << answer.bit_str << '\n';
    return;
}

string get_bit_str(lli number) {
    string res;
    while (number) {
        res.push_back((number & 1) ? '1' : '0');
        number >>= 1;
    }

    while ((lli)res.size() < K)
        res.push_back('0');
    
    lli sz = (lli)res.size();
    lli sz2 = (sz >> 1); // sz2 = sz / 2
    for (int i = 0; i < (int)sz2; ++i)
        swap(res[i], res[sz - i - 1]);
    
    return res;
}
