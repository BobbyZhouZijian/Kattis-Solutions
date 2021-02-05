#include <bits/stdc++.h>
using namespace std;

int N;
double L, W;

int main() {
    cin >> N;
    cin >> L >> W;

    vector<pair<double, double>> v(N);
    for (int i = 0; i < N; ++i) {
        double x;
        cin >> x;
        v[i] = {x, 0.0};
    }

    sort(v.begin(), v.end());
    int n = N / 2;
    vector<pair<double, double>> left(n+1), right(n+1);

    for (int i = 0; i < n; ++i) {
        double x = (double)i * L / (double)(n-1);
        left[i] = {x, 0};
        right[i] = {x, W};
    }

    double dp[1001][1001];
    
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + hypot(left[i-1].first-v[i-1].first, left[i-1].second-v[i-1].second);
        dp[0][i] = dp[0][i-1] + hypot(right[i-1].first-v[i-1].first, right[i-1].second-v[i-1].second);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            double dl = hypot(v[i+j-1].first-left[i-1].first, v[i+j-1].second - left[i-1].second);
            double dr = hypot(v[i+j-1].first-right[j-1].first, v[i+j-1].second - right[j-1].second);
            dp[i][j] = min(dp[i-1][j] + dl, dp[i][j-1] + dr);
        }
    }

    cout << setprecision(15) << dp[n][n] << endl;
}
