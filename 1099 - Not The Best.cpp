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
#include <limits.h>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>

map <ll, vector <ll> > ed;
map <ll, vector <ll> > cost;

ll d[5050], sd[5050];

priority_queue < pll, vector <pll>, greater<pll> > pq, tpq;

void dijk(ll src, ll dst)
{
    pq.push(pll(0, src));
    d[src] = 0;

    while(pq.empty() == false)
    {
        pll temp = pq.top();
        pq.pop();

        ll u = temp.second;
        ll dis = temp.first;

        for (ll i = 0; i < ed[u].size(); i++)
        {
            ll v = ed[u][i];

            if (dis < d[v] - cost[u][i])
            {
                sd[v] = d[v];
                d[v] = dis + cost[u][i];
                pq.push(pll(d[v], v));
 //               cout << "a " << u << " " << dis << " " << v << " " << d[v] << endl;
            }
            else if (dis < sd[v] - cost[u][i] && dis != d[v] - cost[u][i])
            {
                sd[v] = dis + cost[u][i];
                pq.push(pll(sd[v], v));
   //             cout << "b " << u << " " << dis << " " << v << " " << d[v] << endl;
            }
        }
    }
}


int main ()
{
 //   freopen("inl.txt", "r", stdin);
    // freopen("outl.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
            d[i] = sd[i] = LLONG_MAX;

        ed.clear();
        cost.clear();

        while (pq.empty() == false)
            pq.pop();

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            sl(z);


            ed[x].push_back(y);
            ed[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        dijk(1, n);

        printf("Case %lld: %lld\n", cs, sd[n]);
    }

    return 0;
}
