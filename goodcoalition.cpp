#include <bits/stdc++.h>
using namespace std;

int TC;
int n;
int ppl[155];
double prob[155];
double dp[155][155];

double search(int pos, int seats) {
    if (pos == n && seats < 76) return 0;
    if (seats > 75) return 1.0;
    double &ans = dp[pos][seats];
    if (ans > -1) return ans;
    ans = 0.0;
    double s1 = search(pos+1, seats + ppl[pos]) * prob[pos];
    double s2 = search(pos+1, seats);
    return ans = max(ans, max(s1, s2));
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    int x; double y;
    for (int i = 0; i < n; ++i ){
        cin >> x >> y;
        ppl[i] = x;
        prob[i] = y/100.0;
    }
    cout << search(0,0) * 100 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(15);
    cin >> TC;
    while (TC--) {
        solve();
    }
}
