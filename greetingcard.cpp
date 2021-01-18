#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(pair<T1, T2> const &p) const {
        size_t h1 = hash<T1>()(p.first);
        size_t h2 = hash<T2>()(p.second);

        return h1 ^ h2;
    }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int dx[12] = {0,1118,1680,2018,1118,1680,-1118,-1680,0,-1118,-1680,-2018};
int dy[12] = {2018,1680,1118,0,-1680,-1118,-1680,-1118,-2018,1680,1118,0};
int N;


int main() {
    fast();
    cin >> N;

    unordered_set<pair<int,int>, pair_hash> s;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        s.insert({x,y});
    }
    int cnt = 0;
    for (auto p : s) {
        int x = p.first, y = p.second;
        for (int i = 0; i < 12; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (s.find({nx,ny}) != s.end()) {
                cnt++;
            }
        }
    }

    cout << cnt / 2 << endl;

    return 0;
}
