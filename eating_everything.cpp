#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}


double dfs(map<int, vector<int>> &v, vector<double> &dp, vector<double> &value, int curr) {
	if (dp[curr] != -1) return dp[curr];
	double cur_val = value[curr], maxm = value[curr];

	for (int next : v[curr]) {
		double next_max = dfs(v, dp, value, next);
		maxm = max(maxm, max(next_max, cur_val + next_max / 2));
	}

	dp[curr] = maxm;
	return maxm;
}

int main(int argc, char const *argv[])
{
	//add from the right to the left
	//use dp

	fast();

	int n, m;
	cin >> n >> m;

	vector<double> dp(n, -1);
	map<int, vector<int>> v; 
	vector<double> value(n);
	
	for (int i = 0; i < n; ++i) {
		double val;
		cin >> val;

		value[i] = val;
	}

	for (int i = 0; i < m; ++i) {

		int u1, u2;
		cin >> u1 >> u2;
		v[u1].push_back(u2);
	}

	cout << setprecision(7) << dfs(v, dp, value, 0);
	return 0;
}