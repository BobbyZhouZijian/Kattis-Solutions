#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> f;

void update(int x) {
    while (x <= N) {
        f[x]++;
        x += (x & (-x));
    }
}

int get(int i) {
    int ans =0 ;
    while (i > 0) {
        ans += f[i];
        i -= (i & (-i));
    }
    return ans;
}

void solve() {
    f.resize(1+N, 0);
    vector<int> arr(N+1);
    for (int i = 1; i <= N; ++i) {
        int x ; cin >> x;
        arr[x] = i;
    }
    for (int i = 1, j = N; i <= j; ++i, --j) {
        int pos1 = arr[i], pos2 = arr[j];
        int rm1 = get(pos1);
        cout << pos1 - 1 - rm1 << endl;
        update(pos1);
        if (i == j) break;
        int rm2 = get(N) - get(pos2);
        cout << N - pos2 - rm2 << endl;
        update(pos2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N;
    solve();
}