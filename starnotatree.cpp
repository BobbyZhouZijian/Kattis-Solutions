#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
pair<double, double> pts[MAXN];
int n;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

double calc(double x, double y) {
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        ans += hypot(pts[i].first - x, pts[i].second - y); 
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    double x = 0.0, y = 0.0;
    double best = calc(x,y);
    double EPS = 10000.0;
    for (; EPS > 1e-12; EPS /= 2.0) {
        for (int k = 0; k < 4; ++k) {
            double nx = x + EPS * dx[k];
            double ny = y + EPS * dy[k];
            double cur = calc(nx, ny);
            if (cur < best) {
                best = cur;
                x = nx;
                y = ny;
            }
        }
    }

    cout << setprecision(12) << best << endl;
}
