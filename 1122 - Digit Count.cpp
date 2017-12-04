#include <stdio.h>
#include <climits>
#include <iostream>
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

bool dig[10];

ll dp[12][15][2];

ll solve(ll n, ll prev, bool started)
{
    if (n == 0)
        return 1;

    ll i, ans = 0;

    if (dp[n][prev][started] != -1)
        return dp[n][prev][started];

    for (i = 0; i <= 9; i++)
    {
        if (started == 0)
        {
            if (dig[i] == 1)
            {
                ans += solve(n-1, i, i == 0? 0 : 1); //+ (i != 0? 1 : 0);
            }
        }
        else
        {
            if (dig[i] == 1 && fabs(i - prev) <= 2)
            {
                ans += solve(n-1, i, started);// + 1;
            }
        }
    }

    return dp[n][prev][started] = ans;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, p, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(m);
        sl(n);

        memset(dig, 0, sizeof(dig));

        while (m--)
        {
            sl(x);
            dig[x] = 1;
        }

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: %lld\n", cs, solve(n, 14, 0));
    }

    return 0;
}
