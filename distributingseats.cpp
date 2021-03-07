#include <bits/stdc++.h>
using namespace std;

int n,r,c;

struct Person {
    int a,b; 

    bool operator<(const Person & other) const {
        return b < other.b;
    }
};

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n >> r >> c;

    vector<Person> v;

    for (int i = 0; i < n; ++i) {
        int a,b,s;
        cin >> a >> b >> s;
        v.push_back({a-s,a+s});
    }

    sort(v.begin(), v.end());

    map<int,int> m;
    for (int i = 1; i <= r; ++i) {
        m[i] = c;
    }

    int cnt = 0;
    for (auto p : v) {
        auto l = m.lower_bound(p.a);
        if (l == m.end()) continue;
        int row = l->first;
        if (row > p.b) continue;
        cnt++;
        m[row]--;
        if (m[row] == 0)
            m.erase(l);
    }

    cout << cnt << endl;
}
