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

#define md 100000007

ll a[52], c[52], n, k, dp[52][1005], cn;

ll ksack(ll i, ll w)
{
    if (i == n+1)
    {
        if (w == 0)
        {
            return 1;
        }
        else return 0;
    }

    if (w == 0)
        return 1;

    if (w < 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    ll p1 = 0, p2 = 0, tk;

    for (tk = 1; tk <= c[i] && w - a[i]*tk >= 0; tk++)
        p1 = (p1 + ksack(i+1, w - a[i]*tk))%md;

    p2 = ksack(i + 1, w);


    dp[i][w] = (p1 + p2)%md;
    return dp[i][w];
}

int main ()
{
    ll cs, t, i, j, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

        cn = 0;

        memset(dp, -1, sizeof(dp));


        for (i = 1; i <= n; i++)
            sl(a[i]);

        for (i = 1; i <= n; i++)
            sl(c[i]);

        ans = ksack(1, k);


        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
