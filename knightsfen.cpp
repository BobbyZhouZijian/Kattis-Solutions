#include <iostream>
#define inf 1000001
using namespace std;

int m1[5][5], m[5][5] = {{1,1,1,1,1},{0,1,1,1,1},{0,0,-1,1,1},
                            {0,0,0,0,1},{0,0,0,0,0}};

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,2,-2,1,-1};

int si, sj;
string cur;
 
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

bool match() {
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(m1[i][j] != m[i][j]) return false;
        }
    }
    return true;
}

bool inbound(int i, int j) {
    return i >= 0 && i < 5 && j >= 0 && j < 5;
}

void swap(int i, int j, int ni, int nj) {
    int tv = m1[i][j];
    m1[i][j] = m1[ni][nj];
    m1[ni][nj] = tv;
}

int solve(int pi, int pj, int i, int j, int depth) {
    if(depth > 10) return inf;
    if(match()) return 0;

    int ans = inf;

    for(int k = 0; k < 8; ++k) {
        int ni = i + dx[k], nj = j + dy[k];

        if(inbound(ni, nj) && (ni != pi || nj != pj)) {
            swap(i, j, ni, nj);
            ans = min(ans, 1 + solve(i, j, ni, nj, depth + 1));
            swap(i, j, ni, nj);
        } 
    }

    return ans;
}

int main() {
    fast();

    int n; cin >> n;
    getline(cin, cur);
    while(n--) {
        for(int i = 0; i < 5; ++i) {
            getline(cin, cur);
            for(int j = 0; j < 5; ++j) {
                m1[i][j] = cur[j] == '1' ? 1 : (cur[j]=='0' ? 0 : -1);

                if(cur[j] == ' ') {
                    si = i;
                    sj = j;
                }
            }
        }

        int ans = solve(si, sj, si, sj, 0);
        if(ans > 10) cout << "Unsolvable in less than 11 move(s)." << endl;
        else cout << "Solvable in " << ans << " move(s)." << endl;
    }

    return 0;
}
