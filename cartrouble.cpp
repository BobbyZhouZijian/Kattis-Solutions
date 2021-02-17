#include <bits/stdc++.h>
using namespace std;

int n;
int order[1005];
bool seen[1005];

unordered_map<int, vector<int>> m, m1;

void search(int x) {
    if (seen[x]) return;
    seen[x] = 1;
    for (int v : m[x]) {
        search(v);
    }
}

void search2(int x) {
    if (seen[x]) return;
    seen[x] = 1;
    for (int v : m1[x]) {
        search2(v);
    }
}

int main() {
    scanf("%d",  &n);
    int u, k, v;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &k);
        order[i] = u;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &v);
            m[u].push_back(v);
            m1[v].push_back(u);
        }
    }
    
    memset(seen, 0, sizeof seen);
    search2(0);

    bool ok = true;
    // output trapped
    for (int i = 0; i < n; ++i) {
        if (!seen[order[i]]) {
            ok = false;
            printf("TRAPPED %d\n", order[i]);
        }
    }

    memset(seen, 0, sizeof seen);
    search(0);

    // output unreachable
    for (int i = 0; i < n; ++i ){
        if (!seen[order[i]]) {
            ok = false;
            printf("UNREACHABLE %d\n", order[i]);
        }
    }

    if (ok) printf("NO PROBLEMS\n");
}
