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

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

#define nsz 10010

vector <ll> ed[nsz], ned[nsz];

#define nsz 10010

ll tm, vis[nsz], par[nsz], low[nsz], disc[nsz], cn;

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
//                isarti[u][v] = 1;
//                isarti[v][u] = 1;
            }
            else
            {
                ned[u].pb(v);
                ned[v].pb(u);
            }
        }
        else if (par[u] != v)
        {
            low[u] = min(low[u], disc[v]);
            ned[u].pb(v);
            ned[v].pb(u);
        }
    }
}

bool color;

ll dfs(ll u)
{
    ll cnt = 0;
    for (ll i = 0; i < ned[u].size(); i++)
    {
        ll v = ned[u][i];

            if (vis[v] == 0)
            {
                vis[u] == 1 ? vis[v] = 2 : vis[v] = 1;
                cnt += dfs(v);
            }
            else
            {
                if (vis[v] == vis[u])
                    color = false;
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
    ll ans, gaba;
    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 0; i < n; i++)
        {
            vis[i] = 0;
            par[i] = -1;
            ed[i].clear();
            ned[i].clear();
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

        ans = 0;


        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                color = true;
                vis[i] = 1;
                gaba = dfs(i);

                if (color == false)
                {
                    ans += gaba;
                }
            }
        }

        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}
