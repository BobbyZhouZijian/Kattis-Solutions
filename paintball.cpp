#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
using namespace std;
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

int N, M;
vector<int> l, r;
vector<bool> vis; 
vector<vector<int>> g;

bool dfs(int x) {
    for (int i : g[x]) {
        if (vis[i]) continue;
        vis[i] = true;
        if (r[i] == -1 || dfs(r[i])) {
            l[x] = i;
            r[i] = x;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (l[i] == -1) {
            vis.clear();
            vis.resize(N, false);
            ans += dfs(i);
        } else {
            ans++;
        }
    }
    return ans;
}

int main() {
    fast();

    cin >> N >> M;
    g.resize(N);
    l.resize(N, -1);
    r.resize(N, -1);
    vis.resize(N, false);

    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res = hungarian();

    if (res != N) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            cout << l[i] + 1 << endl;
        }
    }

    return 0;
}
