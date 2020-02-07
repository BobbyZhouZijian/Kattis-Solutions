#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

int judge(int t, ull m, ull n) {
	if (t == 1) {
		ull ans = 1;
		while (n > 0) {
			ans *= n--;
			if (ans > m) return false;
		}
		return true;
	}

	if (t == 2) {
		ull ans = 1;
		while (n-- > 0) {
			ans *= 2;
			if (ans > m) return false;
		}
		return true;
	}

	if (t == 3) {
		if (n > 100) return false;
		else if (pow(n, 4) > m) return false;
		return true;
	}

	if (t == 4) {
		if (n > 464) return false;
		else if (pow(n, 3) > m) return false;
		return true; 
	} 

	if (t == 5) {
		if (n > 10000) return false;
		else if (pow(n, 2) > m) return false;
		return true;
	}

	if (t == 6) {
		if (log2(n) * n > m) return false; 
		return true;
	}

	if (t == 7) {
		return n <= m;
	}
}

int main(int argc, char const *argv[])
{
	ull m, n;
	int  t;
	cin >> m >> n >> t;

	if (judge(t, m, n)) cout << "AC";
	else cout << "TLE";
	return 0;
}