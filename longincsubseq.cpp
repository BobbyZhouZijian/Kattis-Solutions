#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int>& v) {
    int n = v.size();
    vector<int> p(n, -1); // index to prev index
    vector<int> t(n, 0); // len to index

    int lis = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] <= v[t[0]]) {
            t[0] = i;
        } else if (v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        } else {
            int l = -1;
            int r = lis - 1;
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (v[t[mid]] >= v[i]) r = mid;
                else l = mid;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    vector<int> res;
    for (int i = t[lis - 1]; i >= 0; i = p[i]) {
        res.push_back(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main1() {
    // io
    int n;
    while (cin >> n) {
        vector<int> arr = vector<int>();
        for (int i = 0; i < n; ++i) {
            int cur;
            cin >> cur;
            arr.push_back(cur);
        }
        vector<int> res = solve(arr);
        cout << res.size() << endl;
        for (int& t : res) cout << t << " ";
        cout << endl;
    }
}

