#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[200000005];

int main(int argc, char const *argv[])
{
	int n, d;
	cin >> n >> d;
	vector< vector<int> > frogs;
	for (int i = 0; i < n; ++i)
	{
		int l, w, h;
		cin >> l >> w >> h;
		frogs.push_back({w, h, l});
	}

	sort(frogs.begin(), frogs.end(), greater< vector<int> >());

	int ans = 0;

	for (int i = 0; i < n; ++i) {

		if (dp[frogs[i][0]] + frogs[i][2] > d) ans++;

		for (int j = 0; j < frogs[i][0]; ++j) {

			dp[j] = max(dp[j], dp[j + frogs[i][0]] + frogs[i][1]);
		}
	}

	cout << ans;
	return 0;
}