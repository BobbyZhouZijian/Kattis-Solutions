#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}


int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}

bool line(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3) {
	vector<pair<int, int>> ln = {p1, p2, p3};
	sort(ln.begin(), ln.end(), comp);

	int diffx1 = ln[1].first - ln[0].first;
	int diffy1 = ln[1].second - ln[0].second;
	int diffx2 = ln[2].first - ln[1].first;
	int diffy2 = ln[2].second - ln[1].second;

	if (diffx1 == 0 || diffx2 == 0) return diffx1 == 0 && diffx2 == 0;
	if (diffy1 == 0 || diffy2 == 0) return diffy1 == 0 && diffy2 == 0;

	int gcd1 = gcd(diffx1, diffy1);
	int gcd2 = gcd(diffx2, diffy2);


	diffx1 /= gcd1;
	diffy1 /= gcd1;
	diffx2 /= gcd2;
	diffy2 /= gcd2;

	return diffx1 == diffx2 && diffy1 == diffy2;
}

int main(int argc, char const *argv[])
{
	fast();
	
	int n;
	cin >> n;
	vector<pair<int, int>> pts;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {
			if (s[j] != '.') pts.push_back(make_pair(i, j));
		}
	}

	n = pts.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++) {

				if(line(pts[i], pts[j], pts[k])) cnt++;
			}
		}
	}

	cout << cnt;
}