#include <bits/stdc++.h>
using namespace std;

string mapper[7] = {"Twilight Sparkle", "Applejack",
    "Rarity", "Pinkie Pie", "Fluttershy", "Rainbow Dash", "Spike"};
int arr[10][10];
vector<vector<int>> used(7);

int cnt = INT_MAX;
vector<vector<int>> res;

void backtrack(int j) {
    if(j == 7) {
        int maxm = 0;
        for (vector<int> &v : used) maxm = max(maxm, (int)v.size());
        if (maxm < cnt) {
            cnt = maxm;
            res = used;
        }
        return;
    }
    for (int i = 0; i < 7; ++i) {
        if (arr[i][j]) {
            used[i].push_back(j);
            backtrack(j+1);
            used[i].pop_back();
        }
    }
}

int main() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cin >> arr[i][j];
        }
    }

    backtrack(0);

    if (cnt == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cnt << '\n';
        for (int i = 0; i < cnt; ++i) {
            int cur = 0;
            vector<pair<int,int>> out;
            for (int j = 0; j < 7; ++j) {
                if (res[j].size() > i) {
                    cur++;
                    out.push_back({j, res[j][i]+1});
                }
            }
            cout << cur << '\n';
            for (auto p : out) {
                cout << mapper[p.first] << ' ' << p.second << '\n';
            }
        }
    }
}
