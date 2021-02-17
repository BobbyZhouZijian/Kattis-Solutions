#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int TC, n;

ll a[805], b[805];

ll solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);

    sort(a, a+n);
    sort(b, b+n);

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i] * b[n-i-1];
    return ans;
}

int main() {
    scanf("%d", &TC);
    int c = 1;
    while (TC--) {
        printf("Case #%d: %lld\n", c++, solve());
    }
}
