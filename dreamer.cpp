#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct HASH {
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int TC;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool smaller(int y, int m, int d, int y1, int m1, int d1) {
    if (y<y1) return 1;
    else if (y>y1) return 0;
    if (m<m1) return 1;
    else if (m>m1)return 0;
    return d<d1;
}

bool is_leap(int year) {
    if (year % 4 != 0) 
        return false;
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return true;
}

void solve() {
    int arr[10];
    for (int i = 0; i < 8; ++i) {
        char c; cin>>c;
        arr[i] = c-'0';
    }
    sort(arr, arr+8); 
    int cnt = 0;
    int min_y = 9999;
    int min_m = 12;
    int min_d = 32;
    do {
        int year = 1000 * arr[4] + 100 * arr[5] + 10 * arr[6] + arr[7];
        int mon = 10 * arr[2] + arr[3];
        int day = 10 * arr[0] + arr[1];
        int hash = 1000 * year + 100 * mon + day;
        if (is_leap(year)) days[2] = 29;
        else days[2] = 28;
        if (mon > 12 || mon <= 0 || days[mon] < day || year < 2000 || day <= 0) continue;
        cnt++;
        if (smaller(year, mon, day, min_y, min_m, min_d)) {
            min_y = year;
            min_m = mon;
            min_d = day;
        }
    } while (next_permutation(arr, arr+8));

    if (cnt == 0) cout << cnt << "\n";
    else cout << cnt << " " << (min_d<10?"0":"") << min_d 
        << " " << (min_m<10?"0":"") << min_m << " " << min_y << "\n";
}

int main() {
    fast();
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}
