#include <bits/stdc++.h>
using namespace std;

const int NINF = INT_MIN / 2;
int N, k;

int arr[205][2];
int dp[201][201][4];

int search(int row, int k, int last) {
    if (row == N) {
        return k == 0 ? 0 : NINF;
    }
    if (k < 0) return NINF;
    int &ans = dp[row][k][last];
    if (ans != -1) return ans;
    if (last == 0) {
        return ans = max(search(row+1,k-1,1)+arr[row][0],
            max(search(row+1,k-1,2)+arr[row][1], search(row+1,k,0)+arr[row][0]+arr[row][1]));
    } else if (last == 1) {
        return ans = max(search(row+1,k,0)+arr[row][0]+arr[row][1], search(row+1,k-1,1)+arr[row][0]);
    } else {
        return ans = max(search(row+1,k,0)+arr[row][0]+arr[row][1], search(row+1,k-1,2)+arr[row][1]);
    }
}

void solve() {
    memset(dp, -1, sizeof dp);  
    for (int i = 0 ; i < N; ++i) {
        int x,y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }
    cout << search(0, k, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (cin >> N >> k) {
        if (N == 0 && k == 0) break;
        solve();
    }
}
