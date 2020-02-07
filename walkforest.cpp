#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

ll inf = 2147483647;

int main() {
    ll r, c;

    while (cin >> r) {
        if (r == 0) break;
        cin >> c;

        map< ll, vector< pair<ll, ll> > > cnt;
        vector< pair<ll, ll> > edges;

        for (ll i = 0; i < c; i++) {
            ll a, b, d;
            cin >> a >> b >> d;

            cnt[a].push_back(make_pair(d, b));
            cnt[b].push_back(make_pair(d, a));

            edges.push_back(make_pair(a, b));
        }

        //dijkstra

        vector<ll> dis(r + 1, inf);
        vector<bool> vis(r + 1, false);


        dis[2] = 0;

        priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > q;
        q.push(make_pair(0, 2));

        while (!q.empty()) {
            ll i = q.top().second; q.pop();

            for (auto p : cnt[i]) {
                ll w  = p.first;
                ll j = p.second;

                if (!vis[j] && dis[j] > dis[i] + w) {
                    dis[j] = dis[i] + w;
                    q.push(make_pair(dis[j], j));
                }
            }

            vis[i] = true;
        }

        //topo

        vector<ll> indeg(r + 1, 0);

        for (auto p : edges) {
            int a = p.first, b = p.second;

            if (dis[a] < dis[b]) indeg[a] ++;
            else if (dis[a] > dis[b]) indeg[b]++;
        }

        queue<ll> top;

        for (ll i = 2; i <= r; i++) {
            if (indeg[i] == 0) top.push(i);
        }

        while (!top.empty()) {
            ll curr = top.front(); top.pop();

            for (auto i : cnt[curr]) {
                ll nb = i.second;
                if (dis[nb] < dis[curr]) {
                    indeg[nb]--;

                    if (indeg[nb] == 0 && nb != 1)
                        top.push(nb);
                }
            }
        }

        //find
        vector<ll> ans(r + 1, 0);
        ans[1] = 1;

        top.push(1);

        while (!top.empty()) {
            ll n = top.front(); top.pop();

            for (auto i : cnt[n]) {
                ll nb = i.second;
                if (dis[nb] < dis[n]) {
                    indeg[nb]--;
                    ans[nb] += ans[n]; 

                    if (indeg[nb] == 0) top.push(nb);
                }
            }
        }

        cout << ans[2] << endl;
    }
}