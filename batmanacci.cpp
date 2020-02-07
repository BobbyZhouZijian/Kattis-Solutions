#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull fib[89];

string find(int n, ull k) {
	if (n == 1) return "N";
	if (n == 2) return "A";

	ull l = fib[n - 2];
	if (l >= k)
		return find(n - 2, k);
	else  return find(n - 1, k - l);
}

int main(int argc, char const *argv[])
{
	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i < 89; ++i) fib[i] = fib[i - 1] + fib[i - 2];

	int n; ull k;
	cin >> n >> k;

	n = n > 89 ? 89 : n;

	cout << find(n, k);
	return 0;
}