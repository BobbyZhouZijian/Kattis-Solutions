#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> arr(n+1,0);
    set<pair<int,int>> st1, st2;

    int cnt = 0;
    for (int i = 1 ; i <= n; ++i) {
        if (s[i-1] == 'B')
            cnt++;
        else
            cnt--;
        arr[i] = cnt;
        st1.insert({cnt, i});
        st2.insert({cnt, -i});
    }

    int ans = 0;
    int bi = 0, bj = 0;
    for (int i = 0; i <= n; ++i) {
        auto p1 = *(st2.rbegin());
        auto p2 = *(st1.begin());
        if (abs(p1.first - arr[i]) > ans) {
            ans = abs(p1.first - arr[i]);
            bi = i+1;
            bj = -p1.second;
        }
        if (abs(p2.first - arr[i]) > ans) {
            ans = abs(p2.first - arr[i]);
            bi = i+1;
            bj = p2.second;
        }

        if (i>0) {
            st1.erase({arr[i], i});
            st2.erase({arr[i], -i});
        }
    }

    cout << bi << ' ' << bj << endl;
}
