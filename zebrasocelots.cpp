#include <iostream>
using namespace std;
typedef unsigned long long ull;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	fast();
	int n; cin >> n;
	ull sum = 0ull;
	ull step = 1ull  << (n - 1);
	while(n--) {
		string cur; cin >> cur;
		if(cur == "O") sum += step;
		step >>= 1ull;
	}

	cout << sum;
}