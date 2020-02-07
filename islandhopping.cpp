#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<int> fathers;
int inf = 1<<29;

void initializer(int n) {
	for(int i = 0; i < n; ++i) fathers[i] = i;
}

int find(int x) {
	return fathers[x] == x ? x : find(fathers[x]);
}

void unite(int x, int y) {
	fathers[find(x)] = find(y);
}

double dist(vector<pair<double, double>>& coords, int i, int j) {
	double xi = coords[i].first, yi = coords[i].second;
	double xj = coords[j].first, yj = coords[j].second;
	return sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
}

int main() {
	int n;
	cin >> n;

	while(n--) {
		int cases; cin >> cases;
		fathers.resize(cases);
		initializer(cases);
		vector<pair<double, double>> coords;
		for(int i = 0; i < cases; ++i) {
			double x ,y;
			cin >> x >> y;
			coords.push_back({x, y});
		}

		vector<pair<double, pair<int, int>>> graph;
		for(int i = 0; i < cases; ++i) {
			for(int j = i + 1; j < cases; ++j) {
				double cur_dist = dist(coords, i, j);
				graph.push_back({cur_dist, {i, j}});
			}
		}

		//find
		
		sort(graph.begin(), graph.end());

		
		
		double ans = 0.0;
		int count = 0, index = 0;
		while(count < cases - 1 && index < graph.size()) {
			auto& cur = graph[index++];
			double cur_dist = cur.first;
			int i = cur.second.first, j = cur.second.second;
			
			if(find(i) != find(j)) {
				ans += cur_dist;
				unite(j, i);
				count++;
			}
			
		}

		cout << fixed << setprecision(5) << ans << endl;
		
	}
}