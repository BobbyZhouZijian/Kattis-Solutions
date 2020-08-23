#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int LIS(vector<int>& v) {
    if (v.empty()) return {}; //prevent access overflow
    int n = v.size();
    vector<int> p(n, -1); //index to prev index
    vector<int> t(n, 0); //len to index

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
                if (v[i] <= v[t[mid]]) r = mid;
                else l = mid;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }
    int ans = 0;
    for (int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans++;
    }
    return ans;
}

int main() {
    deque<int> v;

    int n, i;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        cin >> i;
        v.push_back(i);
    }

    int ans = 0;
    while (!v.empty()) {
        int center = v.front();
        v.pop_front();
        vector<int> d1;
        vector<int> d2;

        for (int t : v) {
            if (t > center) {
                d1.push_back(t);
            }
        }

        for (int t : v) {
            if (t < center) {
                d2.push_back(-t);
            }
        }

        ans = max(ans, LIS(d1) + LIS(d2) + 1);
    }
    cout << ans;
}