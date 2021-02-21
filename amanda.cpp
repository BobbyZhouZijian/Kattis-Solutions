#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;
vector<pair<int,int>> zeros, twos;
unordered_map<int ,vector<int>> g;
bool vis[200005] , ok = true;


int dfs(int x) {
    if (vis[x]) return 0;
    vis[x] = 1;

    int res = arr[x] == 1;

    for (int v : g[x]) {
        if (!ok)break;
        if (arr[v] == 1 && arr[x] == 1) ok = false;
        if (arr[v] == 0 && arr[x] == 0) ok = false;
        if (arr[x] == 1) arr[v] = 0;
        else if (arr[x] == 0) arr[v] = 1;
        
        res += dfs(v);
    }

    return res;
}

pair<int, int> bmatch(int x) {
    if (vis[x]) return {0,0};
    vis[x] = 1;

    int r = 0, b = 0;
    if (arr[x] == 3) r++;
    else b++;

    for (int v : g[x]) {
        if (arr[v] == 3 && arr[x] == 3) ok = false;
        if (arr[v] == 4 && arr[x] == 4) ok = false;

        if (arr[x] == 3) arr[v] = 4;
        if (arr[x] == 4) arr[v] = 3;

        auto p = bmatch(v);
        r += p.first;
        b += p.second;
    }

    return {r,b};
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    int u, v, w;
    arr.resize(n + 1, 2);
    for (int i = 0; i < m ; ++i) {
        cin >> u >> v >> w;
        if (w == 0) zeros.push_back({u,v});
        if (w == 1) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (w == 2) twos.push_back({u,v});
    }

    for (auto &[x,y] : zeros) {
        arr[x] = 0;
        arr[y] = 0;
    }

    for (auto &[x,y] : twos) {
        if (!arr[x] || !arr[y]) {
            ok = false;
            break;
        }

        arr[x] = 1;
        arr[y] = 1;
    }


    int ans = 0;

    // handle 0-1 matching
    for (int i = 1; i <= n && ok; ++i) {
        if (!vis[i] && (arr[i] < 2))
            ans += dfs(i);
    }

    // handle unassigned v
    // bipartite colouring 3 vs 4
    for (int i = 1; i <= n && ok; ++i) {
        if (!vis[i] && arr[i] == 2) {
            arr[i] = 3;
            auto p = bmatch(i);
            ans += min(p.first, p.second);
        }
    }

    if (ok)
        cout << ans << endl;
    else
        cout << "impossible" << endl;
}
