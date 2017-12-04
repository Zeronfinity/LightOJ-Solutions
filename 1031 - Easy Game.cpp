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

ll ar[200], dp[110][110][2];
bool vis[110][110][2];

ll solve(ll i, ll j, bool player)
{
    if (i > j)
        return 0;

    if (vis[i][j][player] == 1)
        return dp[i][j][player];

    vis[i][j][player] = 1;



    ll k, sum, ans;

    sum = 0;

    for (k = i; k <= j; k++)
    {
        sum += ar[k];
        if (player == 0)
        {
            if (k == i)
                ans = sum + solve(k+1, j, (player+1)%2);
            else ans = max(ans, sum + solve(k+1, j, (player+1)%2) );
        }
        else
        {
            if (k == i)
                ans = solve(k+1, j, (player+1)%2) - sum;
            else ans = min(ans, solve(k+1, j, (player+1)%2) - sum);
        }
    }

    sum = 0;

    for (k = j; k >= i; k--)
    {
        sum += ar[k];
        if (player == 0)
        {
            ans = max(ans, sum + solve(i, k-1, (player+1)%2) );
        }
        else
        {
            ans = min(ans, solve(i, k-1, (player+1)%2) - sum);
        }
    }

    return dp[i][j][player] = ans;
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

        for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
        }

        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                vis[i][j][0] = vis[i][j][1] = 0;

        ans = solve(1, n, 0);

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
