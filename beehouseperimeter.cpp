#include <bits/stdc++.h>
using namespace std;

int r, k;
map<int, bool> m;
vector<vector<int>> g, vis;

int cnt = 0;

void dfs(int i, int j)
{
    if (i < 0 || i > 2 * r || j < 0
     || j > 2 * r || vis[i][j] || m[g[i][j]]) return;
    vis[i][j] = 1;

    if (i > 0 && m[g[i-1][j]]) cnt++;
    if (i < 2*r && m[g[i+1][j]]) cnt++;
    if (j > 0 && m[g[i][j-1]]) cnt++;
    if (j < 2*r && m[g[i][j+1]]) cnt++;
    if (i > 0 && j>0 && m[g[i-1][j-1]]) cnt++;
    if (i<2*r && j<2*r && m[g[i+1][j+1]]) cnt++;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i-1,j-1);
    dfs(i+1,j+1);
}

int main()
{
    scanf("%d %d", &r, &k);

    int rep = 0, cur;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &cur);
        m[cur] = 1;
    }
    
    g.resize(2 * r + 1, vector<int>(2 * r + 1));
    vis.resize(2 * r + 1, vector<int>(2 * r + 1));
    int num = 1;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j < r + i; ++j)
        {
            g[i][j] = num;
            num++;
        }
    }
    for (int i = r + 1; i < 2 * r; ++i)
    {
        for (int j = i - r + 1; j < 2 * r; ++j)
        {
            g[i][j] = num;
            num++;
        }
    }

    dfs(0,0);

    printf("%d\n", cnt);
}