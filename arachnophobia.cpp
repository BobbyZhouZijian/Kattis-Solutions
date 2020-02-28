#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll inf = (ll)1 << 62;
ll n, m, t, s_ptr, e_ptr;

bool path(vector< vector< pair<ll, ll> > >& adj, ll dist, vector<ll>& distspider) {
    if (distspider[e_ptr] < dist) return false;
    if (distspider[s_ptr] < dist) return false;

    vector<bool> vis(n, false);
    for(ll i = 0; i < n; ++i) {
        if (distspider[i] < dist) vis[i] = true;
    }

    vector<ll> best(n, inf);
    best[s_ptr] = 0;

    priority_queue< pair<ll, ll> > q;
    q.push({0, s_ptr});

    while(!q.empty()) {
        ll cur = q.top().second;
        q.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for(auto& p : adj[cur]) {
            ll next = p.first, w = p.second;
            if (!vis[next] && best[next] > best[cur] + w) {
                best[next] = best[cur] + w;
                q.push({-best[next], next});
            }
        }
    }

    return best[e_ptr] <= t;
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n >> m >> t;
    vector< vector< pair<ll, ll> > > adj(n);
    for(ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> s_ptr >> e_ptr;

    ll num_spiders;
    cin >> num_spiders;
    vector<ll> spiders(num_spiders);

    for(auto& i : spiders) cin >> i;

    vector<ll> distspiders(n, inf);
    vector<bool> visit(n, false);

    priority_queue< pair<ll, ll> > q;

    for(auto i : spiders) {
        distspiders[i] = 0;
        q.push({0, i});
    }

    while(!q.empty()) {
        ll cur = q.top().second;
        q.pop();

        if (visit[cur]) continue;
        visit[cur] = true;

        for(auto& p : adj[cur]) {
            ll next = p.first, w = p.second;
            if (distspiders[next] > distspiders[cur] + w) {
                distspiders[next] = distspiders[cur] + w;
                q.push({-distspiders[next], next});
            }
        }
    }

    ll lo = 0, hi = inf, ans = 0;

    // for (auto i : distspiders) cout << i << " ";

    cout << endl;

    while(lo <= hi) {
        // cout << "loop currently at: " << lo << " " << hi << endl;
        ll mid = lo + (hi - lo) / 2;
        if (path(adj, mid, distspiders)) {
            lo = mid + 1;
            ans = max(ans, mid);
        } else {
            hi = mid - 1;
        }
    }

    cout << ans;
}