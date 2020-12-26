#include <bits/stdc++.h>
using namespace std;


map<int, string> m;
vector<vector<int>> v;

void print(int i) {
    if (v[i].size() == 1) {
        cout << m[v[i][0]];
        return;
    }
    for (int j : v[i]) {
        if (j == i) {
            cout << m[j];
            continue;
        }
        print(j);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> s;
        m[i] = s;
        v[i].push_back(i);
    }
    
    int x = 0, y = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        x--;y--;
        v[x].push_back(y);

    }

    print(x);
}