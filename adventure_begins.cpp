#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

struct node {
	int add;
	int sum;
};

vector<node> t;

int power(int x, int n, int mod) {
	int ans = 1;
	while (n) {
		if (n & 1)
			ans = (1LL * ans * x) % mod;
		x = (1LL * x * x) % mod;
		n >>= 1;
	}
	return ans;
}

int inv(int x) {
	return power(x, mod - 2, mod);
}

void propogate(int id, int l, int r) {
	int &x = t[id].add;

	if (x != 0) {
		int m = (l + r) / 2;
		t[2 * id].add = (t[2 * id].add + x) % mod;
		t[2 * id].sum = (t[2 * id].sum + 1LL * (m - l + 1) * x) % mod;
		t[2 * id + 1].add = (t[2 * id + 1].add + x) % mod;
		t[2 * id + 1].sum = (t[2 * id + 1].sum + 1LL * (r - m) * x) % mod;
		x = 0;
	}
}


void update(int id, int l, int r, int i, int j, int x) {
	if (i > r || j < l) return;
	if (i <= l && j >= r) {
		t[id].add = (t[id].add + x) % mod;
		t[id].sum = (t[id].sum + 1LL * (r - l + 1) * x) % mod;
		return;
	}


	propogate(id, l, r);

	int m = (l + r) / 2;
	update(2 * id, l, m, i, j, x);
	update(2 * id + 1, m + 1, r, i, j, x);
	t[id].sum = (t[2 * id].sum + t[2 * id + 1].sum) % mod;
}


int query(int id, int l, int r, int i, int j) {
	if (i > r || j < l) return 0;
	if (i <= l && j >= r) return t[id].sum;

	propogate(id, l, r);

	int m = (l + r) / 2;
	return (query(2 * id, l, m, i, j) + query(2 * id + 1, m + 1, r, i, j)) % mod;
}


int main(int argc, char const *argv[])
{
	fast();

	int n, q;
	cin >> n >> q;

	t.assign(4 * n + 1, {0, 0});

	int ans = 0;
	while(q--) {
		int type;

		cin >> type;

		if (type == 1) {
			int l, r;
			cin >> l >> r;
			int x = inv(r - l + 1);
			ans = (ans + 1) % mod;
			ans = (ans + 2LL * query(1, 1, n, l, r) * x) % mod;
			update(1, 1, n, l, r, x);
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}


















