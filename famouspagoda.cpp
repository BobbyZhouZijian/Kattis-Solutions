#include <iostream>
#define ll long long
#define inf 999999999999999999
#define N 2005

using namespace std;
int n, m, k, s[N];
ll sum1[N], sum2[N], f[N][N], g[N][N];

ll cal(ll x, ll a, ll b, ll c) {
	return (ll)a * x * x + (ll)b * x + c;
}


void solve(int l, int r, int lx, int rx, int j) {
	if(l > r)return;
  	int mid=(l+r)>>1,pos=-1;
  	for(int i=lx;i<=rx&&i<mid;i++)
    	if(f[mid][j]>f[i][j-1]+g[i+1][mid]) {
      		f[mid][j]=f[i][j-1]+g[i+1][mid];
      		pos=i;
    	}
  	solve(l,mid-1,lx,pos,j);
  	solve(mid+1,r,pos,rx,j);
}


int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	for(int i = 1; i <= n; ++i) sum1[i] = sum1[i - 1] + s[i];
	for(int i = 1; i <= n; ++i) sum2[i] = sum2[i - 1] + (ll)s[i] * s[i];

	if(k == 1) {
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j <= n; ++j) {
				if(j - i == 0) {
					g[i][j] = 0;
					continue;
				}

				if(j - i == 1) {
					g[i][j] = s[j] - s[i];
					continue;
				}

				if((j - i) & 1) {
					ll pos = (i + j) / 2;
					g[i][j] = sum1[j] - sum1[pos] - (sum1[pos] - sum1[i - 1]);
				} else {
					ll pos = (i + j) >> 1;
					g[i][j] = sum1[j] - sum1[pos] - (sum1[pos - 1] - sum1[i - 1]);
				}
			}
		}
	}

	else {
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j <= n; ++j) {
				ll a = j - i + 1;
				ll b = 2 * (sum1[j] - sum1[i - 1]);
				ll c = sum2[j] - sum2[i - 1];

				g[i][j] = min(cal(s[i], a, -b, c), cal(s[j], a, -b, c));
				ll pos = b / (2 * a);
				if(s[i] < pos && pos < s[j]) g[i][j] = min(g[i][j], cal(pos, a,-b, c)); 
				pos++;
				if(s[i] < pos && pos < s[j]) g[i][j] = min(g[i][j], cal(pos, a, -b, c));
			}
		}
	}

	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j) f[i][j] = inf;
	
	f[0][0] = 0;

	for(int j = 1; j <= m; ++j) solve(j, n, j - 1, n, j);

	cout << f[n][m];

}