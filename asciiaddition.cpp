#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	vector<string> hash(100, "");
	int len;
	string s;

	while(cin) {
		cin >> s;
		if (s == "") break;
		len = s.length() / 5;

		for (int i = 0; i < len; ++i) {
			for (int j = 5 * i; j < 5 * i + 5; ++ j) {
				hash[i] += s[j];
			}
		}
	}

	map<string, int> m;
	m["xxxxxx...xx...xx...xx...xx...xxxxxx"] = 0;
	m["....x....x....x....x....x....x....x"] = 1;
	m["xxxxx....x....xxxxxxx....x....xxxxx"] = 2;
	m["xxxxx....x....xxxxxx....x....xxxxxx"] = 3;
	m["x...xx...xx...xxxxxx....x....x....x"] = 4;
	m["xxxxxx....x....xxxxx....x....xxxxxx"] = 5;
	m["xxxxxx....x....xxxxxx...xx...xxxxxx"] = 6;
	m["xxxxx....x....x....x....x....x....x"] = 7;
	m["xxxxxx...xx...xxxxxxx...xx...xxxxxx"] = 8;
	m["xxxxxx...xx...xxxxxx....x....xxxxxx"] = 9;

	m[".......x....x..xxxxx..x....x......."] = 10;


	int a = 0, b = 0;
	int i = 0;
	while (i < len) {
		if (m[hash[i]] == 10) break;
		else {
			a = a * 10 + m[hash[i]];
		}
	}

	i++;

	while(i < len) {
		b = b * 10 + m[hash[i]];
	}

	int ans = a + b;

	cout << ans;
}
