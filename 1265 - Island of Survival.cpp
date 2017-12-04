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
#define fr first
#define sd second

bool vis[1010][1010];
double dp[1010][1010];

double solve(ll tg, ll dr)
{
    if (tg == 0)
        return 1;

    if (vis[tg][dr] == 1)
        return dp[tg][dr];
    vis[tg][dr] = 1;

    double p1 = 0, q, l1 = 1, x, y, p2 = 0, l2 = 1;

    if (dr > 0)
    {
        q = 2*solve(tg, dr - 1);

        q *= (double) tg / (double) (tg + dr + 1);
        q *= (double) dr / (double) (tg + dr);

        p1 += q;
        p2 += q;
    }

    if (dr >= 2)
    {
        q = 1;
        q *= (double) dr / (double) (tg + dr + 1);
        q *= (double) (dr - 1) / (double) (tg + dr);

        x = solve(tg, dr - 1);

        l1 -= q;
        l2 -= q;
    }

    if (dr >= 1)
    {
        q = 2;
        q *= (double) dr / (double) (tg + dr + 1);
        q *= (double) 1 / (double) (tg + dr);

        l1 -= q;

        q *= solve(tg, dr-1);
        p2 += q;
    }

    if (tg > 1)
    {
        q = solve(tg - 2, dr);
        q *= (double) tg / (double) (tg + dr + 1);
        q *= (double) (tg-1) / (double) (tg + dr);

        p1 += q;
        p2 += q;
    }

    return dp[tg][dr] = max(p1/l1, p2/l2);
}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, tg, dr;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(tg);
        sl(dr);
        printf("Case %lld: %0.8lf\n", cs, solve(tg, dr));
    }

    return 0;
}
