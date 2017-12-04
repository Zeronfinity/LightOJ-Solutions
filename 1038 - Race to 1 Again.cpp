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

double dp[100100];
bool vis[100100];
ll n;

double solve(ll n)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 2;

    if (vis[n] != 0)
        return dp[n];

    vis[n] = 1;

    ll sq = sqrt((double) n);
    double sum = 2, cn = 1;

    for (ll i = 2; i <= sq; i++)
    {
        if (n%i == 0)
        {
            sum += solve(n/i) + 1;
            cn++;
            if (i*i != n)
            {
                sum += solve(i) + 1;
                cn++;
            }
        }
    }

   // cout << n << " " << sum << " " << cn << endl;

    return dp[n] = sum/cn;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);
    memset(vis, 0, sizeof(vis));

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        printf("Case %lld: %0.7lf\n", cs, solve(n));
    }

    return 0;
}
