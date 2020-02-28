#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define N 505
using namespace std;

int n, fathers[N];

struct point {
    int x, y;
};

struct edge {
    int x, y;
    double dist;
};

int find(int x) {
    return fathers[x] == x ? x : find(fathers[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) fathers[fx] = y;
}

void initialize(int p) {
    for(int i = 0; i <= p; ++i) fathers[i] = i;
}

void fast() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

bool cmp(edge& x, edge& y) {
    return x.dist < y.dist;
}

int main() {
    fast();
    cin >> n;
    while(n--) {
        int s, p;
        cin >> s >> p;
        initialize(p);
        vector<point> v;
        
        for(int i = 0; i < p; ++i) {
            point p;
            cin >> p.x >> p.y;
            v.push_back(p);
        }

        vector<edge> es;

        for(int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                edge e;
                e.dist = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
                e.x = i; e.y = j;
                es.push_back(e);
            }
        }

        sort(es.begin(), es.end(), cmp);

        vector<double> kept;

        for(auto& e : es) {
            if(find(e.x) != find(e.y)) {
                kept.push_back(e.dist);
                unite(e.x, e.y);
            }
        }

        for(int i = 1; i < s; ++i) {
            kept.pop_back();
        }

        cout << fixed << setprecision(2) << kept.back() << endl;
    }
}