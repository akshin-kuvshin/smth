// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>

using lli = long long int;
using ulli = unsigned long long int;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::next;

ulli P(ulli n);
ulli A(ulli n, ulli k);
ulli C(ulli n, ulli k);
ulli P_with_rep(const vector<ulli>& ns);
ulli A_with_rep(ulli n, ulli k);
ulli C_with_rep(ulli n, ulli k);
void overflow_exit(const string& source);

int main() {
    lli option;
    cout << "\tWelcome!" << endl
         << "Choose an option:" << endl
         << "1) Permutations (P(n));" << endl
         << "2) Placements (A(n, k));" << endl
         << "3) Combinations (C(n, k));" << endl
         << "4) Permutations with repetitions (P_with_rep(n1, n2, ..., nk));" << endl
         << "5) Placements with repetitions (A_with_rep(n, k));" << endl
         << "6) Combinations with repetitions (C_with_rep(n, k))." << endl
         << "> ";
    cin >> option;

    if (option == 1LL) {
        cout << endl
             << "Chosen option: P(n)." << endl;

        lli n;
        cout << "Enter (n):" << endl
             << "> ";
        cin >> n;

        if (n < 0LL) {
            cerr << endl
                 << "(!) ERROR: (n) must be nonnegative." << endl;
            exit(2);
        }

        ulli res = P(n);
        cout << endl
             << "\tP(" << n << ") = " << res << '.' << endl;
    } else if (option == 2LL or option == 3LL or option == 5LL or option == 6LL) {
        ulli (*func)(ulli, ulli);
        string func_name;
        switch (option)
        {
        case 2LL:
            func = A;
            func_name = "A";
            break;
        case 3LL:
            func = C;
            func_name = "C";
            break;
        case 5LL:
            func = A_with_rep;
            func_name = "A_with_rep";
            break;
        case 6LL:
            func = C_with_rep;
            func_name = "C_with_rep";
            break;
        }

        cout << endl
             << "Chosen option: " << func_name << "(n, k)." << endl;

        lli n, k;
        cout << "Enter (n):" << endl
             << "> ";
        cin >> n;
        cout << "Enter (k):" << endl
             << "> ";
        cin >> k;

        if (n < 0LL or k < 0LL) {
            cerr << endl
                 << "(!) ERROR: (n) and (k) must be nonnegative." << endl;
            exit(2);
        }
        if ((option == 2LL or option == 3LL) and n < k) {
            cerr << endl
                 << "(!) ERROR: (n) must be greater than (k)." << endl;
            exit(2);
        }

        ulli res = func(n, k);
        cout << endl
             << '\t' << func_name << '(' << n << ", " << k << ") = " << res << '.' << endl;
    } else if (option == 4LL) {
        cout << endl
             << "Chosen option: P_with_rep(n1, n2, ..., nk)." << endl;
        
        lli ns_size;
        cout << "Enter (k):" << endl
             << "> ";
        cin >> ns_size;
        if (ns_size < 0LL) {
            cerr << endl
                 << "(!) ERROR: (k) (amount of classes) must be nonnegative." << endl;
            exit(2);
        }

        vector<ulli> ns(ns_size);
        cout << "Enter (n)-array:" << endl
             << "> ";
        for (ulli& nsi : ns) {
            lli tmp;
            cin >> tmp;
            if (tmp < 0LL) {
                cerr << endl
                     << "(!) ERROR: each (ni) must be nonnegative." << endl;
                exit(2);
            }
            nsi = tmp;
        }

        ulli res = P_with_rep(ns);
        string func_view = "P_with_rep(";
        for (ulli nsi : ns)
            func_view += to_string(nsi) + ", ";
        func_view.pop_back(); func_view.pop_back();
        func_view += ')';
        cout << endl
             << '\t' << func_view << " = " << res << '.' << endl;
    } else {
        cerr << endl
             << "(!) ERROR: nonexistent option was chosen." << endl;
        exit(3);
    }
    
    return 0;
}

ulli P(ulli n) {
    ulli res = 1ULL;
    for (ulli ni = 2ULL; ni <= n; ++ni) {
        if (ULLONG_MAX / res < ni)
            overflow_exit("P(" + to_string(n) + ")");
        res *= ni;
    }
    return res;
}

ulli A(ulli n, ulli k) {
    ulli res = 1ULL;
    for (ulli ni = 2ULL, denom = 2ULL; ni <= n; ++ni) {
        if (ULLONG_MAX / res < ni)
            overflow_exit("A(" + to_string(n) + ", " + to_string(k) + ")");
        res *= ni;

        while (denom <= n - k and res % denom == 0ULL)
            res /= denom++;
    }
    return res;
}

ulli C(ulli n, ulli k) {
    ulli res = 1ULL;
    for (ulli ni = 2ULL, denom1 = 2ULL, denom2 = 2ULL; ni <= n; ++ni) {
        if (ULLONG_MAX / res < ni)
            overflow_exit("C(" + to_string(n) + ", " + to_string(k) + ")");
        res *= ni;

        while (denom1 <= k and res % denom1 == 0ULL)
            res /= denom1++;
        while (denom2 <= n - k and res % denom2 == 0ULL)
            res /= denom2++;
    }
    return res;
}

ulli P_with_rep(const vector<ulli>& ns) {
    ulli n = 0ULL;
    for (ulli nsi : ns)
        n += nsi;
    
    ulli res = 1ULL;
    vector<ulli>::const_iterator cur_denom = ns.begin();
    for (ulli ni = 2ULL, denom = 2ULL; ni <= n; ++ni) {
        if (ULLONG_MAX / res < ni) {
            string source = "P_with_rep(";
            for (ulli nsi : ns)
                source += to_string(nsi) + ", ";
            source.pop_back(); source.pop_back();
            source += ')';
            overflow_exit(source);
        }
        res *= ni;

        while (denom <= *cur_denom and res % denom == 0ULL)
            res /= denom++;
        while (next(cur_denom) != ns.end() and denom > *cur_denom) {
            ++cur_denom;
            denom = 2ULL;
        }
    }
    return res;
}

ulli A_with_rep(ulli n, ulli k) {
    ulli n0 = n,
         k0 = k;
    ulli res = 1ULL;
    while (k > 0ULL) {
        if (k % 2ULL == 1ULL) {
            if (ULLONG_MAX / res < n)
                overflow_exit("A_with_rep(" + to_string(n0) + ", " + to_string(k0) + ")");
            res *= n;
        }
        if (ULLONG_MAX / n < n)
            overflow_exit("A_with_rep(" + to_string(n0) + ", " + to_string(k0) + ")");
        n *= n;
        k /= 2LL;
    }
    return res;
}

ulli C_with_rep(ulli n, ulli k) {
    return C(n + k - 1ULL, k);
}

void overflow_exit(const string& source) {
    cerr << endl
         << "(!) ERROR: overflow happened during counting " << source << '.' << endl;
    exit(1);
}
