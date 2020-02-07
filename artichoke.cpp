#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double p, a, b, c, d, n;

	cin >> p >> a >> b >> c >> d >> n;

	double max_diff = 0.0;

	double max_p = p * (sin(a + b) + cos(c + d) + 2);

	for (int i = 2; i <= n; i ++) {
		double cur_p = p * (sin(a * i + b) + cos(c * i + d) + 2);
		if (cur_p > max_p) max_p = cur_p;
		else if (max_p - cur_p > max_diff) max_diff = max_p - cur_p;
	}

	cout << setprecision(10) << max_diff;
}