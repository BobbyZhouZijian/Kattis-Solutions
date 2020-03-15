#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    int n;
    cin >> n;
    map<int, priority_queue<int>> map;
    while (n--) {
        string action;
        cin >> action;

        if (action == "add") {
            int e, g;
            cin >> e >> g;
            map[e].push(g);
        } else {
            int x;
            cin >> x;
            long sum = 0;
            while (map.size()) {
                auto k = map.lower_bound(x);
                if (k == map.end()) k--;
                while (k != map.begin() && k->first > x) k--;
                if (k->first > x) break;
                sum += k->second.top();
                x -= k->first;
                k->second.pop();

                if (k->second.empty()) map.erase(k);
            }
            cout << sum << endl;
        }
    }
}
