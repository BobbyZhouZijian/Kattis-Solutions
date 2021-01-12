#include <bits/stdc++.h>
using namespace std;

int T;

void solve() {
    int N; cin >> N;
    vector<int> v(N);
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        v[i] = x-1;
    }
    vector<int> high(N);
    for (int i=N-1;i>=0;--i){
        if (i==N-1) {
            high[N-1] = v[N-1];
            continue;
        }
        high[i] = min(v[i], high[i+1]);
    }

    for (int i = 0; i < N-1; ++i) {
        if (v[i] > high[i+1]) {
            cnt++;
            res.push_back(v[i]);
        }
    }
    sort(res.begin(), res.end());
    cout << cnt << endl;
    for (int i : res) cout << i + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		solve();
	}
}
