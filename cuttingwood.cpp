#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}


int main() {

	fast();

	int n;
	cin >> n;

	while(n--) {
		int m;
		cin >> m;

		vector<double> c(m);
		for(int i = 0; i < m; ++i) {
			int k;
			double cur; 
			cin >> k;
			for(int j = 0; j < k; ++j) {
				cin >> cur;
				c[i] += cur;
			}
		}

		sort(c.begin(), c.end());
		double sum = 0, accum = 0;
		for(auto v : c) {
			accum += v;
			sum += accum;
		}

		double out = sum / (double)m;

		cout << setprecision(10) << out << endl;
	}
}