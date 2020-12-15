#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> disjoint;
vector<set<int>> sets;
vector<ll> sums;

void move(int p, int q) {
    int idp = disjoint[p];
    int idq = disjoint[q];
    if (idp == idq) return;
    sets[idp].erase(p);
    sums[idp] -= p;
    sets[idq].insert(p);
    sums[idq] += p;
    disjoint[p] = idq;
}

void join(int p, int q) {
    int idp = disjoint[p];
    int idq = disjoint[q];
    if (idp == idq) return;
    if (sets[idp].size() < sets[idq].size()) {
        for (int i : sets[idp]) {
            disjoint[i] = idq;
            sets[idq].insert(i);
        }
        sets[idp].clear();
        sums[idq] += sums[idp];
        sums[idp] = 0;
    } else {
        for (int i : sets[idq]) {
            disjoint[i] = idp;
            sets[idp].insert(i);
        }
        sets[idq].clear();
        sums[idp] += sums[idq];
        sums[idq] = 0;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;

    while (cin >> n && cin >> m) {
        disjoint.clear(); sets.clear(); sums.clear();
        disjoint.resize(n + 1);
        sets.resize(n + 1);
        sums.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            disjoint[i] = i;
            sets[i].insert(i);
            sums[i] = i;
        }

        int op, p, q;
        for (int i = 0; i < m; ++i) {
            cin >> op;

            // union
            if (op == 1) {
                cin >> p >> q;
                join(p, q);
            }

            // move
            else if (op == 2) {
                cin >> p >> q;
                move(p, q);
            }

            // query
            else {
                cin >> p;
                int idp = disjoint[p];
                cout << sets[idp].size() << " " << sums[idp] << endl;
            }
        }
    }
}