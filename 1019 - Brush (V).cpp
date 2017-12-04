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
#define pll pair <long long, long long>
#define pb push_back


#define nsz 110

long long dis[nsz], n;

vector<long long> ed[nsz], cost[nsz];

priority_queue <pll, vector<pll>, greater <pll> > pq;

void dijk(long long src, long long dst)
{
    long long i, j, ad, u;

    for(i = 0; i<= n + 2; i++){
        dis[i] = LLONG_MAX-100000;
    }

    pq.push(pll(0, src));

    dis[src]=0;

    while(!pq.empty())
    {
        pll v = pq.top();
        u = v.second;
        pq.pop();
        if(u == dst)
            return;
        for(i=0; i<ed[u].size(); i++)
        {
            ad = ed[u][i];
            if(dis[u]+cost[u][i]<dis[ad])
            {
                dis[ad]=dis[u]+cost[u][i];
                pq.push(pll(dis[ad], ad));
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

        while (pq.empty() == false)
            pq.pop();

        for (i = 0; i <= n; i++)
        {
            ed[i].clear();
            cost[i].clear();
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

        dijk(1, n);

        if (dis[n] != LLONG_MAX-100000)
            printf("Case %lld: %lld\n", cs, dis[n]);
        else printf("Case %lld: Impossible\n", cs);
    }

    return 0;
}
