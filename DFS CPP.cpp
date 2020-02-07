#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<int, vector<int>> m;

// using a stack

int min_dis = 0;
vector<vector<bool>> vis;
vector<vector<int>> g;
vector<vector<int>> dis;
vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


void dfs(int i, int j, int k)  {
    if (vis[i][j] == true)
        return;
    else {
        if (g[i][j] == 2)
            dis[i][j] = 0;
        
        else if (g[i][j] == 1)
            dis[i][j] = min(dis[i][j], k);
        
        else
            return;
        
        for (auto dir : direction) {
            dfs(i + dir[0], j + dir[1], k + 1);
        }
    }
    return;
}

int maxTimeTraversal(vector<vector<int>>& graph) {
    long r = graph.size();
    long c = graph[0].size();
        
    // for output
    vector<vector<bool>> tmp(r, vector<bool>(c, false));
    vis = tmp;
    
    vector<vector<int>> temp(r, vector<int>(c, INT_MAX));
    dis = temp;
    
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 2)
                dfs(i, j, 0);
            
        }
    }
    
    int maxm = 0;
    
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++) {
            
            if (dis[i][j] == INT_MAX && g[i][j] == 1)
                return -1;
            maxm = max(maxm, dis[i][j]);
        }
    }
    
    return maxm;
}

int main() {
    
    int r, c;
    cin >> r >> c;
    
    
    vector<vector<int>> tmp(r, vector<int>(c));
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> tmp[i][j];
        }
    }
    
    g = tmp;
    cout << maxTimeTraversal(g);
    
    return 0;
}
