#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX / 2;
int n;
int arr[1005];
int dp[1005][2500];
int most;

int search(int pos, int w) {
    if (pos == n || w > most) {
        return w;
    }
    int &ans = dp[pos][w];
    if (ans != -1) return ans;

    int res1 = search(pos+1, w+arr[pos]);
    int res2 = search(pos+1, w);
    if (abs(res1-1000) == abs(res2-1000))
        return ans = max(res1, res2);
    else if (abs(res1-1000) < abs(res2-1000))
        return ans = res1;
    else 
        return ans = res2;
}

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    memset(dp, -1, sizeof dp);
    most = 1000 + abs(1000 - arr[0]);
    printf("%d\n",search(0, 0));
}