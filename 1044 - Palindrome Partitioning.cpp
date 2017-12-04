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
#define ft first
#define sd second

char s[1010];

ll dp[1010], l;

bool is_pal(ll i, ll j)
{
    ll k, m;
    for (k = i, m = j; k <= j; k++, m--)
    {
        if (s[k] != s[m])
            return false;
    }
    return true;
}

ll solve(ll i)
{
    if (i >= l)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    ll ans = LLONG_MAX;

    for (ll j = i; j < l; j++)
    {
        if (is_pal(i, j))
        {
            ans = min(ans, 1 + solve(j + 1));
        }
    }

    return dp[i] = ans;
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
        ss(s);

        l = strlen(s);

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: %lld\n", cs, solve(0));
    }

    return 0;
}
