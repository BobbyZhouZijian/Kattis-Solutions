#include <bits/stdc++.h>
using namespace std;

int n;

priority_queue<int, vector<int>, greater<int>> pq;

int find() {
    if (pq.empty()) {
        cout << "Error" << endl;
        return -1;
    }
    int res = pq.top(); pq.pop();
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector<int> arr;
    vector<bool> seen(2+n,false);
    vector<int> cnt(2+n,0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
        seen[x] = true;
        cnt[x]++;
    }
    if (arr.back() != n+1) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 1; i <= n+1; ++i) {
        if (!seen[i]) pq.push(i);
    }
    vector<int> last(n,-1);
    for (int i = 0; i < n; ++i) {
        cnt[arr[i]]--;
        if (cnt[arr[i]]==0) last[i]=arr[i];
    }
    int k=find();
    if (k == -1) return 0;

    vector<int> buff;
    
    for (int i = 0; i < n; ++i) {
        buff.push_back(k);
        if (i==n-1) {
            break;
        }
        if (last[i]!=-1) {
            pq.push(last[i]);
        }
        k = find();
        if (k == -1) return 0;
    }

    for (int i : buff) cout << i << endl;
}
