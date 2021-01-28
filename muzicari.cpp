#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<int> b;

int dp[505][5005];
bool seen[505];

int search(int x, int t) {
    int &ans = dp[x][t];
    if (ans != -1) return ans;
    if (x == n || t == 0) return 0;
    if (b[x] > t) return ans = search(x+1, t);
    return ans = max(search(x+1, t), b[x] + search(x+1, t-b[x]));
}

void add_ppl(int x, int t) {
    if (x == n || t < 0) return;
    if (search(x+1, t - b[x]) + b[x] == dp[x][t]) {
        seen[x] = 1;
        add_ppl(x+1, t-b[x]);
    } else {
        add_ppl(x+1, t);
    }
}

int main() {
    cin >> t >> n;
    memset(dp, -1, sizeof dp);
    memset(seen, 0, sizeof seen);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.push_back(x);
    }
    
    search(0, t);
    add_ppl(0, t);
    vector<int> a(n);
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i]) {
            a[i] = t1;
            t1 += b[i];
        } else {
            a[i] = t2;
            t2 += b[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
