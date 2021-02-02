#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int inf = INT_MAX/2;

int N, fee[MAXN], dp[MAXN][MAXN];

int search(int pos, int step) {
    if (pos < 1 || pos > N) return inf;
    if (pos == N) return fee[N];
    int &ans = dp[pos][step];
    if (ans != -1) return ans;
    return ans = fee[pos] + min(search(pos-step, step), search(pos+step+1,step+1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> N;
    for (int i = 1 ; i <= N; ++i) {
        cin >> fee[i];
    }

    cout << search(2,1) << endl;
}
