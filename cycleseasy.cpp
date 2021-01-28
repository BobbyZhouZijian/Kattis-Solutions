#include <bits/stdc++.h>
using namespace std;

const int mod = 9901;
int TC;
int n, k;

int dp[15][(1 << 15)];
bool g[15][15];

int tsp(int x, int mask) {
    mask = (mask | (1 << x));
    if (mask == (1 << n) - 1) {
        return !g[x][0];
    }
    int &ans = dp[x][mask];
    if (ans != -1) return ans;
    ans = 0;
    for (int j = 0; j < n; ++j) {
        if (g[x][j] || (mask & (1 << j))) continue;
        ans += tsp(j, mask);
    }
    return ans;
}

void solve() {
    memset(g, 0, sizeof g);
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int u,v;
        cin >> u >>v;
        u--; v--;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    cout << (tsp(0, 0) / 2) % mod << '\n';
}

int main() {
    cin >> TC;
    int id = 1;
    while (TC--) {
        cout << "Case #" << id++ << ": ";
        solve();
    }
}
