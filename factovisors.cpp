#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

bitset<(1<<20)> bs;
vector<ll> p;
map<ll, ll> factors;

void preprocess() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < (1<<19); ++i) {
        if (bs[i]) {
            for (ll j = i*i; j < (1<<19); j +=i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

void factorize(ll m) {
    factors.clear();
    for (int i = 0; i < (int)p.size() && (p[i] * p[i] <= m); ++i) {
        while (m % p[i] == 0) {
            m /= p[i];
            factors[p[i]]++;
        }
    }
    if (m != 1) factors[m]++;
}

ll legendre(ll n, ll fac) {
    ll mult = fac;
    ll res = 0;
    while (mult <= n) {
        res += n / mult;
        mult *= fac;
    }
    return res;
}

void solve() {
    if (m == 0) {
        cout << m << " does not divide " << n << "!\n";
        return;
    }
    if (n == 0) {
        if (m == 1)
            cout << m << " divides " << n << "!\n";
        else
            cout << m << " does not divide " << n << "!\n";
        return;
    }
    factorize(m); 
    bool ok = 1;
    for (auto p : factors) {
        ll i = p.first;
        ll num = p.second;
        ll leg = legendre(n, i);
        if (num > leg) {
            ok = 0;
            break;
        }
    }
    
    if (ok) {
        cout << m << " divides " << n << "!\n";
    } else {
        cout << m << " does not divide " << n << "!\n";
    }
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    preprocess();
    while (cin >> n >> m)
        solve(); 
}