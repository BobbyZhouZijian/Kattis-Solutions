#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt {
    ll x, y;
    pt(ll a, ll b) : x(a), y(b) {}
};

int n, m;
vector<pt> l,r,l1,r1;

ll ans = 0;

void search(int li, int lj, int ri, int rj) {
    if (li > lj || ri > rj) return;
    int lmid = (li + lj) / 2;
    ll curmax = 0;
    int maxid = -1;
    for (int i = ri; i <= rj; ++i) {
        ll diffx = r1[i].x - l1[lmid].x;
        ll diffy = r1[i].y - l1[lmid].y;
        if (diffx <= 0 || diffy <= 0) continue;
        ll cur = diffx * diffy;
        if (cur > curmax) {
            maxid = i;
            curmax = cur;
        }
    }

    if (curmax > ans)
        ans = curmax;

    if (maxid == -1) {
        maxid = rj;
        for (int i = ri; i <= rj; ++i) {
            if (r1[i].x >= l1[lmid].x) {
                maxid = i;
                break;
            }
        }
    }

    search(li, lmid - 1, ri, maxid);
    search(lmid + 1, lj, maxid, rj);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        l.push_back(pt(x, y));
    }

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        r.push_back(pt(x, y));
    }

    auto cmp1 = [](pt p1, pt p2) {
        if (p1.x == p2.x)
            return p1.y < p2.y;
        return p1.x < p2.x;
    };
    sort(l.begin(), l.end(), cmp1);

    for (int i = 0; i < m; ++i) {
        if (l1.size() == 0) {
            l1.push_back(l[i]);
            continue;
        }
        if (l[i].x >= l1.back().x && l[i].y >= l1.back().y)
            continue;
        l1.push_back(l[i]);
    }
    
    auto cmp2 = [](pt p1, pt p2) {
        if (p1.x == p2.x)
            return p1.y > p2.y;
        return p1.x > p2.x;
    };
    sort(r.begin(), r.end(), cmp2);

    for (int i = 0; i < n; ++i) {
        if (r1.size() == 0) {
            r1.push_back(r[i]);
            continue;
        }
        if (r[i].x < l1[0].x) continue;
        if (r[i].x <= r1.back().x && r[i].y <= r1.back().y)
            continue;
        r1.push_back(r[i]);
    }

    reverse(r1.begin(), r1.end());

    search(0, l1.size()-1, 0, r1.size()-1);

    cout << ans << endl;
}

