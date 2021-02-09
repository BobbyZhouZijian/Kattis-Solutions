#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll a[4];

void solve() {
    ll d;
    scanf("%lld%lld%lld%lld", &a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    a[2]+=d;
    ll res = a[0]*a[0]+a[1]*a[1]+a[2]*a[2]+7*a[0];

    for(int i = 0 ; i < 100 && i < d; ++i) {
        a[0]++;
        a[2]--;
        sort(a,a+3);
        ll tmp = a[0]*a[0]+a[1]*a[1]+a[2]*a[2]+7*a[0];
        if (tmp > res) res = tmp;
    }

    printf("%lld\n", res);
}

int main() {
    scanf("%d",&n);
    while (n--)
        solve();
}
