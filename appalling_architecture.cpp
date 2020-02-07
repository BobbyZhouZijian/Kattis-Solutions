#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;
	cin.ignore();

	double ctl = -1, ctr = -1;
	double M = 0;
	int cnt = 0;

	string s;

	for (int i = 0; i < r; ++i)
	{
		getline(cin, s);
		
		if (i == r - 1) {
			for (int j = 0; j < c; ++j)
			{
				if (s[j] == '.') continue;

				if (ctl == -1) {
					ctl = j + 0.5;
					ctr = j + 0.5;
				}
				else ctr = j + 0.5;
			}
		}

		for (int j = 0; j < c; j++) {
			if (s[j] == '.') continue;

			M += j + 0.5;
			cnt++;
		}

	}

	M = M / cnt;

	//test
	//cout << M << " " << cnt << " " << ctl << ctr;

	if (M < ctl - 0.5) cout << "left";
	else if (M > ctr + 0.5) cout << "right";
	else cout << "balanced";

	return 0;
}