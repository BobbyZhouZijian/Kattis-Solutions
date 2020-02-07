#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int h, w, n;
	cin >> h >> w >> n;

	queue<int> bricks;

	for (int i = 0; i < n; ++i)
	{
		int curr;
		cin >> curr;

		bricks.push(curr);
	}

	int layer = h;
	int curr_w = w;
	
	while (!bricks.empty()) {

		if (bricks.front() <= curr_w) {
			curr_w -= bricks.front();
			bricks.pop();
		} else {
			cout << "NO";
			return 0;
		}

		if (curr_w == 0) {
			curr_w = w;
			layer--;
		}

		if (layer == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}