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

vector <ll> ed[16];

bool possbl[33000];

ll dp[33000], nm;

ll solve(ll mask)
{
   // cout << n << " " << mask << endl;
    if (mask == 0)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    ll ans = LLONG_MAX;

    for (ll i = mask; i > 0; i = (i-1)&mask)
    {
        ll remaining = mask^i;

     //   cout << mask << " " << i << " " << remaining << " " << possbl[remaining] << " " << ans << endl;

        if (possbl[i])
            ans = min(ans, solve(remaining) + 1);
    }

 //   cout << mask << " " << ans << endl;

    return dp[mask] = ans;
}

bool vis[16][33000];

void dfs(ll u, ll mask)
{
    vis[u][mask] = 1;
    possbl[mask] = 1;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        if (vis[ed[u][i]][mask | (1LL << ed[u][i])] == 0)
        {
            dfs(ed[u][i], mask | (1LL << ed[u][i]));
        }
    }
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
        sl(nm);
        sl(m);

        for (i = 0; i < nm; i++)
            ed[i].clear();

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            ed[x-1].pb(y-1);
        }

        memset(vis, 0, sizeof(vis));
        memset(possbl, 0, sizeof(possbl));

        for (i = 0; i < nm; i++)
        {
            dfs(i, (1LL << i));
        }

        memset(dp, -1, sizeof(dp));

        ans = solve((1LL << nm) - 1);

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
