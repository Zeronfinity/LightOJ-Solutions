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

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

#define nsz 110

int dis[nsz][110], n, price[nsz];

vector <int> ed[nsz], cost[nsz];
priority_queue <plp, vector<plp>, greater <plp> > pq;


ll dijk(int src, int dst, ll cap)
{
    int i, j, ad, u;

    for (i = 0; i <= n + 2; i++)
        for (j = 0; j <= cap + 2; j++)
        {
            dis[i][j] = INT_MAX;
        }

    pq.push(plp(0, pll(src, 0)));

    dis[src][0] = 0;

    while(!pq.empty())
    {
        plp v = pq.top();
        u = v.second.first;
        ll ase = v.second.second;
        pq.pop();
        //   cout << u << " " << ase << " " << v.first << endl;
        if(u == dst)
            return v.first;

        for (i = ase + 1; i <= cap; i++)
        {
            pll ad = pll(u, i);

            ll taka = (i - ase)*price[u];
            ll exp = dis[u][ase] + taka;

            if(exp < dis[u][i])
            {
                    dis[u][i] = exp;
                    pq.push(plp(exp, pll(u, i)));
            }
        }

        for(i=0; i<ed[u].size(); i++)
        {
            ad = ed[u][i];

            if(ase >= cost[u][i])
            {
                ll left = ase - cost[u][i];
                ll exp = dis[u][ase];
                if (exp < dis[ad][left])
                {
                    dis[ad][left] = exp;
                    pq.push(plp(exp, pll(ad, left)));
                }
            }
        }
    }
    return -1;
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

        for (i = 0; i < n; i++)
        {
            ed[i].clear();
            cost[i].clear();
            sl(price[i]);
        }

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            ed[x].pb(y);
            ed[y].pb(x);

            cost[x].pb(z);
            cost[y].pb(z);
        }

        sl(q);

        printf("Case %d:\n", cs);

        while(q--)
        {
            sl(x);
            sl(y);
            sl(z);

            while(pq.empty() == false)
                pq.pop();

            for (i = 0; i <= n; i++)
                for (j = 0; j <= x; j++)
                {
                    dis[i][j] = INT_MAX-1000;
                }

            ans = dijk(y, z, x);

            if (ans == -1)
                printf("impossible\n");
            else printf("%d\n", ans);
        }
    }

    return 0;
}
