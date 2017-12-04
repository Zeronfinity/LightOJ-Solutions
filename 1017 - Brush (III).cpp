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

ll n, ar[110], w, dp[110][110];

ll solve(ll i, ll k)
{
    if (i >= n)
        return 0;

    if (k == 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    ll u = ar[i] + w;

    ll x = upper_bound(ar, ar + n, u) - ar;

    ll y = x - i;

    ll p = solve(x, k - 1) + y;
    ll q = solve(i + 1, k);

    return dp[i][k] = max(p, q);
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
        sl(w);
        sl(k);

        for (i = 0; i <= n; i++)
            for (j = 0; j <= k; j++)
                dp[i][j] = -1;

        for (i = 0; i < n; i++)
        {
            sl(x);
            sl(ar[i]);
        }

        sort(ar, ar + n);

        printf("Case %lld: %lld\n", cs, solve(0, k));
    }

    return 0;
}
