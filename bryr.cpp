#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int INF = ~(1 << 31);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int x, y, single;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> single;
        x--; y--;
        v[x].push_back({y, single});
        v[y].push_back({x, single});
    }
    vector<int> dist(n, INF);
    vector<bool> vis(n, false);
    deque<int> dq;
    dq.push_back(0);
    dist[0] = 0;
    while (!dq.empty()) {
        int top = dq.front(); dq.pop_front();
        if (vis[top]) continue;
        vis[top] = true;
        for (auto p : v[top]) {
            int nb = p.first, sg = p.second;
            dist[nb] = min(dist[nb], dist[top] + sg);
            if (sg) {
                dq.push_back(nb);
            } else {
                dq.push_front(nb);
            }
        }
    }
    cout << dist[n - 1] << endl;
}