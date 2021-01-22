#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct HASH {
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
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

void solve() {
    char v[11][26];
    int len[11];
    int arr[11] = {0,1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < N; ++i) {
        scanf("%26s", &v[i][0]);
        len[i]=strlen(v[i]);
    }
    int ans = INT_MAX;
    do {
        int cur = 0;
        bool can = true;
        for (int i = 0; i+1< N && can; ++i) {
            int p1=0,p2=0, l1=len[arr[i]], l2 =len[arr[i+1]];
            while(p1<l1&&p2<l2) {
                char c1=v[arr[i]][p1],c2=v[arr[i+1]][p2];
                if (c1<c2)p1++;
                else if (c1>c2)p2++;
                else {
                    p1++;
                    p2++;
                    cur++;
                }
                if (cur>=ans)break;
            }
        }
        ans = min(ans, cur);
    } while (next_permutation(arr, arr+N));

    printf("%d\n", ans);
}

int main() {
    scanf("%d", &N);
    solve();

    return 0;
}
