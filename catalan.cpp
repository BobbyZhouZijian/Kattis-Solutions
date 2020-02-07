#include <iostream>
using namespace std;

int mod = 1e9 + 7;

int pow(int x, int y, int mod) {
	int ans = 1;
	while(y) {
		if(y%2) ans = (1LL * ans * x) % mod;
		y >>= 1;
		x = (1LL * x * x) % mod;
	}
	return ans;
}

int inv(int x, int mod) {
	return pow(x, mod - 2, mod);
}

int ncr(int n, int r) {
	int ans = 1;
	for (int i = n - r + 1; i <= n; ++i) {
		ans = (1LL * ans * i) % mod;
	}

	for (int i = 1; i <= r; ++i) {
		ans = (1LL * inv(i, mod) * ans) % mod;
	}
	return ans;
}

int catalan(int n) {
	return (1LL * inv(n + 1, mod) * ncr(2 * n, n)) % mod;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << catalan(n);
	return 0;
}

