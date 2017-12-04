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

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back


ll ar[105], n;

ll dp[105][105][105];

ll solve(ll i, ll l, ll r)
{
    if (i > n)
        return 0;

  //  cout << i << " " << l << " " << r << " " << dp[i][l][r] << endl;

    if (dp[i][l][r] != -1)
        return dp[i][l][r];

    ll x = 0, y = 0;

    if (ar[l] <= ar[i] && ar[i] <= ar[r])
    {
        x = 1 + solve(i + 1, i, r);
        y = 1 + solve(i + 1, l, i);
    }
   // cout << "b " << x << " " << y << endl;

    return dp[i][l][r] = max(solve(i+1, l, r), max(x,y));
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

        for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
        }
        ar[n+1] = INT_MAX;
        ar[0] = 0;

        for (i = 0; i <= n+2; i++)
            for (j = 0; j <= n+2; j++)
                for (k = 0; k <= n+2; k++)
                    dp[i][j][k] = -1;

        printf("Case %d: %d\n", cs, solve(1, 0, n+1));
    }

    return 0;
}
