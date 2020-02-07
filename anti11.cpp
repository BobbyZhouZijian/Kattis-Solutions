#include <iostream>
using namespace std;

typedef long long ll;

ll fibo[10005], mod = 1000000007;

void init_fibo() {
	fibo[0] = 1;
	fibo[1] = 2;
	for (int i = 2; i < 10005; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
	}
}

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(int argc, char const *argv[])
{
	fast();
	init_fibo();

	int t;
	cin >> t;

	while(t--) {
		int num;
		cin >> num;
		cout << fibo[num] << endl;
	}
	return 0;
}