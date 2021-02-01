#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> greedy, dp;
vector<int> v;

int main() {
    cin >> n;

    for (int i = 0;i < n; ++i) {
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int maxm = v[n-1] + v[n-2];
    bool can =true;
    int ptr = 0;
    dp.assign(maxm+1, INT_MAX/2);
    greedy.assign(maxm+1, INT_MAX/2);
    dp[0] = 0;
    greedy[0] = 0;
    for (int i = 1; i < maxm; ++i) {
        while (ptr < n-1 && v[ptr+1] <= i)
            ptr++;

        greedy[i] = greedy[i-v[ptr]] + 1;
        
        for (int j = 0; j < n && v[j] <= i; ++j) {
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }

        if (greedy[i] != dp[i]) {
            can = false;
            break;
        }
    }

    if (can) cout << "canonical\n";
    else cout << "non-canonical\n";
}
