#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

map<int, vector<char>> m0;
map<char, int> m1;

string s;

void initialize() {
    m0[0] = {'A', 'E', 'I', 'O', 'U', 'H', 'W', 'Y'};
    m0[1] = {'B', 'F', 'P', 'V'};
    m0[2] = {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'};
    m0[3] = {'D', 'T'};
    m0[4] = {'L'};
    m0[5] = {'M', 'N'};
    m0[6] = {'R'};

    for (int i = 1; i <= 6; ++i) {
        for (char c : m0[i]) {
            m1[c] = i;
        }
    }
}

void solve() {
    string res;
    for (char c : s) {
        res += ('0' + m1[c]);
    }
    auto p = unique(res.begin(), res.end());
    int dist = distance(res.begin(), p);
    for (int i = 0; i < dist; ++i)
        if (res[i] != '0')
            cout << res[i];
    cout << "\n";
}

int main() {
    fast();
    initialize();

    while (cin >> s)
        solve();

    return 0;
}
