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

vector <ll> ed[1010];

ll dp[1010][2];

ll solve(ll n, ll prev, ll par)
{
    ll p = prev;

    if (dp[n][prev] != -1)
        return dp[n][prev];

    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (ed[n][i] == par)
            continue;

        if (prev == 0)
            p += max(solve(ed[n][i], 1, n), solve(ed[n][i], 0, n));
        else p += solve(ed[n][i], 0, n);
    }

    //  cout << n << " " << prev << " " << p << endl;

    return dp[n][prev] = p;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        memset(dp, -1, sizeof(dp));

        ans = 0;

        for (i = 1; i <= n; i++)
        {
            //cout << i << " "  << vvis[i] << " " << ans << endl;

            if (dp[i][0] == -1 || dp[i][1] == -1)
                ans += max(solve(i, 0, 0), solve(i, 1, 0));
        }

        printf("Case %lld: %lld\n", cs, ans);

        for (i = 0; i <= n; i++)
            ed[i].clear();
    }

    return 0;
}
