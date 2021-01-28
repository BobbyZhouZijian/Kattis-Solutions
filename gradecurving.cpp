#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,yl,yh;
    scanf("%d %d %d", &x, &yl, &yh);

    int i = 0;
    bool impossible = false;
    double t = x;
    for(;;++i) {
        if (x >= yl) break;
        t = 10.0 * sqrt(t);
        // printf("%lf %d %d\n", t, (int)ceil(t), x);
        if ((int)ceil(t) == x) {
            impossible = true;
            break;
        }
        x = ceil(t);
    }

    int j = i;
    bool inf = false;
    t = x;
    for(;!impossible;++j) {
        if (x > yh) break;
        t = 10.0 * sqrt(t);
        if ((int)ceil(t) == x) {
            inf = true;
            break;
        }
        x = ceil(t);
    }

    if (inf) {
        printf("%d inf\n", i);
    } else if (impossible || j == i) {
        printf("impossible\n");
    } else {
        printf("%d %d\n", i, j-1);
    }
}
