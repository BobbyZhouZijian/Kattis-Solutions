#include <bits/stdc++.h>
using namespace std;

int c, l;
vector<vector<int>> g;
vector<bool> vis;

int bfs1(int i) {
    queue<int> q({i});
    vector<int> nodes;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        nodes.push_back(x);
        for (int j : g[x]) {
            q.push(j);
        }
    }

    for (int x : nodes) vis[x] = 0;

    return nodes.back();
}

int bfs2(int x) {
    int dep = 0;
    queue<int> q({x});
    vis[x] = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int x = q.front(); q.pop();
            for (int j : g[x]) {
                if (!vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }

        dep++;
    }

    return dep-1;
}


int main() {
    scanf("%d%d", &c,&l);
    g.resize(c+1);
    vis.assign(c+1,false);
    for (int i =0; i<l;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> res;
    for (int i = 0; i < c; ++i)
        if (!vis[i]) {
            int v = bfs1(i);
            int depth = bfs2(v);
            res.push_back(depth);
        }

    sort(res.rbegin(), res.rend());
    int ans = max(res[0], max((res[0]+1)/2 + (res[1]+1)/2 + 1, (res[1]+1)/2 + (res[2]+1)/2 + 2));
    printf("%d\n", ans); 
}
