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

char s[55];

ll dp[52][2][52];

ll solve(ll i, ll v, ll l)
{
    if ( (v == 1 && l >= 3) || (v == 0 && l >= 5) )
    {
        return 0;
    }

    if (s[i] == 0)
    {
        return 1;
    }

    if (dp[i][v][l] != -1)
        return dp[i][v][l];

    ll p, x, y;

    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
    {
        p = solve(i + 1, 1, v == 1? l + 1 : 1);
    }
    else if (s[i] == '?')
    {
        x = solve(i + 1, 1, v == 1? l + 1 : 1);
        y = solve(i + 1, 0, v == 0? l + 1 : 1);

        if (x == 2 || y == 2)
            p = 2;
        else if (x == 1 && y == 1)
            p = 1;
        else if (x == 0 && y == 0)
            p = 0;
        else p = 2;
    }
    else
    {
        p = solve(i + 1, 0, v == 0? l + 1 : 1);
    }

    return dp[i][v][l] = p;
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

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: ", cs);

        x = solve(0, 0, 0);

        if (x == 1)
            printf("GOOD\n");
        else if (x == 0)
            printf("BAD\n");
        else
            printf("MIXED\n");
    }

    return 0;
}
