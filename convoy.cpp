#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n, k;

int main() {
    fast();
    cin >> n >> k;

    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    ll left = n;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for (int i = 0; i < min(n,k); ++i) {
        pq.push({v[i], i});
    }

    while (!pq.empty()) {
        auto [time, i] = pq.top(); pq.pop();
        if (time == v[i]) left--;
        if (left-4 <= 0) {
            cout << time << endl;
            break;
        } else {
            left -= 4;
            pq.push({time+2*v[i], i});
        }
    }

    return 0;
}
