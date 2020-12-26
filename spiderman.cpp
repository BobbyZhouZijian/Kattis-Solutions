#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int c;
    cin >> c;
    for (int k = 0; k < c; ++k)  {
        int n; cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        vector<vector<pair<string, int>>> dp(n + 1, vector<pair<string, int>>(1005, {"", 9999}));

        dp[0][v[0]] = {"U", v[0]}; 
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < 1005; ++j) {
                if (dp[i][j].second < 9999) {
                    if (j - v[i + 1] >= 0 && dp[i][j].second < dp[i+1][j-v[i+1]].second) {
                        dp[i + 1][j - v[i + 1]] = {dp[i][j].first + "D", dp[i][j].second};
                    }
                    if (max(dp[i][j].second, j + v[i+1]) < dp[i+1][j+v[i+1]].second) {
                        dp[i + 1][j + v[i + 1]] = {dp[i][j].first + "U", max(dp[i][j].second, j + v[i+1])};
                    }
                }
            }
        }
        if (dp[n-1][0].second == 9999) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << dp[n-1][0].first << endl;
        }
    }
}