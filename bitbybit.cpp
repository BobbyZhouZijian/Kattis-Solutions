#include <iostream>
#include <vector>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(int argc, char const *argv[])
{
	fast();


	int n;
	while(true) {
		cin >> n;
		if(n==0) break;

		vector<int> bits(32, -1);

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			if (s == "SET") {
				int i;
				cin >> i;
				bits[31 - i] = 1;
			}

			else if (s == "CLEAR") {
				int i;
				cin >> i;
				bits[31 - i] = 0;
			}

			else if (s == "AND") {
				int i,j;
				cin >> i >> j;

				if (bits[31 - i] == 1 && bits[31 - j] == 1) bits[31 - i] = 1;
				else if (bits[31 - i] == 0 || bits[31 - j] == 0) bits[31 - i] = 0;
				else bits[31 - i] = -1;
			}

			else {
				int i, j;
				cin >> i >> j;

				if (bits[31 - i] == 1 || bits[31 - j] == 1) bits[31 - i] = 1;
				else if (bits[31 - i] == -1 || bits[31 - j] == -1) bits[31 - i] = -1;
				else bits[31 - i] = 0;
			}
		}

		for (auto i : bits) {
			if (i == 1) cout << "1";
			if (i == 0) cout << "0";
			if (i == -1) cout << "?";
		}
		cout << endl;

	}
	return 0;
}