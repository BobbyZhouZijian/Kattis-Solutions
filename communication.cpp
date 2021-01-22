#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n;

int main() {
    fast();
    cin >> n;
    unordered_map<int,int> m;
    int all = (1<<8)-1;
    for (int j = 0; j<=all; ++j){
        m[(j^(j<<1))&all]=j;
    }
    for(int i=0; i<n; ++i){
        int t; cin >> t;
        cout << m[t] << ' ';
    }
    cout <<'\n';

    return 0;
}
