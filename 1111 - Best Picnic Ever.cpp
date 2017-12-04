#include <stdio.h>
#include <iostream>
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

map <ll, vector<ll> > ed;

bool vis[1010];
ll tvis[1010];
ll store[110];

void dfs(ll n)
{
    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (vis[ed[n][i]] == 0)
        {
            tvis[ed[n][i]]++;
            vis[ed[n][i]] = 1;
            dfs(ed[n][i]);
        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(k);
        sl(n);
        sl(m);

        ed.clear();

        for (i = 1; i <= n; i++)
            tvis[i] = vis[i] = 0;

        ans = 0;

        for (i = 1; i <= k; i++)
        {
            sl(store[i]);
        }

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            ed[x].push_back(y);
        }


        for (i = 1; i <= k; i++)
        {
            for (j = 1; j <= n; j++)
                vis[j] = 0;

            vis[store[i]] = 1;
            tvis[store[i]]++;
            dfs(store[i]);
        }

        for (i = 1; i <= n; i++)
            if (tvis[i] >= k)
                ans++;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
