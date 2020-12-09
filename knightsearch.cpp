#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> g;

const string need = "ICPCASIASG";

bool dfs(int i, int j, string cur)
{
    cur += g[i][j];
    if (cur == need) return true;
    int len = cur.length();
    if (len >= 10) return false;

    bool can = false;
    if (i > 1 && j < n - 1 && g[i - 2][j + 1] == need[len]) can |= dfs(i - 2, j + 1, cur);
    if (i < n - 2 && j < n - 1 && g[i + 2][j + 1] == need[len]) can |= dfs(i + 2, j + 1, cur);
    if (i > 1 && j > 0 && g[i - 2][j - 1] == need[len]) can |= dfs(i - 2, j - 1, cur);
    if (i < n - 2 && j > 0 && g[i + 2][j - 1] == need[len]) can |= dfs(i + 2, j - 1, cur);
    if (i > 0 && j < n - 2 && g[i - 1][j + 2] == need[len]) can |= dfs(i - 1, j + 2, cur);
    if (i < n - 1 && j < n - 2 && g[i + 1][j + 2] == need[len]) can |= dfs(i + 1, j + 2, cur);
    if (i > 0 && j > 1 && g[i - 1][j - 2] == need[len]) can |= dfs(i - 1, j - 2, cur);
    if (i < n - 1 && j > 1 && g[i + 1][j - 2] == need[len]) can |= dfs(i + 1, j - 2, cur);

    return can;
}

int main()
{
    scanf("%d\n", &n);
    g.resize(n, vector<char>(n));

    vector<pair<int, int>> starts;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%c", &g[i][j]);
            if (g[i][j] == 'I')
                starts.push_back({i, j});
        }
    }

    for (auto p : starts)
        if (dfs(p.first, p.second, ""))
        {
            printf("YES\n");
            return 0;
        }
    
    printf("NO\n");
}