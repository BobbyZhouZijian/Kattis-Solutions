#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c;
ll l, r, p;

vector<int> ps;
bitset<10000010> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1]  = 0;
    for (ll i = 2; i < 10000010; ++i)  if (bs[i]) {
        for (ll j = i*i; j < 10000010; j+=i) bs[j] = 0;
        ps.push_back(i);
    }
}

vector<ll> uf;

ll find(ll x) {
    if (uf[x] == -1) return x;
    return uf[x] = find(uf[x]);
}

void join(ll x, ll y) {
    ll fx = find(x);
    ll fy= find(y);
    if (fx != fy) uf[fx] = fy;
}

int solve() {
    uf.assign(r-l+1,-1);
    for (auto i : ps) {
        if (i < p) continue;
        for (ll j = (l/i)*i; j <= r; j+=i) {
            if (j < l || j-l < i) continue;
            join(j-l, j-l-i);
        }
    }

    ll cnt = 0;
    for (ll i = 0; i <= r-l; ++i) {
        if (uf[i] == -1) cnt++;
    }
    return cnt;
}

int main(){
    sieve();
    cin >> c;
    for (int i = 0 ; i < c; ++i) {
        cin >> l >> r >> p;        
        cout << "Case #" << i+1 << ": " << solve() << '\n';
    }
}
