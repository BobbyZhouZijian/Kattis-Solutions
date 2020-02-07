#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int	n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		double l, num;
		cin >> l >> num;

		double half = (double)l / 2;
		double min_time = 0, max_time = 0;

		for (int i = 0; i < num; ++i)
		{
			/* code */
			double pos;
			cin >> pos;

			if (pos <= half) {

				if (pos > min_time) min_time = pos;
				if (l - pos > max_time) max_time = l - pos;

			} else {

				if (l - pos > min_time) min_time = l - pos;
				if (pos > max_time) max_time = pos;
			}
		}

		cout << min_time << " " << max_time << endl;

	}
	return 0;
}