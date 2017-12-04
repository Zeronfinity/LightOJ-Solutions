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

ll px[20], py[20], pre[20][20], n, dp[65537];

ll solve(ll mask)
{
    ll i, cn = 0, nz;
    for (i = 0; i < n; i++)
    {
        if ( (mask & (1 << i)) != 0 )
            cn++;
        else nz = i;
    }

   // cout << "a " << mask << " " << cn << " " << n << endl;

    if (cn == n)
        return 0;

    if (cn == n - 1)
        return 1;

    if (dp[mask] != -1)
        return dp[mask];

    ll ans = INT_MAX;

    for (i = 0; i < n; i++)
    {
        if (i != nz && (mask & (1<<i)) == 0)
        {
  //          cout << "b " << i << " " << nz << " " << mask << " " << solve(mask | pre[nz][i]) << " " << ans << endl;
            ans = min(ans, solve(mask | pre[nz][i]) + 1);
        }
    }

  //  cout << "c " << mask << " " << ans << endl;

    return dp[mask] = ans;
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
            sl(px[i]);
            sl(py[i]);
        }

        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
            {
                ll mask = 0;
                for (k = 0; k < n; k++)
                {
                    ll area = px[i]*(py[j] - py[k]) + px[j]*(py[k] - py[i]) + px[k]*(py[i] - py[j]);

                    if (area == 0)
                    {
                        mask = mask | (1 << k);
                    }
                }

                pre[i][j] = pre[j][i] = mask;
            }

        for (i = 0; i < (1 << n); i++)
            dp[i] = -1;

        printf("Case %lld: %lld\n", cs, solve(0));
    }

    return 0;
}
