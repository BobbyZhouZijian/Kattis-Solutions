#include <iostream>
#include <map>
using namespace std;

int dp(map<pair<int, int>, int> &memo, int m, int n, int power) {
	if (n == 0) return 1;
	if (m == 0) return 0;

	pair<int, int> p = {n, m};
	if (memo.count(p)) {
		return memo[p];
	}

	int sum = 0;
	if (n >= m) {
		sum += dp(memo, m, n - m, power);
	}
	if (m > 1) {
		sum += dp(memo, m / power, n, power);
	}

	memo[p] = sum;
	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cases; cin >> cases;
	int id, power, n;
	while(cases--) {
		cin >> id >> power >> n;
		int m = power;
		while (m <= n) m *= power;

		map<pair<int, int>, int> memo;
		cout << id << " " << dp(memo, m, n, power) << endl;
	}
}