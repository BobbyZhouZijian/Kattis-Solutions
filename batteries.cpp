#include <iostream>
#include <vector>
using namespace std;

int n;
//dp array
vector<vector<int>> dp;

int main() {
	while(cin >> n) {
		if(n == 0) break;
		n--;
		dp.resize(n + 1, vector<int>(3));

		//if only one battery
		for(int i = 1; i <= n; ++i) {
			dp[i][1] = i;
		}

		for(int i = 1; i <= n; ++i) {

			int min = 1<<30;
			int maxm;

			for(int k = 1; k <= i; ++k) {
				maxm = 1 + max(dp[k - 1][1], dp[i - k][2]);

				if(min > maxm) min = maxm;
			}

			dp[i][2] = min;
		}

		cout << dp[n][2] << endl;
	}
}