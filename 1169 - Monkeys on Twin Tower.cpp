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
#define pll pair <long long, long long>
#define pb push_back

ll fr[2][1010], jump[2][1010];

ll dp[2][1010], n;

ll solve(ll x, ll i)
{
    if (i == n)
        return 0;

    if (dp[x][i] != -1)
        return dp[x][i];

    ll a, b;

    a = fr[x][i] + jump[x][i] + solve((x+1)%2, i+1);
    b = fr[x][i] + solve(x, i+1);

    return dp[x][i] = min(a, b);
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < n; i++)
            sl(fr[0][i]);
        for (i = 0; i < n; i++)
            sl(fr[1][i]);

        for (i = 0; i < n-1; i++)
            sl(jump[0][i]);
        for (i = 0; i < n-1; i++)
            sl(jump[1][i]);

        memset(dp, -1, sizeof(dp));
        x = solve(0, 0);
        memset(dp, -1, sizeof(dp));
        y = solve(1, 0);

        printf("Case %lld: %lld\n", cs, min(x, y));
    }

    return 0;
}
