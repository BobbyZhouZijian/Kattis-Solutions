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

int M, N;

int main() {
    fast();
    while (cin >> M >> N) {
        char jk, fal;
        cin >> jk >> fal >> jk;
        vector<vector<char>> f1(M,vector<char>(N)), f2(M,vector<char>(N));
        
        int x=10000, y=10000;
        for (int i = 0; i<M; ++i) {
            for (int j=0; j<N;++j){
                char c;
                cin >> c;
                f1[i][j] = c;
                if (c == fal) {
                    if (i<x) {
                        x = i;
                        y = j;
                    } else if (i==x) {
                        y=min(y,j);
                    }
                }
            }
        }

        int x2=10000, y2=10000;

        for(int i=0; i<M;++i) {
            for(int j =0; j<N; ++j) {
                char c;
                cin >> c;
                f2[i][j] = c;
                if (c == fal) {
                    if (i<x2) {
                        x2=i;
                        y2=j;
                    } else if (i==x2) {
                        y2=min(y2,j);
                    }
                }
            }
        }
        
        int sx = x2-x, sy = y2-y;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j){
                int lx=i-sx, ly=j-sy;
                if (lx>=0 && lx<M && ly>=0 && ly<N && f2[lx][ly]==fal) {
                    cout << fal; 
                } else if (f2[i][j]==fal) {
                    cout << f1[i][j];
                } else {
                    cout << f2[i][j];
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }


    return 0;
}
