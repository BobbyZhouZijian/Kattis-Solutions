#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &f) {
    if(f[i] == -1) return i;
    f[i] = find(f[i], f);
    return f[i];
}

int join(int i, int j, vector<int> &f, vector<int> &s) {
    int fi = find(i, f), fj = find(j, f);
    if (fi == fj) {
        return s[fi];
    }
    if (s[fi] < s[fj]) {
        f[fi] = fj;
        s[fj] += s[fi];
        return s[fj];
    } else {
        f[fj] = fi;
        s[fi] += s[fj];
        return s[fi];
    }
}


int main() {
    int c; cin >> c;
    while (c--) {
        int n; cin >> n;
        unordered_map<string, int> m;
        int id = 0;
        vector<int> f(2*n+1, -1), s(2*n+1, 1);
        for (int i = 0; i < n; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s1) == m.end()) {
                m[s1] = id++;
            }
            if (m.find(s2) == m.end()) {
                m[s2] = id++;
            }
            int res = join(m[s1], m[s2], f, s);
            if (res > 0) cout << res << endl;
        }
    }
}