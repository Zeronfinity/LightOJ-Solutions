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

char s[70];

ll len, dp[62][62];

ll solve(ll i, ll j)
{
    if (i == j)
        return 1;

    if (i > j)
        return 0;

    ll ans = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        ans = solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
    else
    {
        ans = 1 + solve(i + 1, j - 1) + solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
    }

    return dp[i][j] = ans;
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

        len = strlen(s);

        for (i = 0; i <= len; i++)
            for (j = 0; j <= len; j++)
                dp[i][j] = -1;

        printf("Case %lld: %lld\n", cs, solve(0, len - 1));
    }

    return 0;
}
