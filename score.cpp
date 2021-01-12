#include <bits/stdc++.h>
using namespace std;

int N, la=0,lh=0;
int pa=0, ph=0;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	char s, jk;
	int ltt=0,lss=0;
	int pt,tt,ss;
	for (int i = 0; i < N; ++i) {
		cin >> s >> pt >> tt >> jk >> ss;
		bool h_lead = (ph > pa);
		bool a_lead = (pa > ph);
		if (s == 'H') {
			ph += pt;
			int excess = (tt-ltt)*60 + (ss-lss);
			if (h_lead) {
				lh += excess;	
			} else if (a_lead) {
				la += excess;
			}
		} else {
			pa += pt;
			int excess = (tt-ltt)*60 + (ss-lss);
			if (a_lead) {
				la += excess;	
			} else if (h_lead) {
				lh += excess;
			}
		}
		ltt=tt;
		lss=ss;
	}
	int excess = (32 - ltt) * 60 + (0 - lss);
	if (pa > ph) {
		la += excess;
	} else {
		lh += excess;
	}
	string winner;
	if (pa > ph) winner = "A";
	else winner = "H";
	cout << winner << " ";
	cout << lh / 60 << ":";
	lh % 60 < 10 ? cout << "0" << lh % 60 << " " : cout << lh % 60 << " ";
	cout << la / 60 << ":";
	la % 60 < 10 ? cout << "0" << la % 60 << endl : cout << la % 60 << endl;
}
