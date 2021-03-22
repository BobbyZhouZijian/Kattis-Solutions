#include <bits/stdc++.h>
using namespace std;

int n;
double g[25][25];
double memo[21][(1<<21)];

double search(int pos, int mask) {
    if (mask == (1 << n)-1) return 1.0;
    if(pos >= n) return 0.0;
    
    double &ans = memo[pos][mask];
    if (ans > -0.5) return ans;
    
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) continue;
        ans = max(ans, g[pos][i] * search(pos+1, mask | (1 << i))); 
    }
    return ans;
}

int main() {
    for (int i = 0; i < 21; ++i)
        fill(memo[i],memo[i]+(1<<21),-1.0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for  (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            g[i][j] /= 100.0;
        }
    }

    cout << setprecision(10);
    cout << search(0,0) * 100.0 << '\n';
}
