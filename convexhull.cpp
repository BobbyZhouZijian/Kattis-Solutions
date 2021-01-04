#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld prec = 0.000001;

struct point {
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    bool operator== (const point& other) const {
        return abs(other.x - x) < prec && abs(other.y - y) < prec;
    }
    bool operator!= (const point& other) const {
        return !(abs(other.x - x) < prec && abs(other.y - y) < prec);
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
};


bool cw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool cmp(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


// upper and lower hull
void convexhull(vector<point> &a) {
    sort(a.begin(), a.end(), &cmp);
    point p1 = a[0], p2 = a.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        set<point> s;
        for (int i = 0; i < n; ++i) {
            point p;
            cin >> p.x >> p.y;
            s.insert(p);
        }

        vector<point> v;
        for(auto i : s) v.push_back(i);

        if (v.size() <= 2) {
            cout << v.size() << endl;
            for (auto &i : v) {
                cout << i.x << " " << i.y << endl;
            }
            continue;
        }

        convexhull(v);
        cout << v.size() << endl;
        reverse(v.begin(), v.end());
        for (auto &i : v) {
            cout << i.x << " " << i.y << endl;
        }
    }
}