#include <bits/stdc++.h>
using namespace std;

int n1,n2;
char g[4][4];

int scores[] = {0,0,0,1,1,2,3,5,11};
bool vis[4][4];

int dx[] = {1,0,-1,0,1,1,-1,-1}, dy[] = {0,1,0,-1,1,-1,1,-1};

bool search(string& s, int i, int j, int len) {
    if (s.length() == len) return 1;
    if (i < 0 || i > 3 || j < 0 || j > 3 || vis[i][j]) return 0;
    if (g[i][j] != s[len]) return 0;

    vis[i][j] = 1;
    bool work = 0;
    for (int k = 0; k < 8 && !work; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if (search(s,nx,ny,len+1)) work = 1;
    }

    vis[i][j] = 0;
    return work;
}

bool found(string& s) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (search(s,i,j,0)) return 1;
        }
    }

    return 0;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    memset(vis,0,sizeof vis);
    cin >> n1;
    vector<string> dic(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> dic[i];
    }

    cin >> n2;

    for (int i = 0; i < n2; ++i) {
        for (int k = 0; k < 4; ++k) {
            string s;
            cin >> s;
            for (int l = 0; l < 4; ++l) {
                g[k][l] = s[l];
            }
        }

        string word;
        int cnt = 0, sc = 0;
        for (string &s : dic) {
            if (found(s)) {
                cnt++;
                if (s.length() > word.length()) {
                    word = s;
                } else if (s.length() == word.length() && s < word) {
                    word = s; 
                }
                sc += scores[s.length()];
            }
        }

        cout << sc << ' ' << word << ' ' << cnt << '\n';
    }
}
