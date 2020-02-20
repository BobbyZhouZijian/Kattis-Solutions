# include <iostream>
# include <string>
# include <vector>
# include <cmath>
# include <iomanip>
# include <map>
# include <stack>
# include <set>
# include <algorithm>
# include <sstream>
# include <unordered_map>

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

struct edge {
    int n1, n2, w;
};

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

int find(vector<int>& d, int a) {
    if (d[a] == -1) {
        return a;
    }
    
    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    
    if (a == b) {
        return;
    }
    
    d[a] = b;
}

int main() {
    fast();
    
    int cases;
    cin >> cases;
    
    while (cases--) {
        int m, c;
        cin >> m >> c;
        
        vector<edge> v(c*(c-1)/2);
        for(auto& i: v) {
            cin >> i.n1 >> i.n2 >> i.w;
        }
        
        
        sort(all(v), cmp);
        
        int w = 0;
        
        vector<int> d(c, -1);
        for(auto i : v) {
            if (find(d, i.n1) != find(d, i.n2)) {
                join(d, i.n1, i.n2);
                w += i.w;
            }
        }
        
        if (m - w - c >= 0) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
