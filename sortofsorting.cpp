#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2) {
    if (s1.substr(0, 2) == s2.substr(0, 2)) {
        return false;
    }
    else return s1 < s2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        stable_sort(v.begin(), v.end(), comp);
        for (string s : v) cout << s << endl;
        cout << "\n";
    }
}