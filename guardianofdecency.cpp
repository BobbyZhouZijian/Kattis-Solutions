#include <bits/stdc++.h>
using namespace std;

int n;

struct person {
    int h;
    char sex;
    string music, sport;
} g[1001];

vector<vector<int>> AL;
vector<bool> vis;
vector<int> match;

vector<int> Left;

int aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (int &R : AL[L]) {
        if (match[R] == -1 || aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n;
    int h;
    char sex;
    string music, sport;
    for (int i = 0;i < n; ++i) {
        cin >> h >> sex >> music >> sport;
        g[i] = {h,sex,music,sport};
        if (sex == 'M') {
            Left.push_back(i);
        }
    }

    AL.assign(n+1,{});

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (abs(g[i].h - g[j].h) <= 40 && g[i].sex != g[j].sex
                && g[i].music == g[j].music && g[i].sport != g[j].sport) {
                AL[i].push_back(j);
                AL[j].push_back(i);
            }
        }
    }

    match.assign(n+1,-1);

    int res = 0;
    for (int i : Left) {
        vis.assign(n+1,0);
        res += aug(i);
    }

    cout << n - res << endl;
}
