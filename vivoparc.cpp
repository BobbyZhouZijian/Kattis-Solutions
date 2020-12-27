#include <iostream>
#include <vector>

using namespace std;

vector<int> assign;
vector<vector<int>> g;
int n;

bool infer(int x) {
    int clrs[5] = {0, 1, 2, 3, 4};
    for (int i : g[x]) {
        clrs[assign[i]] = 0;
    }
    for (int i = 1; i < 5; ++i) {
        if (clrs[i]) {
            assign[x] = i;
            bool can = true;
            for (int j : g[x]) {
                if (assign[j] == 0 && !infer(j)) {
                    can =  false;
                    break;
                }
            }
            if (can) return true;
        }
    }
    assign[x] = 0;
    return false;
}

void backtrack() {
    for (int i = 1; i <= n; ++i) {
        if (assign[i] == 0) {
            infer(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    assign.resize(n + 1, 0);
    g.resize(n + 1);
    int x, y;
    char junk;
    while (cin >> x >> junk >> y) {
        g[x].push_back(y);
        g[y].push_back(x);

        if (cin.eof()) break;
    }

    backtrack();
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << assign[i] << endl;
    }
}