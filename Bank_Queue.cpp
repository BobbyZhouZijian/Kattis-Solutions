#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
	int n, t;
	cin >> n >> t;

	vector< priority_queue<int> > wait(t, priority_queue<int>());


	int summ = 0;
	priority_queue<int, vector<int>, greater<int> > served;

	while (n-- > 0) {
		int money, curr_time;
		cin >> money >> curr_time;

		if (curr_time < t)	wait[curr_time].push(money);
	}

	for (int i = 0; i < t; ++i)
	{
		served.push(0);

		auto curr_q = wait[i];

		while (!curr_q.empty() && curr_q.top() > served.top()) {
			served.pop();
			served.push(curr_q.top());
			curr_q.pop();
		}
	}

	while (!served.empty()) {
		summ += served.top();
		served.pop();
	}

	cout << summ;
	return 0;
}
