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

int N;

void solve(int x) {
    
    int tmp = x;
    int res = tmp % 7;
    if (res == 6) {
        if (tmp==6) cout << "6";
        else cout << "68";
        for (int i = 0; i < tmp/7-1;++i) cout << "8";
    } else if (res == 5) {
        cout << "2";
        for (int i = 0; i < tmp/7;++i) cout << "8";
    } else if (res==4) {
        if (tmp==4) cout << "4";
        else cout << "20";
        for (int i = 0; i < tmp/7-1;++i) cout << "8";
    } else if (res == 3) { // check
        if (tmp==3) cout << "7";
        else if (tmp >= 17) {
            cout << "200";
            for (int i = 0; i < (tmp-17)/7;++i) cout << "8";
        } else {
            cout << "22";
            for (int i = 0; i < tmp/7-1;++i) cout << "8";
        }
    } else if (res == 2) { // check
        cout << "1";
        for (int i = 0; i < tmp/7;++i) cout << "8";
    } else if (res == 1) { // check
        cout << "10";
        for (int i = 0; i < tmp/7-1;++i) cout << "8";
    } else { // check
        for (int i = 0; i < tmp/7;++i) cout << "8";
    }

    cout << " ";

    if (x % 2 == 0) {
        for (int i = 0; i < x / 2; ++i) {
            cout << "1";
        }
    } else {
        cout << "7";
        for (int i = 0; i < (x-3) / 2; ++i) {
            cout << "1";
        }
    }
    cout << endl;
}

int main() {
    fast();
    cin >> N;

    while (N--) {
        int x; cin >> x;
        solve(x);
    }

    return 0;
}
