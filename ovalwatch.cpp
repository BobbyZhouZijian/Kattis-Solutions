#include <bits/stdc++.h>
using namespace std;

int N, K;

void solve() {
    vector<pair<int, int>> v;
    for (int i = 0; i < K; ++i) {
        int x , y;
        cin >>x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());

    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
        pos[i] = i;
    }

    for (auto p : v) {
        int l = p.second, r = l + 1;
        if (pos[l] == -1) continue;
        swap(pos[l], pos[r]);
    }
    vector<int> end(N);
    for (int i = 0 ; i< N; ++i) {
        end[pos[i]] = i;
    }
    for (int i : end) cout << i << " ";
    cout << endl;
}

int main() {
    cin >> N >> K;
    solve();
}