#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

void getIndex(vector<vector<int>>& v, int i, int j, vector<pair<int, int>>& objects) {
    if (v[i][j] == 0) {
        return;
    }
    if (v[i - 1][j] == v[i][j]) {
        getIndex(v, i - 1, j, objects);
    } else {
        getIndex(v, i - 1, j - objects[i].second, objects);
        res.push_back(i - 1);
    }
}

int main() {
    int cap, n;

    while (cin >> cap && cin >> n) {
        vector<vector<int>> v(n + 1, vector<int>(cap + 1, 0));
        vector<pair<int, int>> objects;
        objects.push_back({0, 0});
        for (int i = 0; i < n; ++i) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            objects.push_back(p);
        }

        for (int i = 1; i < objects.size(); ++i) {
            pair<int, int>& p = objects[i];
            for (int j = 0; j <= cap; ++j) {
                if (j < p.second) {
                    v[i][j] = v[i - 1][j];
                    continue;
                }
                v[i][j] = max(v[i - 1][j - p.second] + p.first, v[i - 1][j]);
            }
        }

        getIndex(v, n, cap, objects);
        cout << res.size() << endl;
        for (int& t : res) cout << t << " ";
        cout << endl;
        res.clear();
    }
}
