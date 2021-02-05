#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string, int> m1;
vector<int> v[1001];
double ss[1001];
vector<vector<pair<int,double>>> dp(1001, vector<pair<int,double>>(2, {-1,0}));
int id = 0;

pair<int, double> search(int idx, int choose) {
    // do not choose cur
    if (dp[idx][choose].first != -1) {
        return dp[idx][choose]; 
    }
    if (!choose) {
        int maxm = 0;
        double s = 0;
        for (int p : v[idx]) {
            auto next = search(p, 1);
            maxm += next.first;
            s += next.second;
        }

        return dp[idx][0] = {maxm, s};
    }

    // choose
    auto p = search(idx, 0);
    int maxm2 = p.first;
    double s2 = p.second;
    int pmax2 = p.first;
    double ps2 = p.second;
    for (int i : v[idx]) {
        auto next1 = search(i, 1), next0 = search(i, 0);
        int curmax = pmax2 - next1.first + next0.first + 1;
        double curs = ps2 - next1.second + next0.second + min(ss[i], ss[idx]);
        if (curmax > maxm2) {
            maxm2 = curmax;
            s2 = curs;
        } else if (curmax == maxm2) {
            s2 = max(s2, curs);
        }
    }
    return dp[idx][1] = {maxm2, s2};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string a, b; double s;
        cin >> a >> s >> b;
        if (!m1.count(a)) {
            m1[a] = id++;
        }
        if (!m1.count(b)) {
            m1[b] = id++;
        }
        v[m1[b]].push_back(m1[a]);
        ss[m1[a]] = s;
    }

    int ceo = m1["CEO"];
    int src = v[ceo][0];

    auto p = search(src, 1);
    cout << setprecision(10);
    cout << p.first << ' ' << p.second / p.first << endl;
}
