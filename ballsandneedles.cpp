#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z;
    bool operator == (const Point& p) const {
        return this->x==p.x && this->y==p.y && this->z==p.z;
    }

    bool operator < (const Point& p) const {
        return 1000000*this->x + 1000*this->y + this->z < 1000000*p.x + 1000*p.y + p.z;
    }

    // bebug
    void print() {
        cout << this->x << " " << this->y << " " << this->z << endl;
    }
};

map<Point, set<Point>> m;
map<Point, set<Point>> projection;

bool cycle(Point p, Point parent, map<Point, set<Point>> &mp, map<Point, int> &v) {
    v[p] = 1;
    for (auto next_p : mp[p]) {
        if (!v[next_p]) {
            if (cycle(next_p, p, mp, v)) return true;
        } else if (!(next_p == parent)) {
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        m[{x1, y1, z1}].insert({x2, y2, z2});
        m[{x2, y2, z2}].insert({x1, y1, z1});
        if (x1 == x2 && y1 == y2) continue;
        projection[{x1, y1, 0}].insert({x2, y2, 0});
        projection[{x2, y2, 0}].insert({x1, y1, 0});
    }
    bool is_closed = false;
    map<Point, int> vis;
    for (auto &it : m) {
        Point p = it.first;
        if (!vis[p] && cycle(p, {-1,-1,-1}, m, vis)) {
            cout << "True closed chains" << endl;
            is_closed = true;
            break;
        }
    }
    if (!is_closed) {
        cout << "No true closed chains" << endl;
    }
    is_closed = false;
    map<Point, int> vis1;
    for (auto &it : projection) {
        Point p = it.first;
        if (!vis1[p] && cycle(p, {-1,-1,-1}, projection, vis1)) {
            cout << "Floor closed chains" << endl;
            is_closed = true;
            break;
        }
    }
    if (!is_closed) {
        cout << "No floor closed chains" << endl;
    }
}