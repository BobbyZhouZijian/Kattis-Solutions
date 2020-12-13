#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && v[j + 1] == v[j] + 1) {
            j++;
        }
        if (j - i > 1) {
            cout << v[i] << '-' << v[j] << " ";
            i = j;
        } else {
            cout << v[i] << " ";
        }
        i++;
    }
}