#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int> > g;
    vector<int> ind(n);
    int u,v;
    while(m--) {
        cin>>u>>v;
        g[u].push_back(v);
        ind[v]++;
    }
    queue<int > q;
    int count = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!ind[i]) {q.push(i); count++;}
        if(count > 1) {
            ok = false;
            break;
        }
    }
    if (ok) {
        string out = "";
        while(!q.empty()) {
            int t = q.front(); q.pop();
            out += to_string(t) + " ";
            count--;
            for(int i : g[t]) {
                ind[i]--;
                if (!ind[i]) {count++; q.push(i);}
                if (count > 1) ok =false;
            }
            if (!ok) break;
        }
        if (ok) cout << out;
    }
    if (!ok) cout << "back to the lab";
}