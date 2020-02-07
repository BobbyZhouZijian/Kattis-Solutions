#include <iostream>
#include <vector>
#include <map>
using namespace std;

int k, n, m;

struct flight {
	int n1;
	int n2;
	int cap;
};



int main() {

	cin >> k >> n >> m;

	vector<int> people(k);
	map<int, vector<flight> > flights;
	// day, n2, cap
	map<int, vector< pair<int, int> > > adds;

	//read files
	for(int i = 0; i < m; ++i) {
		int d;
		flight f;
		cin >> f.n1 >> f.n2 >> d >> f.cap;
		f.n1--; f.n2--; d--;
		flights[d].push_back(f);
	}

	for(int i = 0; i < n * k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adds[b].push_back({a, c});
	}


	//cal by days
	for(int i = 0; i < n; ++i) {
		//add arrivals to people
		for(auto p : adds[i]) {
			people[p.first] += p.second;
		}

		bool ok = true;
		//schedule departure
		for(auto f : flights[i]) {
			people[f.n1] -= f.cap;

			if(people[f.n1] < 0) {
				ok = false;
				break;
			}
		}

		if(!ok) {
			cout << "suboptimal";
			return 0;
		}

		else {
			for(auto f : flights[i]) people[f.n2] += f.cap;
		}
	}

	cout << "optimal";
}

