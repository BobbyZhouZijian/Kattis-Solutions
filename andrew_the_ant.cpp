#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(int argc, char const *argv[])
{
	fast();
	
	int d, n;
	while (scanf("%d%d", &d, &n) == 2) {

		int maxd = -1, to_r = 0;
		bool single_max = true;
		char maxdir;
		vector<int> pos;

		for (int i = 0; i < n; ++i)
		{
			int p;
			char dir;
			scanf("%d %c", &p, &dir);
			if (dir == 'R') {
				to_r++;
				
				if (d - p == maxd) single_max = false;
				else if (d - p > maxd) {
					maxd = d - p;
					single_max = true;
					maxdir = dir;
				}
			}

			else {
				if (p == maxd) single_max = false;
				else if (p > maxd) {
					maxd = p;
					single_max = true;
					maxdir = dir;
				}
			}

			pos.push_back(p);
		}

		sort(pos.begin(), pos.end());

		if (single_max) {
			//cout << maxdir; // test
			int curr = maxdir == 'R' ? pos[n - to_r] : pos[n - to_r - 1];
			printf("The last ant will fall down in %d seconds - started at %d.\n", maxd, curr);
		} else {
			int curr1 = pos[n - to_r], curr2 = pos[(n - to_r) - 1];
			if (curr1 > curr2) swap(curr1, curr2);
			printf("The last ant will fall down in %d seconds - started at %d and %d.\n", maxd, curr1, curr2);
		}
	}

	return 0;
}