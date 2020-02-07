#include <iostream>
#include <vector>
using namespace std;

int t[500000] = {0};
int lazy[500000] = {0};

void push(int v) {
	t[2 * v] += lazy[v];
	lazy[2 * v] += lazy[v];

	t[2 * v + 1] = lazy[v];
	lazy[2 * v + 1] = lazy[v];

	lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r) {
	if (l == tl && r == tr) {
		t[v]++;
		lazy[v]++;
		return;
	}

	if (l > r) return;

	push(v);
	int mid = tl + (tr - tl) / 2;
	update(2 * v, tl, mid, l, min(r, mid));
	update(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get_max(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l <= tl && r >= tr) return t[v];

	push(v);
	int mid = tl + (tr - tl) / 2;
	return max(get_max(2 * v, tl, mid, l, min(r, mid)),
		get_max(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
}


int main() {
	int n, k, maxm = 0;
	cin >> n >> k;
	vector< pair<int, int> > ppl;

	while(n--) {
		int a, b;
		cin >> a >> b;
		ppl.push_back({a, b});
		maxm = max(maxm, b);
	}

	for (auto p : ppl) {
		update(1, 0, maxm, p.first, p.second);
	}

	int ans = 0;

	for (int i = 0; i <= maxm; ++i) {
		cout << get_max(1, 0, maxm, i, i) << endl;
	}	

}






