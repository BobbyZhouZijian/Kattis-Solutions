#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    map<string, int> m;
    map<int, string> m1;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        m[name] = id;
        m1[id] = name;
        id++;
    }

    vector<vector<int>> v(n);
    for (int i = 0; i < k; ++i) {
        string n1, n2;
        cin >> n1 >> n2;
        int i1 = m[n1], i2 = m[n2];
        v[i1].push_back(i2);
        v[i2].push_back(i1);
    }

    vector<bool> valid(1 << n, false);
    for (int mask = 1; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) > c) continue;
        bool can = true;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask) {
                for (int j : v[i]) {
                    if (mask & (1 << j)) {
                        can = false;
                        break;
                    }
                }
                if (!can) {
                    break;
                }
            }
        }
        if (can) valid[mask] = true;
    }

    vector<vector<int>> dp(1 << n);

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            if (valid[sub]) {
                int other = mask ^ sub;
                if ((other == 0 || dp[other].size() > 0) && (dp[mask].size() == 0 || dp[mask].size() > 1 + dp[other].size())) {
                    dp[mask].clear();
                    for (int i : dp[other]) dp[mask].push_back(i);
                    dp[mask].push_back(sub);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].size() << endl;
    for (int i : dp[(1 << n) - 1]) {
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
                cout << m1[j] << " ";
            }
        }
        cout << endl;
    }
}