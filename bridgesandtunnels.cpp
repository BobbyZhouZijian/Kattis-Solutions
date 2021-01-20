#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

struct HASH {
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};

class UnionFind{
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N,0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N,0);
        setSize.assign(N,1);
        numSets=N;
    }

    int findSet(int i) { return(p[i]==i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i,j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int N;

int main() {
    fast();
    cin >> N;
    unordered_map<string, int> m;
    int id = 1;
    UnionFind uf(N*2+5);
    for (int i = 0; i < N; ++i) {
        string s1,s2; cin>> s1 >> s2;
        if (!m.count(s1)) {
            m[s1] = id++;
        }
        if (!m.count(s2)) {
            m[s2] = id++;
        }
        uf.unionSet(m[s1], m[s2]);
        cout << uf.sizeOfSet(m[s1]) << "\n";
    }

    return 0;
}
