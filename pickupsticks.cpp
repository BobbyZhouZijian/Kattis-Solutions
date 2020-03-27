#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
     int n,m, u,v;
     cin>>n>>m;
     map<int, vector<int> > g;
     vector<int> ind(n + 1);
     while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        ind[v]++;
     }
     queue<int> q;
     for(m = 1; m <= n; ++m) {
         if (!ind[m]) q.push(m);
     }
    queue<int> out;
    int size = 0;
     while(!q.empty()){
         int top = q.front(); q.pop();
         size++;
         out.push(top);
         for(int i : g[top]) {
             if(!--ind[i]) q.push(i);
         }
     }

    if (size < n) cout << "IMPOSSIBLE";
    else {
        while(!out.empty()) {
            m=out.front(); out.pop();
            cout << m << endl;
        } 
    }
} 