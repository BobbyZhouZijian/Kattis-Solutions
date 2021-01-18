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

int r, c;

void solve() {
    vector<vector<char>> arr(c, vector<char>(r));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[j][i];
        }
    }

    auto cmp = [](vector<char> v1, vector<char> v2) {
        string s1, s2;
        for (char c : v1) s1 += tolower(c);
        for (char c : v2) s2 += tolower(c);
        return s1 < s2;
    };

    stable_sort(arr.begin(), arr.end(), cmp);

    for (int j = 0; j < r; ++j) {
        for (int i = 0; i < c; ++i) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    fast();

    while (cin >> r >> c) {
        if (r == 0 && c == 0) break;
        solve();
    }

    return 0;
}
