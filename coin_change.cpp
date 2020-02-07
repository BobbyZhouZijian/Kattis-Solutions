#include <iostream>
#include <vector>
using namespace std;

int kinds_of_coins(int k) {
	if (k == 0) return 1;
	if (k == 1) return 10;
	if (k == 2) return 100;
	if (k == 3) return 1000;
}

vector< vector<int> > memo(3000, vector<int>(3000, -1));

int solve(int curr, int kind) {
	if (kind < 0 || curr < 0) return 0;

	if (curr == 0) return 1;

	else {
		if (memo[curr][kind] != -1) return memo[curr][kind];

		else {
			int ans = solve(curr, kind - 1) + solve(curr - kinds_of_coins(kind), kind);

			memo[curr][kind] = ans;

			return ans;
		}
	}
}

int main(int argc, char const *argv[])
{
	int coins, kinds;
	cin >> coins >> kinds;
	cout << solve(coins, kinds);
	return 0;
}