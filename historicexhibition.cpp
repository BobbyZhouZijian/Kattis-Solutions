#include <bits/stdc++.h>
using namespace std;

int p, v;
unordered_map<int, unordered_set<int>> m;
vector<bool> vis;
vector<int> match;
vector<int> vases;

int aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : m[vases[L]]) {
        if (match[R] == -1 || aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d",&p,&v);
    if (p < v) {
        printf("impossible\n");
        return 0;
    }
    int a, b;
    for (int i = 0; i < p; ++i) {
        scanf("%d%d",&a,&b);
        m[a].insert(i);
        m[b].insert(i);
    }

    match.resize(p+1,-1);
    vases.resize(v+1);
    for (int i = 0; i < v; ++i) {
        scanf("%d",&vases[i]);
    }

    unordered_set<int> freeV;
    int res = 0;
    for (int L = 0; L < v; ++L) {
        freeV.insert(L);
    }
    for (int L = 0; L < v; ++L) {
        vector<int> candidates;
        for (auto &R : m[vases[L]]) {
            if (match[R] == -1)
                candidates.push_back(R);
        }
        if ((int)candidates.size() > 0) {
            res++;
            freeV.erase(L);
            int a = rand()%(int)candidates.size();
            match[candidates[a]] = L;
        }
    }

    for (auto &i : freeV) {
        vis.assign(v+1,false);
        res += aug(i);
    }

    if (res < v)
        printf("impossible\n");
    else {
        vector<pair<int,int>> out;
        for (int i = 0 ; i < p; ++i) {
            if (match[i] == -1) continue;
            out.push_back({match[i], i}); 
        }
        sort(out.begin(), out.end());
        for (auto &p : out) printf("%d\n", p.second+1);
    }
}
