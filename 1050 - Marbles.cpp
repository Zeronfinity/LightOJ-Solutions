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

double dp[510][510];

double solve(ll a, ll b)
{
    if (a == 0 && b == 1)
        return 1;

    if (a + b == 0)
        return 0;

    if (dp[a][b] > - 0.5)
        return dp[a][b];

    double p = 0, q = 0;

    if ((a+b)%2 != 0)
    {
        if (a != 0)
            p = solve(a - 1, b);

        if (b != 0)
            q = solve(a, b - 1);

        dp[a][b] = (a*p+b*q)/(a+b);
    }
    else
    {
        if (b == 0)
            return 0;

        p = solve(a, b - 1);

        dp[a][b] = b*p/b;
    }
    //cout << a << " " << b << " " << pl << " " << dp[a][b][pl] << endl;
    return dp[a][b];
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    for (i = 0; i <= 501; i++)
        for (j = 0; j <= 501; j++)
            dp[i][j] = -1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);


        printf("Case %lld: %0.7lf\n", cs, solve(x, y));
    }

    return 0;
}
