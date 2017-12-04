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

ll n, dp[1010][2][2], soap[1010];

ll solve(ll i, ll x, ll f)
{
    if (i == n)
    {
        if (x == 1 || f == 1)
            return 0;
        else return soap[i];
    }

  //  cout << "a " << i << " " << w << " " << r[i] << " " << g[i] << " " << b[i] << " " << x << " " << dp[i][x] << endl;


    if (dp[i][x][f] != -1)
    {
        return dp[i][x][f];
    }


    if (x != 1)
    {
        dp[i][x][f] = solve(i + 1, 1, i == 1? 1 : f) + soap[i];
    }

    dp[i][x][f] = max(dp[i][x][f], solve(i+1, 0, f));

    //  cout << "b " << i << " " << x << " " << dp[i][x] << endl;


    return dp[i][x][f];
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
            sl(soap[i]);
        }

        memset(dp, -1, sizeof(dp));

        ans = 0;

        ans = solve(1, 0, 0);

      //  for (i = 1; i <= n; i++)
        //    ans = max(ans, solve(i, 0, i==1?n:i-1));

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
