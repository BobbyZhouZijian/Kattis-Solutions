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

int main() {
    fast();
    cin >> N >> M;

    vector<ll> f;
    for (int i = 0; i < N; ++i) {
        ll x; cin >> x;
        f.push_back(x);
    }

    vector<pair<ll, ll>> m;
    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x>> y;
        m.push_back({x, y});
    }

    sort(f.rbegin(), f.rend());

    sort(m.begin(), m.end(), [](pair<ll, ll> p1, pair<ll, ll> p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    });

    int i = 0, j = 0;
    ll p = 0;
    while (j < M && i < N) {
        if (m[j].first == 0) {
            j++;
            continue;
        }
        m[j].first--;
        p += f[i] * m[j].second;
        i++;
    }

    cout << p;

    return 0;
}
