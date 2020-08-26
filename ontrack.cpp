#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int traverse(vector<vector<int>> &g, int cur, int parent) {
    int ans = 1;
    for (int v : g[cur]) {
        if (v == parent) continue;
        ans += traverse(g, v, cur);
    }

    return ans;
}

int main() {
    int n, x, y;
    scanf("%d", &n);

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; ++i) {
       scanf("%d %d", &x, &y); 
       g[x].push_back(y);
       g[y].push_back(x);
    }

    ull cost = 0;
    ull best = 0;

    for (int i = 0; i < n + 1; ++i) {
        if (!g[i].size()) continue;
        // try this node as the split
        vector<int> nums;
        for (int v : g[i]) {
            nums.push_back(traverse(g, v, i));
        }
        ull cur_cost = 0;
        int summation = n;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            summation -= num;
            cur_cost += num * summation;
        }
        if (cur_cost > cost) {
            cost = cur_cost;
            // calculate the salvaged cost
            if (nums.size() > 1)
                best = cost - *(nums.end() - 1) * *(nums.end() - 2);
            else
                best = 0;
        }
    }
    printf("%d %d", cost, best);
}