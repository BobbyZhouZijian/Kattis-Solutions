#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;
const int MAXM = 155;
int TC;
int n, m;

struct bundle {
    int cost;
    vector<int> items;

    bool operator<(bundle &other) const {
        if (items.size() == other.items.size()) {
            return items < other.items;
        }
        return items.size() < other.items.size();
    }

    bool operator==(bundle &other) const {
        return items == other.items;
    }
} bundles[MAXM], b2[MAXM];

int best[MAXM];
vector<int> contains[MAXM];

void search(int x) {
    best[x] = b2[x].cost;

    unordered_set<int> parts;
    for (int j : b2[x].items) {
        int f = lower_bound(contains[j].begin(), contains[j].end(), x) - contains[j].begin();
        if (f == 0) {
            return;
        }
        parts.insert(contains[j][f-1]);
    }

    int res = 0;
    for (int i : parts) {
        res += best[i];
    }
    best[x] = min(best[x], res);
}

void solve() {
    cin >> n >> m;
    memset(best, -1, sizeof best);
    for (int i = 0; i < m; ++i) {
        int c, num;
        cin >> c >> num;
        bundles[i].cost = c;
        bundles[i].items.clear();
        for (int j = 0; j < num; ++j) {
            int x; cin >> x;
            bundles[i].items.push_back(x-1);
        }
        sort(bundles[i].items.begin(), bundles[i].items.end());
    }
    
    // sentinel
    bundles[m].cost = INF;
    bundles[m].items.clear();
    for (int i = 0; i < n; ++i) {
        bundles[m].items.push_back(i); 
    }
    m++;
    sort(bundles, bundles + m);

    // remove duplicates
    int k = 0;
    for (int i = 0; i < m;) {
        int j = i+1;
        for (; j < m && bundles[i] == bundles[j]; ++j) {
            bundles[i].cost = min(bundles[i].cost, bundles[j].cost);
        }
        b2[k++] = bundles[i];
        i=j;
    }
    m = k;

    for (int i = 0; i < n; ++i) {
        contains[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        for (int b : b2[i].items) {
            contains[b].push_back(i);
        }
    }

    for (int i = 0; i < m; ++i) {
        search(i);
    }

    cout << best[m-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> TC;
    while (TC--)
        solve();
}
