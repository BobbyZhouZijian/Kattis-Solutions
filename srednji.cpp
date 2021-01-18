#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int N, B;

int main() {
    fast();
    cin >> N >> B;
    int idx=-1;
    vector<int>arr;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (x == B) idx = i;
        arr.push_back(x);
    }

    if (idx ==-1) {
        cout << 0 << endl;
        return 0;
    }
    
    int cnt = 0;

    int right = N - idx - 1, left = idx;

    unordered_map<int,int> l, r;

    l[0]=1;
    r[0]=1;

    int offset = 0;
    for(int i = idx-1; i >= 0; --i) {
        if (arr[i] < B) offset++;
        else offset--;
        l[offset]++;
    }
    offset=0;
    for (int i = idx+1; i < N; ++i) {
        if (arr[i] > B) offset++;
        else offset--;
        r[offset]++;
    }

    for (auto p : r) {
        cnt += p.second * l[p.first];
    }

    cout << cnt << endl;
    return 0;
}
