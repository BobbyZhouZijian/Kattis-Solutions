#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
unordered_map<ll, ll> fib;
unordered_map<int, vector<int>> g;
unordered_set<int> ones;
bool vis[100005];
int dp[1000005];
ll h[100005];

void search(int x) {
    if (vis[x]) return;
    vis[x] = 1;

    if (fib.count(h[x])) dp[x] = 1;

    for (int v : g[x]) {
        search(v);
        dp[x] = max(dp[x], 1 + dp[v]);
    }

    if (ones.count(x)) dp[x]++;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    memset(vis, 0, sizeof vis);
    memset(dp, 0, sizeof dp);
    ll a = 1, b = 2;
    for (int i = 1; i < 100; ++i) {
        fib[a] = b;
        ll tmp = a;
        a = b;
        b += tmp;
    }
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }


    int u,v, ans = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        if (h[u] == 1 && h[v] == 1) {
            ones.insert(u);
            ones.insert(v);
        }
        if (fib.count(h[u]) && fib[h[u]] == h[v])
            g[u].push_back(v);
        if (fib.count(h[v]) && fib[h[v]] == h[u])
            g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) 
        if (!vis[i])
            search(i);

    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);

    cout << ans << endl;
}
