#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {

    int inf = 1 << 29;
    int D;
    cin >> D;
    int dp[103][203], d[103], p[103];
    d[0] = 0;
    p[0] = 0;
    
    string s;
    getline(cin, s);
    int n = 1;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        stringstream ss;
        ss << s;
        int x, y;
        ss >> x >> y;
        d[n] = x;
        p[n] = y;
        n++;

    }

    d[n] = D;
    p[n] = inf;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 201; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][100] = 0;

    for (int i = 1; i <= n; i++) {
        int dist = d[i] - d[i - 1];
        
        for (int j = dist; j < 201; j++) {
            dp[i][j - dist] = min(dp[i][j - dist], dp[i - 1][j]);
        }

        for (int j = 1; j < 201; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + p[i]);
        }
    }

    int ans = inf;

    for (int j = 100; j < 201; j++) {
        ans = min(ans, dp[n][j]);
    }

    if (ans == inf)
        cout << "Impossible";
    else
        cout << ans;
    
}