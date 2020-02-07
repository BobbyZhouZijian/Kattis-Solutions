#include <iostream>
#include <vector>

using namespace std;

/*
deg_of_freedom(vector< vector<int> > &grid, int i, int j) {
	if (i == 0 && j == 0) return 2;
	if (i > 0 && j > 0) return 0;
	return 1;
}
*/

int main() {

	int n;
	cin >> n;

	while(n--) {
		int r, c;
		cin >> r >> c;

		int ans = 1;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					ans *= 18;
				}

				else if (i > 0 && j > 0) {
					continue;
				}

				else {
					ans *= 6;
				}
			}
		}

		cout << ans << endl;
	}
}