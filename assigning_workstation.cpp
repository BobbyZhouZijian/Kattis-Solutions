#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int	main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int> > stations;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > researchers;

	for (int i = 0; i < n; ++i)
	{
		int arrive, stay;
		cin >> arrive >> stay;
		researchers.push(make_pair(arrive, stay));
	}

	int cnt = 0;

	while (!researchers.empty()) {

		auto curr = researchers.top();
		researchers.pop();

		if (stations.empty()) {
			cnt ++;
			stations.push(curr.first + curr.second);
		}

		else {
			bool found = false;
			while(!stations.empty()) {
				int available = stations.top();
				if (available + m < curr.first) {
					stations.pop();
					continue;
				}
				else if (available > curr.first) {
					cnt++;
					stations.push(curr.first + curr.second);
					found = true;
					break;
				}

				else {
					stations.pop();
					found = true;
					stations.push(curr.first + curr.second);
					break;
				}
			}

			if (!found) {
				cnt++;
				stations.push(curr.first + curr.second);
			}
		}
	}

	cout << n - cnt;
	return 0;
}