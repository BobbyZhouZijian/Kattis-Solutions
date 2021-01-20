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

int N, K;

void solve(){
    UnionFind uf(N+5);
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        uf.unionSet(x, y);
    }
    bool can = true;
    for (int i = 1; i * 2 <= N; ++i){
        if (!uf.isSameSet(i, N-i+1)) {
            can = false;
            break;
        }
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    fast();
    cin >> N >> K;
    solve();

    return 0;
}
