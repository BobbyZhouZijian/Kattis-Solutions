#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int	main(int argc, char const *argv[])
{
	
	double x, y;
	int n;

	cin >> x >> y >> n;

	std::vector<double> dis;

	while(n-- > 0) {
		double a, b, d;
		cin >>a >> b >> d;

		double curr_dis = sqrt((a - x) * (a - x) + (b - y) * (b - y));
		dis.push_back(curr_dis - d);
	}

	sort(dis.begin(), dis.end());

	double ans = dis[0];
	int cnt = 0;

	for (int i = 1; i < dis.size(); ++i)
	{

		cnt++;
		if (dis[i] != dis[i - 1]) {
			ans = dis[i];
		}

		if (cnt == 2) break;
	}

	int res = floor(ans);

	cout << max(0, res);
	return 0;
}