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
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define ft first
#define sd second

ll f[1010];

ll ncr[1010][1010];

ll solve(ll n, ll r)
{
    if (n == r || r == 0)
        return 1;

    if (ncr[n][r] != -1)
        return ncr[n][r];

    ncr[n][r] = (solve(n-1, r-1) + solve(n-1, r))%10056;
    return ncr[n][r];
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    memset(ncr, -1, sizeof(ncr));

    f[0] = f[1] = 1;

    for (i = 2; i <= 1000; i++)
    {
        for (j = 1; j <= i; j++)
        {
            f[i] = (f[i] + (solve(i, j)*f[i-j])%10056)%10056;
        }
    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        printf("Case %lld: %lld\n", cs, f[n]);
    }

    return 0;
}
