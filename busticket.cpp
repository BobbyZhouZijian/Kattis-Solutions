#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1000005;

ll s,p,m,n,dp[MAXN], trips[MAXN];

ll search(int pos) {
    if (pos == n) return 0;
    ll &ans = dp[pos];
    if (ans != -1) return ans;
    int next = lower_bound(trips+pos, trips+n, trips[pos]+m) - (trips+pos);
    ll c1 = p + search(pos + next), c2 = s + search(pos+1);
    if (c1 < c2)
        return ans = c1;
    return ans = c2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s >> p >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> trips[i]; 
    }
    cout << search(0) << endl;
}
