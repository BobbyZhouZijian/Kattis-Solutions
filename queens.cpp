#include <iostream>
#include <vector>

using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool ok(int x1, int y1, int x2, int y2) {
    return x1 != x2 
        && x2 != y2
        && (x1 - x2) != (y1 - y2)
        && (x1 - x2) != (y2 - y1);
}

int main() {

    fast();

    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }   

    for(int i = 0; i < n; ++i) {
        int curx = v[i].first, cury = v[i].second;
        for(int j = 0; j < n; ++j) {
            if(j == i) continue;
            int compx = v[j].first, compy = v[j].second;
            if(!ok(curx, cury, compx, compy)) {
                cout << "INCORRECT";
                return 0;
            }
        }
    }

    cout << "CORRECT";
}