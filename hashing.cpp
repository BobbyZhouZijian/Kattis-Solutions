#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int q;

vector<ll> P, h,h2;
const ll p = 131;
const ll M = 1e9+9;
const ll M2 = 1e9+7;

ll extEuclid(ll a, ll b, ll &x, ll &y) { // pass x and y as ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a; // gcd(a,b)
}

ll mod(ll a, ll m) {
    return ((a%m) + m) % m;
}

ll modInverse(ll b, ll m) {
    ll x,y;
    ll d = extEuclid(b,m,x,y);
    if (d != 1) return -1; // -1 for failure
    return mod(x, m);
}



vector<ll> prepareP(ll n) {
    P.assign(n,0);
    P[0] = 1;
    for (ll i = 1; i < n; ++i) {
        P[i] = (P[i-1]*p) % M;
    }
    return P;
}

vector<ll> computeRollingHash(string T) {
    vector<ll> P = prepareP(T.size());
    vector<ll> h(T.size(), 0);
    for (ll i = 0; i < T.length(); ++i) {
        if (i != 0) h[i] = h[i-1];
        h[i] = (h[i] + (T[i]*P[i]) % M) % M;
    }
    return h;
}

vector<ll> computeRollingHash2(string T) {
    vector<ll> P = prepareP(T.size());
    vector<ll> h(T.size(), 0);
    for (ll i = 0; i < T.length(); ++i) {
        if (i != 0) h[i] = h[i-1];
        h[i] = (h[i] + (T[i]*P[i]) % M2) % M2;
    }
    return h;
}

ll hash_fast(ll L, ll R) {
    if (L == 0) return h[R] * h2[R];
    ll ans = 0, ans2 = 0;
    ans = ((h[R] - h[L-1]) % M + M) % M;
    ans = (ans * modInverse(P[L], M)) % M;
    ans2 = ((h2[R] - h2[L-1]) % M2 + M2) % M2;
    ans2 = (ans2 * modInverse(P[L], M2)) % M2;
    return ans * ans2;
}

int main() {
    cin >> s >> q;
    h = computeRollingHash(s);
    h2 = computeRollingHash2(s);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << hash_fast(l, r-1) << '\n';
    }
}
