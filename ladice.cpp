#include<bits/stdc++.h>
using namespace std;

vector<int> f, s;

int find(int x) {
    if (f[x] == -1) return x;
    f[x] = find(f[x]);
    return f[x];
}

bool join(int i, int j) {
    int fi = find(i), fj = find(j);
    if (fi==fj) {
        if (s[fi] == 0) return false;
        s[fi]--;
    } else if (s[fi]<s[fj]) {
        f[fi] = fj;
        s[fj] += s[fi];
        if (s[fj] == 0) return false;
        s[fj]--;
    } else {
        f[fj] = fi;
        s[fi] += s[fj];
        if (s[fi] == 0) return false;
        s[fi]--;
    }
    return true;
}

int main() {
    int n, l;
    cin >> n >> l;
    f.resize(l+1,-1);
    s.resize(l+1,1);
    for (int i = 0; i < n; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        if (join(n1, n2)) cout << "LADICA" << endl;
        else cout << "SMECE" << endl;
    }
}