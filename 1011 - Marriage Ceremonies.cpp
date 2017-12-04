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

ll n, ar[20][20], dp[17][66000], vis[17][66000];

ll trick = 1;

ll solve(ll pos, ll mask)
{
    if (pos >= n)
        return 0;

    if (vis[pos][mask] == trick)
        return dp[pos][mask];

    ll ret1 = 0;

    for (ll i = 0; i < n; i++)
    {
        if ( (mask & (1LL << i)) == 0 )
            ret1 = max(ret1, solve(pos + 1, mask | (1LL << i)) + ar[pos][i]);
    }

    vis[pos][mask] = trick;
    return dp[pos][mask] = ret1;
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
            for (j = 0; j < n; j++)
                sl(ar[i][j]);

        ans = solve(0, 0);

        trick++;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
