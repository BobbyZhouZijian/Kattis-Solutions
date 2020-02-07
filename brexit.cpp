#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;


int main () {
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    map< int, vector<int> > m;
    vector<int> tot(c + 1, 0);
    vector<int> mv(c + 1, 0);
    vector<bool> left(c + 1, false);
    bool leave = false;


    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        m[a].push_back(b);
        m[b].push_back(a);
        tot[a]++;
        tot[b]++;
    }

    queue<int> q;
    q.push(l);
    left[l] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == x) {
            leave = true;
            break;
        }

        for (auto nb : m[curr]) {
            mv[nb]++;

            if (!left[nb] && mv[nb] * 2 >= tot[nb]) {
                left[nb] = true;
                q.push(nb);
            }
        }
    }

    if (leave) cout << "leave";
    else cout << "stay";
}