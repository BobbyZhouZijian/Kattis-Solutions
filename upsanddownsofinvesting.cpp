#include <bits/stdc++.h>
using namespace std;

int s,n,m;
vector<int> arr;

void ups() {
	int cnt = 0;
	int i = -1;
	while ( ++i + 2*n-2 < s ) {
		bool can = true;
		for (int j = i; j < i+n-1; ++j) {
			if (arr[j+1]<arr[j]) {
				can = false;
				break;
			}
		}	
		if (can) {
			for (int j=i+n-1; j<i+2*n-2; ++j) {
				if (arr[j+1]>arr[j]) {
					can = false;
					break;
				}
			}
		}
		if (can) {
			cnt++;
		}
	}
	cout << cnt;
}

void downs() {
	int cnt = 0;
	int i = -1;
	while ( ++i + 2*m-2 < s ) {
		bool can = true;
		for (int j = i; j < i+m-1; ++j) {
			if (arr[j+1]>arr[j]) {
				can = false;
				break;
			}
		}	
		if (can) {
			for (int j=i+m-1; j<i+2*m-2; ++j) {
				if (arr[j+1]<arr[j]) {
					can = false;
					break;
				}
			}
		}
		if (can) {
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> s>> n >>m;
	int x;
	for (int i = 0; i < s; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	ups();
	cout << " ";
	downs();
	cout << endl;
}
