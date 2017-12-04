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

#define ll unsigned long long
#define sl(n) scanf("%llu", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;
    return gcd(b, a%b);
}

ll pwr(ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(p/2);

    if (p%2 == 0)
        return x*x;
    else return x*x*6;
}

ll dp[25][150];

ll solve(ll n, long long x)
{
    if (n == 0)
    {
        if (x <= 0)
            return 1;
        else return 0;
    }

    if (dp[n][x] != -1)
        return dp[n][x];

    ll p = 0;

    for (ll i = 1; i <= 6; i++)
    {
        if (x >= i)
            p += solve(n-1, x - i);
        else
            p += pwr(n-1);
    }

    return dp[n][x] = p;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, p, gc;

    memset(dp, -1, sizeof(dp));

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(x);
        p = solve(n, x);
        q = pwr(n);

        gc = gcd(p, q);

        p /= gc;
        q /= gc;

        if (q == 1)
            printf("Case %lld: %llu\n", cs, p);
        else if (p == 0)
            printf("Case %lld: 0\n", cs);
        else
            printf("Case %lld: %llu/%llu\n", cs, p, q);
    }

    return 0;
}
