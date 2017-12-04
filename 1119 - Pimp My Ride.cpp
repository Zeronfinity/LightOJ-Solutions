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

ll shop[15][15], n;

ll dp[15][16400];

ll solve(ll i, ll mask)
{
   // cout << "a " << i << " " << mask << endl;
    if (mask == (1LL << n) - 1)
        return 0;

    if (dp[i][mask] != -1)
        return dp[i][mask];

    ll ans = 0, p = LLONG_MAX;

   // cout << "d " << i << " " << mask << endl;


    for (ll j = 0; j < n; j++)
    {
        if (i == j)
        {
            ans += shop[i][j];
        }
        else
        {
            if ( (mask & (1LL << j)) != 0 )
                ans += shop[i][j];
        }
    }

    for (ll j = 0; j < n; j++)
        if (i != j && (mask & (1LL << j)) == 0 )
        {
            p = min( p, solve(j, mask | (1<<i)) );
          //  cout << "b " << i << " " << mask << " " << j << " " << p << endl;
        }

    if (p == LLONG_MAX)
        p = 0;

    return dp[i][mask] = ans + p;
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
        {
            for (j = 0; j < n; j++)
            {
                sl(shop[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));

        ans = LLONG_MAX;

        for (i = 0; i < n; i++)
        {
            ans = min( ans, solve(i, 0) );
         //   cout << i << " " << ans << endl;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
