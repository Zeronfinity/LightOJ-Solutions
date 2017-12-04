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
#define plp pair <long long, pll >
#define pb push_back

vector <ll> ed[10010], ned[10010], cost[10010], ncost[10010];

ll n, d, dis[11][10010];

void dijk()
{
    priority_queue <plp, vector <plp>, greater<plp> > pq;

    pq.push(plp(0, pll(0, 0)));

    dis[0][0] = 0;

    while(!pq.empty())
    {
        ll u = pq.top().second.first;
        ll hm = pq.top().second.second;
        pq.pop();

      //  cout << "Yo Gaba " << u << " " << hm << endl;

        for (ll i = 0; i < ed[u].size(); i++)
        {
            ll adj = ed[u][i];
        //    cout << "agaba " << i << " " << adj << " " << dis[hm][u] << " " << cost[u][i] << " " << dis[hm][adj] << endl;
            if (dis[hm][u] + cost[u][i] < dis[hm][adj])
            {
                dis[hm][adj] = dis[hm][u] + cost[u][i];
                pq.push(plp(dis[hm][adj], pll(adj, hm) ));
            }
        }

        if (hm < d)
        {
            for (ll i = 0; i < ned[u].size(); i++)
            {
                ll adj = ned[u][i];

//                cout << "bgaba " << i << " " << adj << " " << dis[hm][u] << " " << cost[u][i] << " " << dis[hm][adj] << endl;

                if (dis[hm][u] + ncost[u][i] < dis[hm + 1][adj])
                {
                    dis[hm + 1][adj] = dis[hm][u] + ncost[u][i];
                    pq.push(plp(dis[hm + 1][adj], pll(adj, hm + 1) ));
                }
            }
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
        sl(n);
        sl(m);
        sl(k);
        sl(d);

        for (i = 0; i < 10010; i++)
            {
                for (j = 0; j <= d; j++)
                    dis[j][i] = LLONG_MAX;

                ed[i].clear();
                cost[i].clear();
                ned[i].clear();
                ncost[i].clear();
            }


        while(m--)
        {
            sl(x);
            sl(y);
            sl(z);

            ed[x].pb(y);
            cost[x].pb(z);

           // ed[y].pb(x);
         //   cost[y].pb(z);
        }

        while(k--)
        {
            sl(x);
            sl(y);
            sl(z);

            ned[x].pb(y);
            ncost[x].pb(z);

           // ned[y].pb(x);
          //  ncost[y].pb(z);
        }

        dijk();

        ans = LLONG_MAX;

        for (i = 0; i <= d; i++)
            ans = min(ans, dis[i][n-1]);

        if (ans == LLONG_MAX)
            printf("Case %lld: Impossible\n", cs);
        else printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
