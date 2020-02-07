#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ops = {"+", "-", "*", "/"};

int evaluate(vector<string> v) {
	if (v.size() == 1) return stoi(v[0]);

	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i] == "*") {
			int ans = stoi(v[i - 1]) * stoi(v[i + 1]);
			vector<string> nv;
			for (int j = 0; j < i - 1; j++) nv.push_back(v[j]);
			nv.push_back(to_string(ans));
			for(int j = i + 2; j < v.size(); j++) nv.push_back(v[j]);
			return evaluate(nv);
		}

		else if (v[i] == "/") {
			int ans = stoi(v[i - 1]) / stoi(v[i + 1]);
			vector<string> nv;
			for (int j = 0; j < i - 1; j++) nv.push_back(v[j]);
			nv.push_back(to_string(ans));
			for(int j = i + 2; j < v.size(); j++) nv.push_back(v[j]);
			return evaluate(nv);
		}
	}

	if (v[1] == "+") {
		int ans = stoi(v[0]) + stoi(v[2]);
		vector<string> nv;
		nv.push_back(to_string(ans));
		for (int i = 3; i < v.size(); i++) nv.push_back(v[i]);
		return evaluate(nv);
	} 

	else {
		int ans = stoi(v[0]) - stoi(v[2]);
		vector<string> nv;
		nv.push_back(to_string(ans));
		for (int i = 3; i < v.size(); i++) nv.push_back(v[i]);
		return evaluate(nv);
	}
}

vector<vector<string>> get_poss(int len) {
	if(len == 0) return {{"4"}};

	vector<vector<string>> sub = get_poss(len - 1);
	vector<vector<string>> curr;

	for(vector<string> &v : sub) {
		// inverse insertion
		for (int i = 0; i < 4; i ++) {
			vector<string> nv;
			nv.push_back("4");
			nv.push_back(ops[i]);
			for (auto s : v) nv.push_back(s);
			curr.push_back(nv);
		}
	}
	return curr;
}

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(int argc, char const *argv[])
{
	fast();

	vector<vector<string>> can(600);

	vector<vector<string>> parse = get_poss(3);
	for (vector<string> &st : parse) {
		can[evaluate(st) + 256] = st;
	}

	int m;
	cin >> m;

	while(m--) {
		int n;
		cin >> n;

		if (n > 256 || n < -256) {
			cout << "no solution" << endl;
		}

		else {

			vector<string> curr = can[n + 256];
			if (curr.size() > 0) {
				for (int i = 0; i < curr.size(); i++) {
					cout << curr[i] << " ";
				}
				cout << "=" << " " << n << endl;;
			}
			else {
				cout << "no solution" << endl;
			}
		}
	}
	return 0;
}