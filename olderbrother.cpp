#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<bool> build_prime(int n) {
	n += 10;
	vector<bool> res(n, true);
	for (int i = 0; i < n / 2; ++i) {
		if (i == 0 || i == 1) res[i] = false;
		if (res[i]) {
			int j = 2;
			while (j * i <= n) res[(j++) * i] = false;
		}
	}
	return res;
}

bool is_prime(vector<bool> primes, int sq, int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sq; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	int sq = ceil(sqrt(n));

	vector<bool> primes = build_prime(sq);

	if (is_prime(primes, sq, n)) {
		cout << "yes";
		return 0;
	}

	//for (int i = 0; i < primes.size(); ++i) if (primes[i]) cout << i << " ";
	//cout << "\n";

	while (sq > 1) {
		if (n % sq == 0 && primes[sq]) {
			//cout << "sq: " << sq << endl;
			int cur = n;
			while (cur > 1) {
				if (cur % sq == 0) {
					cur /= sq;
				} else {
					break;
				}
			}
			if (cur == 1) {
				cout << "yes";
				return 0;
			}
		}
		sq--;
	}
	cout << "no";
}