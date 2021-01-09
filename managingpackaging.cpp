#include <bits/stdc++.h>
using namespace std;

int N;

void solve() {
    string s;
    map<string, int> m1;
    map<int, string> m2;
    int id = 0;
    vector<vector<int>> g(N);
    vector<int> in(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> s;
        if (!m1.count(s)) {
            m1[s] = id;
            m2[id] = s;
            id++;
        }
        int cur = m1[s];
        while (cin.peek() == ' ') {
            cin >> s;
            if (!m1.count(s)) {
                m1[s] = id;
                m2[id] = s;
                id++;
            }
            g[m1[s]].push_back(cur);
            in[cur]++;
        }
    }

    auto cmp = [&](int i1, int i2) {
        return m2[i1] > m2[i2];
    };

    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    for (int i = 0; i < N; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int t = q.top(); q.pop();
        order.push_back(t);
        for (int j : g[t]) {
            in[j]--;
            if (in[j] == 0) {
                q.push(j);
            }
        }
    }
    if (order.size() == N) {
        for (int i : order) {
            cout << m2[i] << endl;
        }
    } else {
        cout << "cannot be ordered" << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    while (cin >> N) {
        if ( N == 0) break;
        solve();
    }
}