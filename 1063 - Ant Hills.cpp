#include <stdio.h>
#include <climits>
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
#define pb push_back

vector <ll> ed[10010];

ll tm, cn, vis[10010], low[10010], par[10010], disc[10010], ap[10010];

void rtdfs (ll u)
{
    vis[u] = 1;

    disc[u] = low[u] = tm++;

    ll child = 0;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];

        if (vis[v] == 0)
        {
            child++;

            par[v] = u;

            rtdfs(v);

            low[u] = min(low[u], low[v]);

            if (par[u] != -1 && disc[u] <= low[v])
                if (ap[u] == 0)
                {
                    ap[u] = 1;
                    cn++;
                }
        }
        else
        {
            if (par[u] != v)
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (par[u] == -1 && child > 1)
        {
            if (ap[u] == 0)
            {
                ap[u] = 1;
                cn++;
            }
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
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
        {
            ed[i].clear();
            vis[i] = ap[i] = 0;
            par[i] = -1;
        }

        while(m--)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        tm = cn = 0;

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                rtdfs(i);
            }
        }

        printf("Case %lld: %lld\n", cs, cn);
    }

    return 0;
}
