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

#define nsz 10010

vector <ll> ed[nsz];

ll tm, cn, vis[nsz], ap[nsz], par[nsz], low[nsz], disc[nsz], hap;

map <ll, bool> vas;

void artidfs(ll u)
{
    vis[u] = 1;
    disc[u] = low[u] = tm++;
    ll child = 0;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == false)
        {
            child++;
            par[v] = u;
            artidfs(v);
            low[u] = min(low[u], low[v]);
            if (par[u] != -1 && disc[u] <= low[v])
            {
                if (ap[u] == 0)
                {
                    cn++;
                    ap[u] = 1;
                }
            }
            if (par[u] == -1 && child > 1)
            {
                if (ap[u] == 0)
                {
                    cn++;
                    ap[u] = 1;
                }
            }
        }
        else if (par[u] != v)
            low[u] = min(low[u], disc[v]);
    }
}

unsigned ll dfs(ll u)
{
    vis[u] = 1;
    unsigned ll cnt = 0;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];

        if (vis[v] == 0)
        {
            if (ap[v] == 0)
                cnt += dfs(v);
            else
            {
                if (vas[v] == 0)
                {
                    hap++;
                    vas[v] = 1;
                }
            }
        }
    }
    return cnt + 1;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m;
    unsigned ll ans, gaba;
    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 0; i < n; i++)
        {
            ap[i] = vis[i] = 0;
            par[i] = -1;
            ed[i].clear();
        }

        while(m--)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        tm = cn = 0;
        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                artidfs(i);
        }

        for (i = 0; i < n; i++)
            vis[i] = 0;

        ans = 1;

        y = 0;

        for (i = 0; i < n; i++)
        {
            hap = 0;
            if (vis[i] == 0 && ap[i] == 0)
            {
                vas.clear();
                gaba = dfs(i);

                if (hap == 1)
                {
                    ans *= gaba;
                    y++;
                }
            }
        }

        if (cn == 0)
        {
            y = 2;
            ans = n*(n-1)/2;
        }

        printf("Case %lld: %lld %lld\n", cs, y, ans);
    }

    return 0;
}
