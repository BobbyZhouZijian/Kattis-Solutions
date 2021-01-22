#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}



int main() {
    fast();
    ll n;
    while (cin>>n){
        if(n==0)break;
        ll t=n;
        int sum=0;
        while(t) {
            sum += t%10;
            t/=10;
        }
        for(ll m=11; ;++m) {
            ll a=n*m;
            int cur=0;
            while(a) {
                cur+=a%10;
                a/=10;
            }
            if(cur==sum){
                cout << m << endl;
                break;
            }
        }
    }


    return 0;
}
