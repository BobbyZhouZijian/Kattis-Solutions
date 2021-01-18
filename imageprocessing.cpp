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

int H,W,N,M;

int main() {
    fast();
    cin >> H>>W>>N>>M;

    vector<vector<int>> im(H,vector<int>(W));
    vector<vector<int>> ker(N,vector<int>(M));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> im[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ker[i][j];
        }
    }

    for (int i = 0; i < H-N+1;++i) {
        for (int j = 0; j < W-M+1; ++j) {
            int res = 0;
            for (int k1=N-1;k1>=0;--k1) {
                for (int k2=M-1; k2>=0; --k2) {
                    res += ker[k1][k2] * im[i+N-k1-1][j+M-k2-1]; 
                }
            }
            cout << res << " ";
        }
        cout << "\n";
    }

    return 0;
}
