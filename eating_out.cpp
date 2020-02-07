#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, a, b, c;
	cin >> m >> a >> b >> c;
	int order[3] = {a, b, c};
	sort(order, order + 3);

	int left = order[2] + order[1] - m;
	if (left <= 0) {
		cout << "possible";
	} else {
		if (left + order[0] > m) {
			cout << "impossible";
		}

		else cout << "possible";
	}
	return 0;
}