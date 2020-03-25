#include <iostream>
#include <vector>
using namespace std;

const int inf = 1 << 30;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m,q,s;
    while(1){
        cin >>n>>m>>q>>s;
        if(!n&&!m&&!s&&!q) break;
        vector< vector<int> > edges;
        vector<int> dis(n, inf);
        dis[s]=0;
        int u,v,w,i;
        for(i = 0; i < m; ++i) {
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }

        // bellman-ford
        for(i=1; i<n; ++i) {
            for(auto& v : edges) {
                if (dis[v[0]]!=inf && dis[v[0]]+v[2]<dis[v[1]]) {
                    dis[v[1]]=dis[v[0]]+v[2];
                }
            }
        }
        // for(int e : dis) cout << e <<" "; cout << endl;

        // negative cycle
        bool cycle=false;
        for(auto& v : edges) {
            if(dis[v[0]]==-inf || (dis[v[0]]!=inf && dis[v[0]]+v[2]<dis[v[1]])) {
                dis[v[1]]=-inf;
                cycle=true;
            }
        }

        if(cycle){
            for(i=2;i<n;++i){
                for(auto& v : edges) {
                    if(dis[v[0]]==-inf || (dis[v[0]]!=inf && dis[v[0]]+v[2]<dis[v[1]])) 
                        dis[v[1]]=-inf;
                } 
            }
        }

        int dest;
        for(i=0;i<q;++i) {
            cin>>dest;
            if(dis[dest]==-inf) cout<<"-Infinity"<<endl;
            else if(dis[dest]==inf) cout<<"Impossible"<<endl;
            else cout << dis[dest]<<endl;
        }
        cout << endl;
    }
}