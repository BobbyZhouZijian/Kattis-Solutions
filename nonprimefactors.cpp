#include <bits/stdc++.h>
using namespace std;

int TC;
int n;
bitset<2000> bs;
vector<int> p;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < 2000; ++i) if (bs[i]) {
        for (int j = i*i; j < 2000; j+=i) {
            bs[j] = 0;
        }
        p.push_back(i);
    }
}

int calc(int n) {
    int ans1 = 1;
    int ans2 = 0;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= n; ++i) {
        int power = 0;
        if (n%p[i]==0) ans2++;
        while (n%p[i]==0) { n/=p[i]; power++; }
        ans1 *= power + 1;
    }

    if (n!=1) ans1 *= 2;
    if (n!=1) ans2++;
    return ans1 - ans2;
}

int cache[2000005];

void solve() {
    scanf("%d",&n); 
    int &ans = cache[n];
    if (ans == -1) ans = calc(n);
    printf("%d\n", ans);
}

int main() {
    sieve();
    memset(cache,-1,sizeof cache);
    scanf("%d",&TC);
    while (TC--)
        solve();
}
