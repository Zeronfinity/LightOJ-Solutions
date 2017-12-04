#include <stdio.h>
#include <iostream>
#include <climits>
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
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define ft first
#define sd second

int res[53];

ll dp[53][2];

ll ddp(ll i, ll prev)
{
    if (i > 50)
        return 1;

    if (dp[i][prev] != -1)
        return dp[i][prev];

    ll p = ddp(i + 1, 0), q = 0;
    if (prev == 0)
        q = ddp(i + 1, 1);

    return dp[i][prev] = p + q;
}

void solve(ll i, ll n, ll isStarted)
{
    if (i > 50)
        return ;

    ll x, y;

    res[i] = 0;
    memset(dp, -1, sizeof(dp));
    x = ddp(i + 1, 0);
    if (isStarted == 0)
        x--;
    if (x >= n)
    {
        solve(i + 1, n, isStarted);
        return ;
    }

    res[i] = 1;
    solve(i + 1, n - x, 1);
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

//        n++;

        solve(0, n, 0);

        printf("Case %lld: ", cs);

        x = 0;

        for (i = 0; i <= 50; i++)
        {
            if (res[i] == 1 && x == 0)
            {
                printf("%d", res[i]);
                x = 1;
                continue;
            }

            if (x == 1)
            {
                printf("%d", res[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
