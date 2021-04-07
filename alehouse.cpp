#include <bits/stdc++.h>
using namespace std;

int n,k;

int main() {
    scanf("%d%d",&n,&k);

    vector<pair<int,int>> p;
    int x,y;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&x,&y);
        p.push_back({x,0});
        p.push_back({y+k,1});
    }

    sort(p.begin(),p.end());
    int cnt = 0, maxm = 0;
    for (auto &[t,leave] : p) {
        if (!leave) cnt++;
        else cnt--;
        maxm = max(maxm, cnt);
    }

    printf("%d\n", maxm);
}

