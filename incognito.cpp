#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	while (n-- > 0) {
		int cat;
		cin >> cat;

		std::map<string, int> m;

		for (int i = 0; i < cat; ++i)
		{
			string wear, category;
			cin >> wear >> category;

			m[category]++;
		}

		int ans = 1;

		for (auto p : m) {
			ans *= (p.second + 1);
		}

		cout << ans - 1 << endl;
	}
	return 0;
}