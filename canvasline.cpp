#include <bits/stdc++.h>
using namespace std;

int N, P;
vector<pair<int, int>> v;
vector<int> pos;
vector<int> res;

void solve() {
    vector<int> need(N, 2);
    unordered_set<int> con;
    for (int i : pos) con.insert(i);
    int j = 0;
    for (int i = 0; i < N; ++i) {
        int left = v[i].first, right = v[i].second;
        while (j < P) {
            if (pos[j] < left) j++;
            else if (pos[j] > right) break;
            else {
                need[i]--;
                if (pos[j] < right) j++;
                else break;
            }
        }
        if (need[i] < 0) {
            cout << "impossible" << endl;
            return;
        }
    }
    for (int i = 0; i < N; ++i) {
        if(need[i] == 0) continue;
        if (i + 1 < N && v[i].second == v[i+1].first && need[i+1] > 0 && con.find(v[i].second) == con.end()) {
            res.push_back(v[i].second);
            need[i]--;
            need[i+1]--;
        }
        int j = 1;
        if (need[i] > 0) {
            while (con.find(v[i].second - j) != con.end()) j++;
            res.push_back(v[i].second - j);
            need[i]--;
        }
        j++;
        if (need[i] > 0) {
            while (con.find(v[i].second - j) != con.end()) j++;
            res.push_back(v[i].second - j);
            need[i]--;
        }
    }
    cout << res.size() << endl;
    for (int i : res) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    cin >> P;
    for (int i=0; i < P; ++i) {
        int x ; cin>> x;
        pos.push_back(x);
    }
    solve();
}
