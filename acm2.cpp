#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, first;
	cin >> n >> k;

	vector<int> arr(n - 1);
	for (int i = 0; i < k; ++i) cin >> arr[i];
	cin >> first;
	for (int j = k; j < n - 1; ++j) cin >> arr[j];

	int penalty = first;
	int rest_time = 300 - first;
	int solve = 1;
	if (rest_time < 0) cout << "0 0";
	else {
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > rest_time ) break;
			rest_time -= arr[i];
			penalty += 300 - rest_time;
			solve++;
		}

		cout << solve << " " << penalty;
	}
}