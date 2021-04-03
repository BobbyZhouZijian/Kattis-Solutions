#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int as[100005], bs[100005];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &as[i]);
    }
    for (int i= 0; i< n; ++i) {
        scanf("%d", &bs[i]);
    }

    ll r_w = 0, r_r = 0, r_y = 0;
    ll c_0 = 0, c_1 = 0, c_2 = 0;

    for (int i = 0; i < n; i += 3) {
        c_0 += bs[i];
        if (i+1<n) c_1 += bs[i+1];
        if (i+2<n) c_2 += bs[i+2];
    }

    for (int i = 0; i < n; ++i) {
        if (i%3==0) {
            r_w += c_0 * as[i];
            r_y += c_1 * as[i];
            r_r += c_2 * as[i];
        } else if (i%3==1) {
            r_y += c_0 * as[i];
            r_r += c_1 * as[i];
            r_w += c_2 * as[i];
        } else {
            r_r += c_0 * as[i];
            r_w += c_1 * as[i];
            r_y += c_2 * as[i];
        }
    }

    printf("%lld %lld %lld\n", r_y, r_r, r_w);
}