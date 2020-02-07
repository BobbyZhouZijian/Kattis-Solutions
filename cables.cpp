#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int n, m, pos[500005], cables[500005];

int main(int argc, char const *argv[])
{

	fast();

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> pos[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> cables[i];
	}

	sort(cables, cables + m);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	for (int i = n - 1; i > 0; --i) {
		pos[i] -= pos[i - 1];
		q.push({pos[i], i + 1});
	}

	int ptr = 0;

	while (!q.empty()) {
		auto p = q.top(); q.pop();

		if (p.second < n) q.push({p.first + pos[p.second], p.second + 1});

		if (p.first <= cables[ptr]) {
			ptr++;
		} else break;
	}

	if (ptr == m) cout << "yes";
	else cout << "no";
	
	return 0;
}