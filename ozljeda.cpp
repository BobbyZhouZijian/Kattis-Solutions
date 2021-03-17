#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k,q;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> k;
    vector<ll> in(2*k+4);
    ll next =0 ;
    for (int i = 1; i <= k; ++i) {
        cin >> in[i];
        next ^= in[i];
    }
    
    in[k+1] = next;

    for (int i = k + 2; i < 2 * k + 3; ++i) {
        in[i] = in[i-k-1];
    }

    vector<ll> cum(2*k+4);
    cum[0] = 0;
    for (int i = 1; i <= 2*k+2; ++i) {
        cum[i] = cum[i-1] ^ in[i];
    }

    cin >> q;
    ll l, r;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        l = (l-1) % (2*k+2)+1;
        r = (r-1) % (2*k+2)+1;

        ll res;
        if (r < l) {
            res = cum[r] ^ cum[2*k+2] ^ cum[l-1];
        } else {
            res = cum[r] ^ cum[l-1];
        }
        cout << res << '\n';
    }
}
