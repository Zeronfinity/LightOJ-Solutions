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

ll ncr[1010][1010], fact[1010];

ll mod;

ll ncrsolve(ll n, ll r)
{
    if (n == r || r == 0)
        return 1;

    if (ncr[n][r] != -1)
        return ncr[n][r];

    ncr[n][r] = (ncrsolve(n-1, r-1) + ncrsolve(n-1, r))%mod;
    return ncr[n][r];
}

ll dp[1010][1010];

ll f(ll x, ll y)
{
    if (x == 0)
        return fact[y];

    if (dp[x][y] != -1)
        return dp[x][y];

    ll p = 0, q = 0, r = 0;

    if (x >= 2)
        p = f(x-2, y);

    q = ((x-1)*(p + f(x-1, y))%mod)%mod;

    if (y >= 1)
    {
        r = (y*(f(x - 1, y - 1) + f(x, y - 1))%mod)%mod;
    }

    return dp[x][y] = (q + r)%mod;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    mod = 1000000007;

    fact[0] = 1;

    for (i = 1; i <= 1002; i++)
        fact[i] = (fact[i-1]*i)%mod;

    memset(dp, -1, sizeof(dp));
    memset(ncr, -1, sizeof(ncr));

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);
        sl(k);

    //    cout << ncrsolve(m, k) << " " << f(m-k, n-m) << endl;

        printf("Case %lld: %lld\n", cs, (ncrsolve(m, k)*f(m-k, n-m))%mod);
    }

    return 0;
}
