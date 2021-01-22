#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n,m;

int main() {
    fast();
    cin >> n >> m;
    int all = (1<<n)-1;
    vector<unordered_set<int>> v(n+1);
    for (int i = 0; i < m; ++i){
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].insert(y);
        v[y].insert(x);
    }

    int cnt=0;
    for(int mask=0; mask<=all; ++mask) {
        bool can=true; 
        for(int i=0; i<n; ++i) {
            if((1<<i)&mask){
                for(int j:v[i]) {
                    if ((1<<j)&mask) {
                        can=false;
                        break;
                    }
                }
                if(!can)break;
            }
        }
        if(can)cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
