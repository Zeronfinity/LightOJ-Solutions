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

bool vis[55][55][2];
unsigned ll dp[55][55][2];

unsigned ll solve(ll a, ll b, ll c)
{
 //   cout << a << " " << b << " " << c << endl;
    if (c == 0)
    {
        if (a == 1 && b == 0)
            return 1;

        if (a == 0)
            return 0;
    }
    else
    {
        if (a == 0 && b == 1)
            return 1;

        if (b == 0)
            return 0;
    }

    if (vis[a][b][c] != 0)
        return dp[a][b][c];
    vis[a][b][c] = 1;

    if (c == 0)
    {
        for (ll i = 1; i <= a; i++)
        {
            dp[a][b][c] += solve(i-1, b + a - i, 1);
     //       cout << "loop " << a << " " << b << " " << c << " " << i << " " << dp[a][b][c] << endl;
        }
    }
    else {
        for (ll i = 1; i <= b; i++)
        {
            dp[a][b][c] += solve(a + b - i, i - 1, 0);
        }
    }

    return dp[a][b][c];
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, y, z, ans, q, m, n;
    unsigned ll x;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        if (m == 1)
        {
            if (n >= 3)
                x = solve(1, n - 3, 0);
            else x = 1;
        }
        else
        {
            x = solve(m-1, n - m, 0);
        }

        printf("Case %lld: %llu\n", cs, x);
    }

    return 0;
}

