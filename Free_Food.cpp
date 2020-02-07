#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, c[1000] = {0};
	int cnt = 0;
	cin >> n;	

	while(n--) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; ++i) {
			if (c[i] == 0) {
				c[i] = 1;
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}