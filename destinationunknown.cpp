#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tuple<ll, int, bool> tup;

struct HASH {
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int TC;
const ll INF = (ll)1e16;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    int s, g, h;
    cin >> s >> g >> h;
    vector<vector<pair<ll, ll>>> G(n+1);
    for (int i = 0; i < m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }

    priority_queue<tup, vector<tup>, greater<tup>> pq;
    vector<pair<ll, bool>> dist(n+1, {INF, false});

    dist[s].first = 0;
    pq.push({0, s, false});

    while (!pq.empty()) {
        ll w; int node; bool used;
        tie(w, node, used) = pq.top(); pq.pop();

        if (w > dist[node].first) continue;

        for (auto [w1, node1] : G[node]) {
            if (dist[node1].first > dist[node].first + w1) {
                dist[node1].first = dist[node].first + w1;
                if ((g == node && h == node1) || (g == node1 && h == node)) {
                    dist[node1].second = true;
                    pq.push({dist[node1].first, node1, true});
                } else {
                    dist[node1].second = used;
                    pq.push({dist[node1].first, node1, used});
                }
            } else if (dist[node1].first == dist[node].first + w1) {
                if ((g == node && h == node1) || (g == node1 && h == node)) {
                    dist[node1].second = true;
                    pq.push({dist[node1].first, node1, true});
                } else if (used) {
                    dist[node1].second = used;
                    pq.push({dist[node1].first, node1, used});
                }
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < t; ++i) {
        int x; cin >> x;
        if (dist[x].second && dist[x].first != INF) res.push_back(x);
    }
    sort(res.begin(), res.end());
    for (int i : res) cout << i << ' ';
    cout << '\n';
}

int main() {
    fast();

    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}
