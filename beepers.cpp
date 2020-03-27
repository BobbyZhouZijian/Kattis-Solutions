#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int cases,m,n,sx,sy,k,x,y; cin >> cases;
    while(cases--) {
        cin>>m>>n>>sx>>sy>>k;
        vector< pair<int, int> > v;
        while(k--){
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        int gminm=2147483647,tx,ty;
        do {
            int minm = 0; tx=sx,ty=sy;
            for(auto& p : v) {
                minm += abs(tx-p.first)+abs(ty-p.second);
                tx=p.first; ty=p.second;
            }
            minm += abs(sx-tx) + abs(sy-ty);
            gminm = min(gminm, minm);
        } while(next_permutation(v.begin(),v.end()));
        cout << gminm << endl;
    }
}