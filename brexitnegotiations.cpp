#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<bool> seen;
vector<int> in, cost, f;

void dfs(int x) {
    seen[x] = 1;
    f[x] = cost[x];

    for (int v : g[x]) {
        if (!seen[v]) dfs(v);
        f[x] = max(f[x], f[v] + 1);
    }
}

int main() {
    scanf("%d", &n);
    g.resize(n+1);
    seen.resize(n+1);
    in.resize(n+1);
    cost.resize(n+1);
    f.resize(n+1);

    int u,k,v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &u, &k);
        cost[i] = u;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &v);
            g[v].push_back(i);
            in[i]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) dfs(i);
    }

    int cnt = 0;
    int minm = 0;

    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) pq.push({f[i], i});
    }

    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        minm = max(minm, cnt + c);
        for (int v : g[x]) {
            if (--in[v] == 0) pq.push({f[v], v});
        }

        cnt++;
    }

    printf("%d\n", minm);
}
