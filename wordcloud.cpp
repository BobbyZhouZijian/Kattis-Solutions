#include <bits/stdc++.h>
using namespace std;

int W, N;

void solve() {
	vector<string> ss;
	vector<int> freq;
	string s; int c;
	int maxm = 0;
	for (int i = 0; i < N; ++i) {
		cin >> s >> c;	
		ss.push_back(s);
		freq.push_back(c);
		maxm = max(maxm, c);
	}
	vector<int> pts(N);
	for (int i = 0; i < N; ++i) {
		int p= 8 + ceil(40.0 * (double)(freq[i] - 4) / (double)(maxm - 4));
		pts[i] = p;
	}
	int h = 0;
	int ans = 0;
	int w = 0;
	for (int i = 0; i < N; ++i) {
		int space = 0;
		if (h > 0) {
			space = 10;	
		}
		int sz = ss[i].length();
		int cur_w = ceil(9.0 / 16.0 * (double)sz * (double)pts[i]);
		if (cur_w + w + space > W) {
			ans += h;
			h = pts[i];
			w = cur_w;
		} else {
			h = max(h, pts[i]);
			w += cur_w + space;
		}
	}
	if (h > 0) {
		ans += h;
	}
	cout << ans;
}

int main() {
	int id = 1;
	while (1) {
		cin >> W >> N;	
		if (W == 0 && N == 0) break;
		cout << "CLOUD " << id++ << ": ";
		solve();
		cout << endl;
	}
	
	return 0;
}

