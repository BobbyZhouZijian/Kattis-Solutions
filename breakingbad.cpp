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
vector<int> items;
vector<vector<int>> g;
vector<int> color;

bool dfs(int x, int c) {
    color[x] = c;
    for (int j : g[x]) {
        if (color[j] == 0) {
            if (!dfs(j, 3 - c)) {
                return false;
            }
        } else if (color[j] == color[x]) {
            return false;
        }
    }
    return true;
}

int main() {
    fast();

    cin >> N;
    map<int, string> m;
    map<string, int> m1;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        m[i] = s;
        m1[s] = i;
        items.push_back(i);
    }

    cin >> M;

    g.resize(N);

    string s1, s2;
    for (int i = 0; i < M; ++i) {
        cin >> s1 >> s2;
        int id1 = m1[s1], id2 = m1[s2];
        g[id1].push_back(id2);
        g[id2].push_back(id1);
    }


    color.resize(N, 0);

    for (int i = 0; i < N; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (color[i] == 1) {
            cout << m[i] << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        if (color[i] == 2) {
            cout << m[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
