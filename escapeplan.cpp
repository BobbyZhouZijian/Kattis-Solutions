#include <bits/stdc++.h>
using namespace std;

vector<pair<double, double>> robots;
vector<pair<double, double>> holes;
vector<int> l, r;
vector<bool> vis;
int N, M;

bool dfs(int x, double thr) {
    for (int i = 0; i < M; ++i) {
        if (vis[i]) continue;
        double x1 = robots[x].first, y1 = robots[x].second;
        double x2 = holes[i].first, y2 = holes[i].second;
        if (hypot(x1 - x2, y1 - y2) > thr * 10.0) {
            continue;
        }
        vis[i] = true;
        if (r[i] == -1 || dfs(r[i], thr)) {
            r[i] = x;
            l[x] = i;
            return 1;
        }
    }
    return 0;
}

int hungarian(double thr) {
    l.clear(); r.clear();
    l.resize(N, -1);
    r.resize(M, -1);

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        if (l[i] == -1) {
            vis.clear();
            vis.resize(M, false);
            ans += dfs(i, thr);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int cnt = 1;
    while (cin >> N) {
        if (N == 0) break;
        robots.clear(); holes.clear();
        for (int i = 0; i < N;++i) {
            double x, y;
            cin >> x >> y;
            robots.push_back({x, y});
        }
        cin >> M;
        for (int i = 0; i < M; ++i) {
            double x , y;
            cin >> x >> y;
            holes.push_back({x, y});
        }


        cout << "Scenario " << cnt++ << endl;
        // v1
        int v1 = hungarian(5.0);
        cout << "In 5 seconds " << v1 << " robot(s) can escape" << endl;
        int v2 = hungarian(10.0);
        cout << "In 10 seconds " << v2 << " robot(s) can escape" << endl;
        int v3 = hungarian(20.0);
        cout << "In 20 seconds " << v3 << " robot(s) can escape" << endl;
        cout << endl;
    }
}