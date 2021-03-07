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

int n;
int arr[1000005];

int main() {
    fast();
    scanf("%d",&n);


    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    if (sum % 3 != 0) {
        printf("%d\n",-1);
        return 0;
    }

    ll each = sum / 3;
    ll sec1 = 0, sec2 = 0, sec3 = 0;
    int k = -1, j = -1;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (k < 0) {
            sec1 += arr[i];
            if (sec1 == each) {
                k = i;
            } else if (sec1 > each) {
                printf("%d",-1);
                return 0;
            }
        } else if (j < 0) {
            sec2 += arr[i];
            if (sec2 == each) {
                j = i;
            } else if (sec2 > each) {
                printf("%d",-1);
                return 0;
            }
        } else {
            sec3 += arr[i];
        }
    }
    if (sec3 == each) {
        k++;
        j++;
        printf("%d %d\n", k, j);
    } else {
        printf("%d\n",-1);
        return 0;

    }
    return 0;
}

