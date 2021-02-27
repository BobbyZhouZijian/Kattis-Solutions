#include <bits/stdc++.h>
using namespace std;

int n, k, ang[11], q[11];
bool poss[15][365];

void dp(int pos, int val) {
    if (pos == n) return;
    if (poss[pos][val]) return;
    poss[pos][val] = 1;

    dp(pos, (val+ang[pos]) % 360);
    dp(pos, abs(val-ang[pos]));
    dp(pos+1, val);
    dp(pos+1, (val+ang[pos]) % 360);
    dp(pos+1, abs(val-ang[pos]));
}

int main (){ 
    memset(poss, 0, sizeof poss);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &ang[i]);
    for (int i = 0; i < k; ++i)
        scanf("%d", &q[i]);

    sort(ang, ang+n);

    dp(0, 0);

    for (int i = 0; i < k; ++i) {
        bool ok = false;
        for (int j = 0; j <= n; ++j)
            if (poss[j][q[i]]) ok = true;

        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}
