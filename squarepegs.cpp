#include <bits/stdc++.h>
using namespace std;

int n,m,k;
double p[105], cir[220];

int main() {
    cin >> n >> m >> k;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> cir[i];
    }
    for (int i = 0; i < k; ++i) {
        double x;
        cin >> x;
        cir[m+i] = x/sqrt(2.0);
    }

    sort(p, p+n);
    sort(cir, cir+m+k);

    int p1 = 0, p2 = 0;
    int ans = 0;
    while (p1 < n && p2 < m+k) {
        if (cir[p2] < p[p1]) {
            ans++;
            p2++;
        }
        p1++;
    }

    cout << ans << '\n';
}
