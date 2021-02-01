#include <bits/stdc++.h>
using namespace std;

int n;
double mat[105][105];
unordered_map<string, int> m1;
unordered_map<int, string> m2;
int id = 1;

vector<unordered_map<string, double>> dp;

void tsp(int x, string vis) {
    if (vis.size() == 0) return mat[m1["home"]][x];
    double &ans = dp[x][vis];
    if (ans) return ans;
    int n = vis.length();
    for (int i = 0; i < n; ++i) {
        int j = vis[i] - '0';
        string next = s.substr(0, i) + s.substr(i+1);
        ans = min(ans, tsp(j, next) + mat[x][j]);
    }
    return ans;
}
int main() {
    cin >> n;
    memset(mat, 0, sizeof mat);
    string name;
    double x, y;
    vector<tuple<int, double, double>> v;
    for (int i = 0; i < n; ++i) {
        cin >> name >> x >> y;
        if (!m1.count(name)) {
            m1[name] = id;
            m2[id++] = name;
        }
        v.push_back({m1[name],x,y});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( i == j) continue;
            int id1, id2;
            double x1,y1, x2,y2;
            tie(id1,x1,y1) = v[i];
            tie(id2,x2,y2) = v[j];

            double dist = hypot((x2-x1), (y2-y1));

            mat[id1][id2] = dist;
            mat[id2][id1] = dist;
        }
    }
    
    while (!cin.eof()) {
        string vis;
        string s;
        int cnt = 0;
        do {
            cin >> s;
            vis += (char)(m1[s] + '0');
            cnt++;
        } while (cin.peek() == ' ');
        
        sort(vis.begin(), vis.end());
        dp.assign(n, {});
        cout << tsp(m1["work"], vis) << endl;
    }
}
