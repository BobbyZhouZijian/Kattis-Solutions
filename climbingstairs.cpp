#include <bits/stdc++.h>
using namespace std;

int n,r,k;

void solve() {
	if (k >= r) {
		if (k * 2 - r >= n) {
			cout << 2 * k << endl;
		} else {
			cout << n+r + ((n-2*k+r) % 2 == 1) << endl;
		}
	} else {
		if (r >= n) {
			cout << 2 * r << endl;
		} else {
			cout << n + r + ((n - r) % 2 == 1) << endl;
		}
	}
}

int main() {
	cin >> n >> r>> k;
	solve();	
}
