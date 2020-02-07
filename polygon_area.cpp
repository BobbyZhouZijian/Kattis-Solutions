#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(true) {
		cin >> n;
		if (n == 0) break;

		int xs[1001], ys[1001]; 

		for (int i = 0; i < n; i++) {
			cin >> xs[i];
			cin >> ys[i];
		}
		xs[n] = xs[0];
		ys[n] = ys[0];

		int sx = 0, sy = 0;

		for (int i = 0; i < n; i++) {
			sx += xs[i] * ys[i + 1];
			sy += ys[i] * xs[i + 1];
		}

		if (sx - sy > 0) {
			double ans = ((double)sx - sy) / 2;
			cout << "CCW ";
			cout << fixed << setprecision(1) << ans << endl;
		} else {
			double ans = ((double)sy - sx) / 2;
			cout << "CW ";
			cout << fixed << setprecision(1) << ans << endl;
		}
	}
	return 0;
}