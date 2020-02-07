#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	bool first = true;
	while (cin) {
		cin >> n;
		if (n == 0) break;

		if (!first)
			cout << endl;
		else first = false;

		vector<string> orig;
		cin.ignore();

		int maxl = 0;
		for (int i = 0; i < n; ++i)
		{
			string s;
			getline(cin, s);
			int slength = s.length();
			maxl = max(maxl, slength);

			for (int k = slength; k < 101; k++) {
				s += " ";
			}

			orig.push_back(s);

		}

		for (int j = 0; j < maxl; ++j) {
			
			int i = 0;
			while (i < n) {
				if (orig[i][j] == ' ') i++;
				else break;
			}

			for (int k = n - 1; k >= i; --k) {
				if (orig[k][j] == '-') cout << '|';
				else if (orig[k][j] == '|') cout << '-';
				else cout << orig[k][j];
			}

			cout << endl;
		}
	}
	return 0;
}