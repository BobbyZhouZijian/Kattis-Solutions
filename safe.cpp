#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct HASH {
  size_t operator()(const array<int,9>&x)const{
    size_t ans=0;
    for(int i=0;i<9;i++) {
        ans *= 10;
        ans += x[i];
    }
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

array<int,9> arr, target = {0,0,0,0,0,0,0,0,0};
unordered_map<array<int,9>, int, HASH> m;

int ans = -1;

void bfs() {
    queue<array<int,9>> q;
    q.push(target);
    m[target] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 9; ++i) { 
            array<int,9> new_a;
            for (int k = 0; k < 9; ++k) new_a[k] = cur[k];
            new_a[i] = (new_a[i]+3) % 4;
            int x = i/3, y = i%3;
            for (int j = 0; j < 3; ++j) {
                if (3*x+j!=i) {
                    new_a[3*x+j] = (new_a[3*x+j]+3)%4;
                }
                if (3*j+y!=i) {
                    new_a[3*j+y] = (new_a[3*j+y]+3)%4;
                }
            }
            if (!m.count(new_a)) {
                m[new_a] = m[cur] + 1; 
                q.push(new_a);
            }
        }
    }
}

int main() {
    fast();
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
    }

    bfs();

    if (m.count(arr)) ans = m[arr];

    cout << ans << endl;

    return 0;
}
