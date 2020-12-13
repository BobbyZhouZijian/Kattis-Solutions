#include <bits/stdc++.h>
using namespace std;

bool is_prefix(string s1, string s2) {
    int l1 = s1.length();
    for (int i = 0; i < l1; ++i) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        vector<string> v;
        string num;
        for (int i = 0; i < c; ++i) {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        bool can = true;
        for(int i = 0; i < v.size() - 1; ++i) {
            if (is_prefix(v[i], v[i + 1])) {
                can = false;
                break;
            }
        }
        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}