#include <iostream>

using namespace std;
typedef long long ll;

ll n, q;

ll biTree[5000005];

void update(ll index, ll val) {
    index++;

    while (index <= n) {
        biTree[index] += val;
        index += index & (-index);
    }
}

ll get(ll index) {
    ll ans = biTree[0];

    while (index > 0) {
        ans += biTree[index];
        index -= index & (-index);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%lld%lld\n", &n, &q);

    char s;
    ll index, val;
    while(q--) {
        scanf("%c", &s);

        if (s == '+') {
            scanf("%lld%lld\n", &index, &val);
            update(index, val);
        } else {
            scanf("%lld\n", &index);
            printf("%lld\n", get(index));
        }
    }
}