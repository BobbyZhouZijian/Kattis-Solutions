#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,d,e,f,g;

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

ll gcd(ll a, ll b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    return gcd(b,a%b);
}

// non-coprime
pair<ll, ll> crt( vector<ll> A, vector<ll> M ) {
    int n = A.size();
 
    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        ll a2 = A[i];
        ll m2 = M[i];
 
        ll g = gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        ll p, q;
        extEuclid(m1/g, m2/g, p, q);
 
        ll mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        ll x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}

int main() {
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<ll> sizes;
    for (ll i = 0; i*2 <= a; ++i) {
        sizes.push_back((a-2*i)*(b-2*i)*i);
    }
    sort(sizes.begin(), sizes.end());
    ll k = distance(sizes.begin(), unique(sizes.begin(), sizes.end()));
    ll s3 = sizes[k-3];
    ll s2 = sizes[k-2];
    ll s1 = sizes[k-1];

    vector<ll> r({c,d,e}), m({s1,s2,s3});

    auto [res, div] = crt(r,m);

    if (res <= g && res >= f) cout << res << '\n';
    else if (res > g) {
        while (res > g) res -= div;
        cout << res << '\n';
    } else {
        while (res < f) res += div;
        cout << res << '\n';
    }
}
