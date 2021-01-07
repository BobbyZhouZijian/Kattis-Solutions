#include <iostream>
using namespace std;
typedef long long ll;

ll n, k;

ll ans = 0;

void solve() {
    ll nodes = n;
    n--;
    if (n <= 1) {
        ans = n;
        return;
    }
    if (k == 1) {
        ans = 2;
        return;
    }
    if (k > n) {
        ans = n;
        return;
    }
    ll res = n % k;
    ans += res;
    n -= res;
    if (n > k) ans++;
    ans += k;
}

int main(){ 
    cin >> n >> k;
    solve();
    cout << ans << endl;
}