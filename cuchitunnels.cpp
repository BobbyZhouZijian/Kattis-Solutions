#include <iostream>
using namespace std;

int deg[1005] = {0};

int main() {
	int n;
	bool ok = true;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> deg[i];
	}

	int i = n - 1, left = 0;
	while (ok && i >= 0) {
		
		if (left < deg[i] - 1) {
			ok = false;
		}
		left += 2 - deg[i];
		i--;
	}

	cout << (ok && left == 2 ? "YES" : "NO");

}