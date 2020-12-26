#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }
    int e;
    cin >> e;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0 ; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    // vector = (weight, items, node)

    auto comp = [](vector<int> &q1, vector<int> &q2) { 
                if (q1[0] == q2[0]) return q1[1] > q2[1];
                return q1[0] < q2[0];
            };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

    vector<int> w(n, 99999999);
    pq.push({0, items[0], 0});
    w[0] = 0;

    int it_cnt = 0;
    int it_wt = 99999999;

    while (!pq.empty()) {
        vector<int> v = pq.top(); pq.pop();
        int wt = v[0], i = v[1], node = v[2];

        if (wt > w[node]) continue;
        if (node == n - 1) {
            if (it_wt == wt) {
                it_cnt = max(it_cnt, i);
            }
            if (it_wt > wt) {
                it_cnt = i;
                it_wt = wt;
            }
        }

        for (auto &[node2, wt2] : g[node]) {
            if (w[node2] >= w[node] + wt2) {
                w[node2] = w[node] + wt2;
                pq.push({w[node2], i + items[node2], node2});
            }
        }
    }

    if (w[n - 1] <99999999) {
        cout << w[n - 1] << " " << it_cnt << endl;
    } else {
        cout << "impossible" << endl;
    }
}