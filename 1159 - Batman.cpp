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

ll dp[60][60][60];
char a[60], b[60], c[60];

ll solve(ll i, ll j, ll k)
{
    if (a[i] == 0 || b[j] == 0 || c[k] == 0)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    ll x;

    if (a[i] == b[j] && b[j] == c[k])
    {
        x = 1 + solve(i + 1, j + 1, k + 1);
    }
    else
    {
        x = max(solve(i+1, j, k), max(solve(i, j+1, k), solve(i, j, k+1)));
    }
    return dp[i][j][k] = x;
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
        ss(a);
        ss(b);
        ss(c);
        memset(dp, -1, sizeof(dp));
        printf("Case %lld: %lld\n", cs, solve(0, 0, 0));
    }

    return 0;
}
