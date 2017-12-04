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

map <ll, vector <ll> > ed;
map <ll, map <ll, ll> > cost;
map <ll, map <ll, bool> > vis;

priority_queue <pll, vector <pll>, greater<pll> > pq;

ll dis[600];

void dijk(ll src)
{
    dis[src] = 0;
    pq.push(pll(0, src));

    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        for (ll i = 0; i < ed[u].size(); i++)
        {
            if (max(dis[u], cost[u][ed[u][i]]) < dis[ed[u][i]])
            {
                dis[ed[u][i]] = max(dis[u], cost[u][ed[u][i]]);
                pq.push(pll(dis[ed[u][i]], ed[u][i]));
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

        for (i = 0; i < n; i++)
            dis[i] = LLONG_MAX;

        ed.clear();
        cost.clear();
        vis.clear();

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            sl(z);
            ed[x].pb(y);
            ed[y].pb(x);

            //   cout << vis[x][y] << endl;

            if (cost.count(x) == 0)
            {
                    //   cout << "a " << cost[x][y] << " " << cost[y][x] << " " << z << endl;
                    cost[x][y] = z;
                    cost[y][x] = z;
                    //    cout << "a " << cost[x][y] << " " << cost[y][x] << " " << z << endl;
            }
            else
            {

                if (cost[x].count(y) == 0)
                {
                    //   cout << "a " << cost[x][y] << " " << cost[y][x] << " " << z << endl;
                    cost[x][y] = z;
                    cost[y][x] = z;
                    //    cout << "a " << cost[x][y] << " " << cost[y][x] << " " << z << endl;
                }
                else
                {
                    cost[x][y] = min(cost[x][y], z);
                    cost[y][x] = min(cost[y][x], z);
                }
                //  cout << "b " << cost[x][y] << " " << cost[y][x] << " " << z << endl;
            }
        }

        /*     for (i = 0; i < n; i++)
                 for (j = 0; j < n; j++)
                     cout << i << " " << j << " " << cost[i][j] << " " << cost[j][i] << endl; */

        sl(x);

        dijk(x);

        printf("Case %lld:\n", cs);

        for (i = 0; i < n; i++)
        {
            if (dis[i] != LLONG_MAX)
                printf("%lld\n", dis[i]);
            else printf("Impossible\n");
        }
    }

    return 0;
}
