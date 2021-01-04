#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<int> colors;
vector<vector<ll>> memo;

ll cnt = 0;

ll dfs(int x, int bits) {
    if ((1 << colors[x]) & bits) {
        return 0;
    }
    if (memo[bits][x]) {
        return memo[bits][x];
    }
    ll res = 1;
    for (int nb : g[x]) {
        res += dfs(nb, bits | (1 << colors[x]));
    }
    memo[bits][x] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    colors.resize(n);
    g.resize(n);
    memo.resize(1 << k, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
        colors[i]--;
    }
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cnt += dfs(i, 0);
    }
    cout << cnt - n << endl;
}