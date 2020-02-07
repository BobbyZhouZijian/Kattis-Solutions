#include <iostream>
#include <deque>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

void trans(deque<int> &q1, deque<int> &q2, int val, bool back) {
	int trans;
	if (back) {
		trans = q1.back();
		q1.pop_back();
		q2.push_front(trans);
	}

	else {
		trans = q2.front();
		q2.pop_front();
		q1.push_back(trans);
	}
}

int main(int argc, char const *argv[])
{
	fast();


	deque<int> q1;
	deque<int> q2;
	int l1 = 0, l2 = 0;

	int n;
	cin >> n;
	while(n--) {
		string type;
		int val;
		cin >> type >> val;

		if (type == "push_back") {
			l2++;
			q2.push_back(val);

			if (l2 > l1) {
				trans(q1, q2, val, false);
				l1++;
				l2--;
			}
		}

		else if (type == "push_front") {
			l1++;
			q1.push_front(val);

			if (l1 > l2 + 1) {
				trans(q1, q2, val, true);
				l2++;
				l1--;
			}
		}

		else if (type == "push_middle") {
			if (l1 > l2) {
				q2.push_front(val);
				l2++;
			}

			else {
				q1.push_back(val);
				l1++;
			}
		}

		else {
			if (val >= l1) {
				cout << q2[val - l1] << endl;
			} else {
				cout << q1[val] << endl;
			}
		}
	}
	return 0;
}














