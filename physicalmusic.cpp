#include <bits/stdc++.h>
using namespace std;

int T;

void solve() {
	int N;
	cin >> N;
	vector<bool> v(N, false);
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		if (i < x - 1) {
			v[x-1] = true;	
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < N; ++i) if (v[i]) cout << i + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		solve();
	}
}
