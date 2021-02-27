#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x,y;
} pts[105];

int n, m;
double paths[105][105];

double dist(int i1, int i2) {
    pt p1 = pts[i1], p2 = pts[i2];
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

void solve() {
    memset(paths, 0x7f, sizeof paths);
    double x, y;
    for (int i = 0 ; i < n; ++i) {
        scanf("%lf%lf", &x, &y); 
        pts[i] = {x,y};
    }

    scanf("%d", &m);
    
    for (int i = 0; i < n; ++i) paths[i][i] = 0;
    
    int i, j;
    for (int k = 0 ; k < m ; ++k) {
        scanf("%d%d", &i, &j);    
        paths[i][j] = dist(i,j);
        paths[j][i] = paths[i][j];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j)  {
                paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
            }
        }
    }

    double sum = 0;
    for (int i = 0 ;i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            sum += paths[i][j];
        }
    }

    // try all pairs possible
    double best = 0;
    int a, b;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(dist(i,j) > paths[i][j]) continue;
            double cur = 0.0;
            for (int ii = 0; ii < n; ++ii) {
                for (int jj = ii+1; jj < n; ++jj) {
                    double d1 = paths[ii][jj] - paths[ii][i] - paths[j][jj] - dist(i,j);
                    double d2 = paths[ii][jj] - paths[ii][j] - paths[i][jj] - dist(i,j);
                    cur += max(0.0, max(d1, d2));
                }
            }

            if (cur > best) {
                best= cur;
                a = i;
                b = j;
            }
        }
    }

    if (best == 0)
        printf("no addition reduces %lf\n", sum);
    else
        printf("adding %d %d reduces %lf to %lf\n", a,b,sum,sum-best);
}

int main() {
    while (scanf("%d", &n)) {
        if(n == 0) break;
        solve();
    }
}
