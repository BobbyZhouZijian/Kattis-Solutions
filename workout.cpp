#include <bits/stdc++.h>
using namespace std;

#define N 100
typedef long long ll;

const int n = 10;
ll U[N], R[N], u[N], r[N], t[N];

int main()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", U + i, R + i);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld %lld", u + i, r + i, t + i);
    }
    // main loop
    ll ans = 0; 
    for (int k = 0; k < 3; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            // no one taking the machine right now
            if (ans < t[i])
            {
                // do work immediately on the machine
                t[i] = max(t[i], ans + U[i]);
                ans += R[i] + U[i];
            }

            // the machine start time not updated yet
            else
            {
                // update it
                int reps = (ans - t[i]) / (r[i] + u[i]);
                t[i] += reps * (r[i] + u[i]) + u[i];
                
                // still in use
                if (ans < t[i])
                {
                    ans = t[i] + U[i] + R[i];
                }
                // immediately available
                else
                {
                    ans += U[i] + R[i];
                }
                t[i] = max(ans - R[i], t[i] + r[i]);
            }
        }
    }
    printf("%lld", ans - R[n - 1]);
}