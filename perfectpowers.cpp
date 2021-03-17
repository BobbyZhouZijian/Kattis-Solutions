#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
vector<ll> p;
bitset<10000010> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i < 10000010; ++i) if (bs[i]) {
        for (ll j = i*i; j < 10000010; j +=i) {
            bs[j] = 0;
        }
        p.push_back(i);
    }
}

ll gcd(ll x, ll y) {
    if (x < y) swap(x,y);
    if (y == 0) return x;
    return gcd(y,x%y);
}

void solve() {
    unordered_map<ll,ll> m;

    bool neg = 0;
    if (x < 0) {
        x = -x;
        neg = 1;
    }
    for (ll i = 0; i < p.size() && p[i]*p[i] <= x; ++i) {
        while (x%p[i]==0) {
            x /= p[i];
            m[p[i]]++;
        }
    }
    if (x != 1) m[x]++;

    vector<ll> pows;
    for (auto p : m) {
        pows.push_back(p.second);
    }

    ll g = pows[0];
    for (ll x : pows) g = gcd(g, x);

    if (!neg) {
        cout << g << '\n';
    } else {
        while (g%2==0) g/=2;
        cout << g << '\n';
    }
}

int main() {
    sieve();
    while (cin >> x) {
        if (x == 0) break;
        solve();
    }
}
