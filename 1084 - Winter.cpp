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

#define fr first
#define sd second

ll n, k;

ll a[100010], dp[100010];

ll solve(ll pos)
{
    if (pos >= n)
        return 0;

    ll &res = dp[pos];

    if (res != -1)
        return res;

    res = INT_MAX;

    ll x = upper_bound(a, a + n, a[pos] + 2*k) - a;

    if (x - pos >= 3)
        res = 1 + solve(x);

    if (x-1 - pos >= 3)
        res = min(res, 1 + solve(x-1));

    if (x-2 - pos >= 3)
        res = min(res, 1 + solve(x-2));

    if (x-3 - pos >= 3)
        res = min(res, 1 + solve(x-3));

    return res;
}

int main ()
{
  //  freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

        for (i = 0; i < n; i++)
        {
            sl(a[i]);
        }

        sort(a, a+n);

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: %lld\n", cs, (solve(0) >= INT_MAX - 100000?-1:solve(0)));
    }

    return 0;
}
