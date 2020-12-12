#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        double avex = 0.0, avey = 0.0;
        vector<pair<double, double>> dists;
        double x, y, num;
        double x0, y0;
        int deg = 0;
        string ins;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            x0 = x; y0 = y;
            double deg;
            double dx, dy;
            while (cin.peek() == ' ') {
                cin >> ins >> num;
                if (ins == "start") {
                    deg = num;
                    dx = cos((double)(deg * M_PI / 180.0));
                    dy = sin((double)(deg * M_PI / 180.0));
                } else if (ins == "walk") {
                    x += dx * num;
                    y += dy * num;
                } else if (ins == "turn") {
                    deg += num;
                    dx = cos((double)(deg * M_PI / 180.0));
                    dy = sin((double)(deg * M_PI / 180.0)); 
                }
            }
            avex += x;
            avey += y;
            dists.push_back({x, y});
        }
        avex /= n;
        avey /= n;
        double best = 0.0;
        for (auto &it : dists) {
            double cur_d = distance(it.first, it.second, avex, avey);
            if (cur_d > best) best = cur_d;
        }
        cout << avex << " " << avey << " " << best << endl;
    }
}