#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

ll n, dp[22][5], r[22], g[22], b[22];

ll solve(ll i, ll x)
{
    if (i == n + 1)
    {
        return 0;
    }

  //  cout << "a " << i << " " << w << " " << r[i] << " " << g[i] << " " << b[i] << " " << x << " " << dp[i][x] << endl;


    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }


    if (x == 0)
        dp[i][x] = min(solve(i + 1, 1) + g[i], solve(i + 1, 2) + b[i]);
    if (x == 1)
        dp[i][x] = min(solve(i + 1, 0) + r[i], solve(i + 1, 2) + b[i]);
    if (x == 2)
        dp[i][x] = min(solve(i + 1, 0) + r[i], solve(i + 1, 1) + g[i]);

    //  cout << "b " << i << " " << x << " " << dp[i][x] << endl;


    return dp[i][x];
}

int main ()
{
    ll cs, t, i, j, k, x, y, ans, q, gaba = 35000, pika = 35000, nafu = 35000;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(r[i]);
            sl(g[i]);
            sl(b[i]);
        }

        memset(dp, -1, sizeof(dp));
        gaba = solve(1, 0);
        memset(dp, -1, sizeof(dp));
        pika = solve(1, 1);
        memset(dp, -1, sizeof(dp));
        nafu = solve(1, 2);

        printf("Case %lld: %lld\n", cs, min(gaba, min(pika, nafu)));
    }

    return 0;
}
