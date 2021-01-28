#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    while (scanf("%d", &n)) {
        if( n == 0 ) break;
        ll arr[12];
        for (int i =0; i < n; ++i){
            scanf("%lld", &arr[i]);
        }
        ll x, y;
        scanf("%lld %lld", &x, &y);
        vector<ll> res {1};
        int ptrs[12] = {0};
        ll minm = 1;
        bool have = false;
        bool prev =false;
        while (1) {
            if (minm > y) break;
            if (minm >= x) {
                have = true;
                if (prev) printf(","); 
                else prev = true;
                printf("%lld", minm);
            }
            
            ll next = 1e16;
            for (int i = 0; i < n; ++i) {
                ll cur = res[ptrs[i]] * arr[i];
                if (cur < next) { 
                    next = cur;
                }
            }

            minm = next;
            res.push_back(minm);
            for (int i = 0; i < n; ++i) {
                if (res[ptrs[i]] * arr[i] == next) {
                    ptrs[i]++;
                }
            }

        }
        if (!have) {
            printf("none");
        }
        printf("\n");
    }
}
