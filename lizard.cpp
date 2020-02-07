#include <iostream>
#include <vector>
using namespace std;

int find_maximum_length(vector< vector<int> > &m) {
    int r = m.size(), c = m[0].size();

    vector< vector<int> > dp(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!i) {
                dp[i][j] = m[i][j];
            } else {
                if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + m[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + m[i][j]);
                if (j + 1 < c) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + m[i][j]);
            }
        }
    }

    int maxm = 0;

    for (auto i : dp[r - 1]) maxm = max(maxm, i);

    return maxm;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector< vector<int> > m(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    cout << find_maximum_length(m);
}