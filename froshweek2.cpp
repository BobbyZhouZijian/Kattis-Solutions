/*
* greedy bipartite matching
*/

#include <bits/stdc++.h>
using namespace std;

int t, l;

int main() {
    scanf("%d%d", &t, &l);
    vector<int> a(t), b(l);
    for (int i = 0; i < t; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < l; ++i) scanf("%d", &b[i]);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int pa=0, pb=0;
    int cnt = 0;
    while (pa<a.size() && pb<b.size()) {
        if (b[pb]>=a[pa]) {
            cnt++;
            pa++;
        }
        pb++;
    }

    printf("%d\n", cnt);
}
