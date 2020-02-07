#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, n;
	cin >> a >> n;

	if (n == 0 || n * n < 4 * M_PI * a) {
		cout << "Need more materials!";
	}

	else {
		cout << "Diablo is happy!";
	}
}