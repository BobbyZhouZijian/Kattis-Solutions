#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n;
string a[11],b[11];
int all;
string cur;
string va, vb;
int tc;

void recurse(int mask) {
    int la = va.size(), lb = vb.size();
    int lc = cur.size();
    if (lc != 0 && (la > lc || lb > lc)) {
        return;
    }
    if (la == lb && la > 0) {
        if (lc == 0) {
            cur = va;
        } else if (la <= lc) {
            if (la < lc) {
                cur = va;
            } else if (va < cur) {
                cur = va;
            }
        }
    }
    int idx = min(la, lb);
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            continue;
        }
        int max_idx = min(la + a[i].size(), lb + b[i].size());
        bool valid = true;
        for (int j = idx; j < max_idx; j++) {
            char ac;
            if (j >= la) {
                ac = a[i][j - la];
            } else {
                ac = va[j];
            }
            char bc;
            if (j >= lb) {
                bc = b[i][j - lb];
            } else {
                bc = vb[j];
            }
            if (ac != bc) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (char c : a[i]) {
                va.push_back(c);
            }
            for (char c : b[i]) {
                vb.push_back(c);
            }   
            recurse(mask | (1 << i));
            int ai_size = a[i].size();
            int bi_size = b[i].size();
            while (ai_size--) {
                va.pop_back();
            }
            while (bi_size--) {
                vb.pop_back();
            }
        }
    }
}

void solve() {
    cur = "";
    for (int i = 0; i < n; ++i) {
         cin >> a[i] >> b[i];
    }

    va = "";
    vb = "";
    recurse(0);
    cout << "Case " << tc << ": ";
    if (cur.size() == 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << cur;
    }
    cout << "\n";
}

int main() {
    fast();
    tc = 1;
    while (cin >> n) {
        solve();
        tc++;
    }

    return 0;
}

