#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll edmonds_karp(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      mf += f;                                   // if f > 0, add to mf
    }
    return mf;
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }

  vector<vector<int>> get_edges(int m, int n) {
    vector<vector<int>> ans(n);
    for (int u = 0; u < m; ++u) {
        for (int idx : AL[u]) {
            if (idx&1) continue;
            auto &[v, cap, flow] = EL[idx]; 
            if (flow == 1) {
                ans[v-m].push_back(u); 
            }
        }
    }
    return ans;
  }
};

int m, n;
unordered_map<string, int> m1;
unordered_map<int, string> m2;
unordered_map<int, vector<int>> ra;

bool works(int max_days) {
    int v = m + n + 2;
    max_flow mf(v);

    int src = m+n+1;
    int sink = m+n;
    for (int i = 0; i < m; ++i) {
        mf.add_edge(src, i, max_days);
    }

    for (int i = m; i < m + n; ++i) {
        mf.add_edge(i, sink, 2); 
    }

    for (auto p : ra) {
        int id = p.first;
        for (int j : p.second) {
            mf.add_edge(id, m+j-1, 1);
        }
    }

    int f = mf.dinic(src, sink);
    if (f == n*2) {
        cout << max_days << '\n';

        // print answers
        vector<vector<int>> edges = mf.get_edges(m,n);

        for (int i = 0; i < n; ++i) {
            cout << "Day " << i + 1 << ": ";
            for (int j : edges[i]) {
                cout << m2[j] << " ";
            }
            cout << '\n';
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        m1[s] = i;
        m2[i] = s;

        ra[i].resize(k);
        for (int &i : ra[i]) cin >> i;
    }

    for (int i = 1; i <= n; ++i) {
        if (works(i)) break;
    }

    return 0;
}
