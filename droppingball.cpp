#include <iostream>
#include <vector>
using namespace std;

int m, n, q;
vector< vector<int> > grid;
vector< vector<int> > t;

void solve1() {
    while(q--) {
        int x; cin >> x;
        if (x == 1) {
            int i, j;
            cin >> i >> j;
            grid[i][j] ^= 1;
        }

        else {
            int j; cin >> j;
            bool ok = true;
            for (int i = 1; i <= m; ++i) {
                if(grid[i][j]) {
                	if(!grid[i][j - 1]) {
                		ok = false;
                		break;
                	} else j--;
                }

                else {
                	if(j == n || grid[i][j + 1]) {
                		ok = false;
                		break;
                	} else j++;
                }
            }

            cout << (ok ? j: -1) << endl;
        }
    }  
}

void update(int v) {
	int lc = v << 1;
	int rc = lc + 1;

	for (int j = 1; j <= n; ++j) {
		if(t[lc][j] == -1) t[v][j] = -1;
		else t[v][j] = t[rc][t[lc][j]];
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		for(int j = 1; j <= n; ++j) {
			if(grid[tl][j]) {
				if(!grid[tl][j - 1]) t[v][j] = -1;
				else t[v][j] = j - 1;
			}

			else {
				if(j == n || grid[tl][j + 1]) t[v][j] = -1;
				else t[v][j] = j + 1;
			}
		}
		return;
	}

	int lc = v << 1, mid = (tl + tr) >> 1;
	int rc = lc + 1;
	build(lc, tl, mid);
	build(rc, mid + 1, tr);
	update(v);
}

void modify(int v, int tl, int tr, int i, int j) {
	if(tl == tr) {
		grid[i][j] ^= 1;

		for(int k = max(1, j - 1); k <= min(n, j + 1); ++k) {
			if(grid[i][k]) {
				if(!grid[tl][k - 1]) t[v][k] = -1;
				else t[v][k] = k - 1;
			}

			else {
				if(k == n || grid[tl][k + 1]) t[v][k] = -1;
				else t[v][k] = k + 1;
			}
		}
		return;
	}

	int lc = v << 1;
	int rc = lc + 1;
	int mid = (tl + tr) >> 1;
	if(i <= mid) modify(lc, tl, mid, i, j);
	else modify(rc, mid + 1, tr, i, j);
	update(v);
}

void solve2() {
	build(1, 1, m);
	while(q--) {
		int x; cin >> x;
		if (x == 1) {
			int i, j;
			cin >> i >> j;
			modify(1, 1, m, i, j);
		}

		else {
			int j;
			cin >> j;
			cout << t[1][j] << endl;
		}
	}
}


int main() {
    cin >> m >> n >> q;

    grid.resize(m + 1, vector<int>(n + 1, 0));
    t.resize(5 * m, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j) grid[i][j] = s[j - 1] == '/';
    } 

	m < 1000 ? solve1() : solve2();	
}



