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

int N, K;
vector<vector<int>> nodes;
vector<int> depths;
vector<int> skills;

ll ans = 0;

bool is_leaf(int x) {
    return nodes[x].size() == 0;
}

vector<int> st;


int mark(int x) {
    if (is_leaf(x)) {
        depths[x] = 0;
        return 0;
    }

    int dep = 0;
    for (int j : nodes[x]) {
        dep = max(mark(j) + 1, dep);
    }
    depths[x] = dep;
    return dep;
}

void dfs(int x, int dep) {
    if (is_leaf(x)) {
        return;
    }
    bool all_leaf = true;
    for (int j : nodes[x]) {
        if (!is_leaf(j)) all_leaf = false;
    }

    if (all_leaf) {
        st.push_back(dep);
        return;
    }

    int max_dep = 0;
    int max_node = -1;

    for (int j : nodes[x]) {
        if (depths[j] >= max_dep) {
            max_dep = depths[j];
            max_node = j;
        }
    }

    for (int j : nodes[x]) {
        if (!is_leaf(j)) {
            if (j == max_node) dfs(j, dep + 1);
            else dfs(j, 2);
        }
    }
}

int main() {
    fast();

    cin >> N >> K;

    for (int i = 0; i < K; ++i) {
        int x ; cin >> x;
        skills.push_back(x);
    }


    sort(skills.rbegin(), skills.rend());

    nodes.resize(N);
    depths.resize(N);

    for (int i = 1; i <= N - 1; ++i) {
        int x; cin >> x;
        nodes[x].push_back(i);
    }

    mark(0);
    dfs(0, 1);

    sort(st.rbegin(), st.rend());

    int i = 0;

    for (; i < st.size(); ++i) {
        ans += static_cast<ll>(st[i]) * static_cast<ll>(skills[i]);
    }

    for (; i < K; ++i) {
        ans += static_cast<ll>(skills[i]);
    }

    cout << ans << endl;

    return 0;
}
