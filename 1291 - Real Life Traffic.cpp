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

ll tm, vis[nsz], par[nsz], low[nsz], disc[nsz], deg[nsz];

map <ll, map <ll, bool> > isarti;

void artidfs(ll u)
{
    vis[u] = 1;
    disc[u] = low[u] = tm++;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == false)
        {
            par[v] = u;
            artidfs(v);
            low[u] = min(low[u], low[v]);
            if (disc[u] < low[v])
            {
                /* edge u to v is an articulation bridge   */
            //    cout << u << "  " << v << endl;
                deg[u]++;
                deg[v]++;
                isarti[u][v] = 1;
                isarti[v][u] = 1;
            }
        }
        else if (par[u] != v)
            low[u] = min(low[u], disc[v]);
    }
}

ll dfs(ll u)
{
    vis[u] = 1;

    ll cn = 0;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];

        if (vis[v] == 0 && isarti[u][v] == 0)
        {
            cn += dfs(v);
        }
    }
    cn += deg[u];
    return cn;
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

        for (i = 0; i <= n; i++)
        {
            vis[i] = 0;
            deg[i] = 0;
            par[i] = -1;
            ed[i].clear();
        }

        isarti.clear();

        while(m--)
        {
            sl(x);
            sl(y);

            ed[x].pb(y);
            ed[y].pb(x);
        }


        tm = 0;

        artidfs(x);

        for (i = 0; i <= n; i++)
        {
            vis[i] = 0;
        }

        ans = 0;

        for (i = 0; i < n; i++)
        {
       //     cout << i << " " << vis[i] << endl;
            if (vis[i] == false)
            {
                x = dfs(i);
         //       cout << x << endl;
                if (x == 1)
                    ans++;
            }
           // cout << ans << endl;
        }

        if (ans%2 == 0)
            ans /= 2;
        else ans = ans/2 + 1;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
