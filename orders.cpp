#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) cin >> queries[i];

    int maxq = *max_element(queries.begin(), queries.end());

    vector<vector<vector<pair<int, int>>>> dp(n, vector<vector<pair<int, int>>>(maxq + 1));
    for (int i = 1; i * nums[0] <= maxq; ++i) {
        dp[0][i * nums[0]].push_back({i, 1});
    }

    for (int i = 1; i < n; ++i) {
        for(int j = 0; j <= maxq; ++j) {
            if (dp[i - 1][j].size() > 0) {
                int tmp = j;
                while (tmp <= maxq) {
                    if (dp[i][tmp].size() > 0 || dp[i - 1][j][0].first == -1) {
                        dp[i][tmp] = {{-1, -1}};
                    } else {
                        for (auto k : dp[i - 1][j]) dp[i][tmp].push_back({k.first, k.second});
                        if (tmp > j) dp[i][tmp].push_back({(tmp - j) / nums[i], i + 1});
                    }
                    tmp += nums[i];
                }
            }
        }
        int k = nums[i];
        while (k <= maxq) {
            if (dp[i][k].size() > 0) {
                dp[i][k] = {{-1, -1}};
            } else {
                dp[i][k].push_back({(k / nums[i]), i + 1});
            }
            k += nums[i];
        }
    }
    for (int query : queries) {
        int amb = 0;
        int idx;
        for (int i = 0; i < n; ++i) {
            if (dp[i][query].size() > 0) {
                if (dp[i][query][0].first == -1) {
                    amb = 2;
                    break;
                } else {
                    idx = i;
                    amb = 1;
                }
            }
        }
        if (amb == 0) {
            cout << "Impossible" << endl;
        }
        if (amb == 1) {
            for (auto k : dp[idx][query]) {
                for (int l = 0; l < k.first; l++) cout << k.second << " ";
            }
            cout << endl;
        }
        if (amb == 2) {
            cout << "Ambiguous" << endl;
        }
    }
}