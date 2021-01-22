#include <stdio.h>
#include <cstring>
using namespace std;


int M, N;
int x, y;

int holes[13];

int ans = 0;
int OK;

inline void dfs(int x, int rw, int ld, int rd) {
    if (rw == OK) {
        ans++;
        return;
    }
    int pos = OK & (~(holes[x] | rw | ld | rd));
    while (pos) {
        int p = pos & (-pos);
        pos -= p;
        dfs(x+1, rw | p, (ld|p)<<1, (rd|p)>>1); 
    }
}

inline void solve() {
    ans = 0;
    OK = (1 << N) - 1;
    memset(holes, 0, N*sizeof(holes[0]));
    for (int i = 0; i < M; ++i)  {
        scanf("%d %d", &x, &y);
        holes[x] |= (1 << y);
    }
    dfs(0, 0, 0, 0);
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0) break;
        solve();
    }
    
    return 0;
}
