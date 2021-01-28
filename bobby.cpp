#include <bits/stdc++.h>
using namespace std;

int TC;
int r,s,x,y,w;

double mem[100][100];

double dp(int rolls, int tot) {
    if (rolls > y) return 0.0;
    if (tot >= x) return 1.0;
    if (mem[rolls][tot] > 0) {
        return mem[rolls][tot];
    }
    double res = ((double)(s-r+1) * dp(rolls+1, tot+1)
        + (double)(r-1) * dp(rolls+1, tot)) / (double)s;
    mem[rolls][tot] = res;
    return res;
}

void solve() {
    cin >> r>>s>>x>>y>>w;
    memset(mem, 0, sizeof mem);
    double res = dp(0, 0);
    if (res * w > 1) {
        cout << "yes\n";
    } else cout << "no\n";
}

int main() {
    cin >> TC;
    while (TC--) {
        solve();
    }
}
