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
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

ll U[505][505], R[505][505];

ll dp[505][505];

ll solve(ll i, ll j)
{
    if (i < 1 || j < 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = max(solve(i-1, j) + U[i][j], solve(i, j-1) + R[i][j]);
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
        sl(m);

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                sl(x);
                U[i][j] = U[i][j-1] + x;
            }

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                sl(x);
                R[i][j] = R[i-1][j] + x;
            }
        memset(dp, -1, sizeof(dp));
        printf("Case %lld: %lld\n", cs, solve(n, m));
    }

    return 0;
}
