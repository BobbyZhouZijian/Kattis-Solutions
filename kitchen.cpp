#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> piv;

struct HASH {
  size_t operator()(const vector<int>&x)const{
    size_t ans=1;
    for (int i = 0; i < x.size(); ++i) {
        ans *= 65;
        ans += x[i];
    }
    return ans;
  }
};

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int N, V;

int main() {
    fast();
    cin >> N;
    vector<int> v;
    for (int i =0; i < N; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }
    cin >> V;

    sort(v.rbegin(), v.rend());

    vector<int> src(N,0);
    src[0] = v[0];

    priority_queue<piv, vector<piv>, greater<piv>> pq;

    unordered_map<vector<int>, int, HASH> m;
    pq.push({0, src});
    m[src] = 0;

    bool found = false;
    int ans;

    while (!pq.empty()) {
        auto [qty, cur] = pq.top(); pq.pop();
        if (m.count(cur) && qty > m[cur]) continue;

        if (cur[0] == V) {
            found = true;
            ans = qty;
        }
        if (found) break;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i==j)  continue;
                int pour = min(cur[i], v[j]-cur[j]);
                vector<int> newa = cur;
                newa[i] -= pour;
                newa[j] += pour;
                if (!m.count(newa) || m[newa] > qty + pour) {
                    m[newa] = qty + pour;
                    pq.push({qty + pour, newa});
                }
            }
        }
    }

    if (found) cout << ans << endl;
    else cout << "impossible" << endl;

    return 0;
}
