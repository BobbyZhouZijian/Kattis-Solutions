#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, t;
    scanf("%d %d", &n, &t);
    vector<vector<int>> g(n, vector<int>(3));
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d %d %d", &g[i][0], &g[i][1], &g[i][2]);
    }

    double lo = 0, hi = t;
    for (int k = 0; k < 100; ++k)
    {
        double c = (lo + hi) / 2;
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            double f = c * g[i][2];

            if (f > g[i][1]) f = g[i][1];
            if (f < g[i][0]) f = g[i][0];

            sum += f;
        }

        if (sum > t)
            hi = c;
        else
            lo = c;
    }

    double c = lo;
    for (int i = 0; i < n; ++i)
    {
        double f = c * g[i][2];
        if (f > g[i][1]) f = g[i][1];
        if (f < g[i][0]) f = g[i][0];

        printf("%.10f\n", f);
    }
}