#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll l, d, n;
ll dist[20005];

void solve() {
    for (int i = 1 ; i <= n; ++i) {
        cin >> dist[i];
    } 
    dist[0] = 6 - d < l-6 ? 6-d : l-6;
    dist[n+1] = l-6+d > 6 ? l-6+d : 6;
    sort(dist, dist + n+2);

    // for (int i = 0; i <= n+2; ++i) cout << dist[i] << " ";

    ll res = 0;
    for (int i = 0; i < n+1; ++i) {
        ll add = (dist[i+1]-dist[i])/d-1;
        res += (add > 0 ? add : 0);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> l >> d >>n ;
    solve();
}