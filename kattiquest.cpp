#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main(int argc, char const *argv[])
{
    fast();

    int n;
    cin >> n;
    multimap<int, int> q;
    q.insert({1e9, 0});

    while (n--) {
        string type;
        cin >> type;

        if (type == "add") {
            int e, g;
            cin >> e >> g;
            q.insert({e, g});
        }

        else {
            int x;
            long long reward = 0;
            cin >> x;
            multimap<int, int>::iterator it;

            while(!q.empty() && (*q.begin()).first <= x) {	
            	
            	it = prev(q.upper_bound(x));
            	auto p = *it;
            	x -= p.first;
            	reward += p.second;
            	q.erase(it);
            }

            cout << reward << endl;
            
        }
    }
    return 0;
}