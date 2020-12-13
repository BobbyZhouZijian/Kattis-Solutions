#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> w;

int find (int i) {
    if (v[i] == -1) return i;
    v[i] = find(v[i]);
    return v[i];
}

void join(int i, int j) {
    int fi = find(i), fj = find(j);
    if (fi != fj) {
        if (w[fi] < w[fj]) {
            v[fi] = fj;
            w[fj] += w[fi];
        } else {
            v[fj] = fi;
            w[fi] += w[fj];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n, -1);
    w.resize(n, 1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        join(a, b);
    }
    int root = find(0);
    bool con = true;
    for (int i = 0; i < n; ++i) {
        if (find(i) != root) {
            cout << i + 1 << endl;
            con = false;
        }
    }
    if (con) cout << "Connected";
}