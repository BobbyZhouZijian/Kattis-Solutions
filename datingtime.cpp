#include <bits/stdc++.h>
using namespace std;

bool is_valid(int h1, int m1, int h2, int m2, int j, double cur_m)
{
    if (!(cur_m >= 0 && cur_m < 60))
        return false;
    
    if (h1 == h2)
    {
        return m1 <= cur_m && cur_m <= m2;
    }

    return ((j > h1 && j < h2)
            || (j == h1 && cur_m >= m1)
            || (j == h2 && cur_m <= m2));
}

int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int h1, m1, h2, m2, theta;
        scanf("%2d:%2d", &h1, &m1);
        scanf("%2d:%2d", &h2, &m2);
        scanf("%d", &theta);

        int count = 0;
        for (int j = h1; j <= h2; ++j)
        {
            if (theta == 0)
            {
                double cur_m = (30 * (j % 12)) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m))
                    count++;
                continue;
            }
            if (theta == 180)
            {
                double cur_m;
                if ((j % 12) < 6)
                    cur_m = (180 + 30 * (j % 12)) / 5.5;
                else
                    cur_m = (-180 + 30 * (j % 12)) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m))
                    count++;
                continue;
            }

            // theta = 90 degree
            if ((j % 12) < 8)
            {
                double cur_m_1 = (90 + 30 * (j % 12)) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m_1))
                {
                    count++;
                }
            }

            if ((j % 12) > 8)
            {
                double cur_m_2 = (30 * (j % 12) - 270) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m_2))
                {
                    count++;
                }
            }

            if ((j % 12) >= 3)
            {
                double cur_m_3 = (-90 + 30 * (j % 12)) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m_3))
                {
                    count++;
                }
            }

            if ((j % 12) < 3)
            {
                double cur_m_4 = (30 * (j % 12) + 270) / 5.5;
                if (is_valid(h1, m1, h2, m2, j, cur_m_4))
                {
                    count++;
                }
            }
       }
        printf("%d\n", count);
    }
}