#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	while (cin) {
		int b;
		string p, m;

		cin >> b;
		if (!b) break;
		cin >> p >> m;

		ll m10 = 0;
		for (int i = 0; i < m.length(); ++i)
		{
			m10 *= b;
			m10 += m[i] - '0';
		}

		if (m10 == 0)
		{
			cout << p << endl;
			continue;
		}

		ll expmod = 1, ans = 0;
		for (int i = p.length() - 1; i >= 0; --i)
		{
			int curr = p[i] - '0';
			ans = (ans + curr * expmod) % m10;
			expmod = (expmod * b) % m10;
		}

		if (ans == 0)
		{
			cout << "0" << endl;
			continue;
		}
		//test
		//cout << m10 << " " << ans << endl;

		string res = "";
		while (ans > 0)
		{
			int left = ans % b;
			res += char('0' + left);
			ans = (ans - left) / b; 
		}

		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	return 0;
}