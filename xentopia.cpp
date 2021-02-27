#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{ 
    int v,x,c;
};

struct Node {
    ll t;
    int node,r,b;

    bool operator<(const Node& other) const {
        return t > other.t;
    }
};

int n,m,k1,k2,s,ta;
vector<vector<edge>> g;

int main() {
    scanf("%d%d%d%d", &n,&m,&k1,&k2);
    g.resize(n+1);

    int u,v,x,c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &u,&v,&x,&c);
        g[u].push_back({v,x,c});
        g[v].push_back({u,x,c});
    }

    scanf("%d%d", &s, &ta);
    vector<vector<vector<ll>>> dist(n+1,vector<vector<ll>>(k1+1, vector<ll>(k2+1, -1)));
    priority_queue<Node> q;
    q.push({0,s,0,0});

    bool work = false;
    while (!q.empty()) {
        auto [t, x, r, b] = q.top(); q.pop();
        if (dist[x][r][b] != -1) continue;
        dist[x][r][b] = t;
        if (x == ta && r == k1 && b == k2) {
            work = true;
            printf("%lld\n", t);
            break;
        }

        for (edge e : g[x]) {
            int r1 = r + (e.c == 1);
            int b1 = b + (e.c == 2);
            ll t1 = t + e.x;
            if ( r1 > k1 || b1 > k2 || dist[e.v][r1][b1] != -1) continue;
            q.push({t1, e.v, r1, b1});
        }
    }

    if (!work) printf("-1\n");
}
