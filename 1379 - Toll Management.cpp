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

#define nsz 10010

long long dis1[nsz], dis2[nsz], n;

vector <long long> ed[nsz], cost[nsz], red[nsz], rcost[nsz];

void dijk1(long long src)
{
    long long i, j, ad, u;

    for(i = 0; i <= n + 2; i++){
        dis1[i] = LLONG_MAX - 1000100;
    }

    priority_queue <pll, vector<pll>, greater <pll> > pq;

    pq.push(pll(0, src));

    dis1[src] = 0;

    while(!pq.empty())
    {
        pll v = pq.top();
        u = v.second;
        pq.pop();

        for(i=0; i<ed[u].size(); i++)
        {
            ad = ed[u][i];
            if(dis1[u]+cost[u][i]<dis1[ad])
            {
                dis1[ad]=dis1[u]+cost[u][i];
                pq.push(pll(dis1[ad], ad));
            }
        }
    }
}

void dijk2(long long src)
{
    long long i, j, ad, u;

    for(i = 0; i <= n + 2; i++){
        dis2[i] = LLONG_MAX - 1000100;
    }

    priority_queue <pll, vector<pll>, greater <pll> > pq;

    pq.push(pll(0, src));

    dis2[src] = 0;

    while(!pq.empty())
    {
        pll v = pq.top();
        u = v.second;

        pq.pop();

        for(i=0; i<red[u].size(); i++)
        {
            ad = red[u][i];
            if(dis2[u]+rcost[u][i]<dis2[ad])
            {
                dis2[ad]=dis2[u]+rcost[u][i];
                pq.push(pll(dis2[ad], ad));
            }
        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
 //   freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, s, d, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ans = 0;
        sl(n);
        sl(m);
        sl(s);
        sl(d);
        sl(p);

        for (i = 0; i <= n; i++)
        {
            ed[i].clear();
            cost[i].clear();
            red[i].clear();
            rcost[i].clear();
        }

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            sl(z);
            ed[x].pb(y);
            cost[x].pb(z);
            red[y].pb(x);
            rcost[y].pb(z);

         //   cout << i << " " << ed[x].size() << endl;
        }

        dijk1(s);
        dijk2(d);

    //    cout << ed[1].size() << endl;

        for (i = 1; i <= n; i++)
            for (j = 0; j < ed[i].size(); j++)
            {
                x = i;
                y = ed[i][j];
                if (dis1[x] == LLONG_MAX - 1000100|| dis2[y] == LLONG_MAX - 1000100)
                    continue;
         //       cout << i << " " << j << " " << x << " " << y << " " << dis1[x] << " " << dis2[y] << " " << cost[i][j] << " " << p << " " << ans << endl;
                if (dis1[x] + dis2[y] + cost[i][j] <= p)
                {
                    ans = max(ans, cost[i][j]);
                }
//                else if (dis2[x] + dis1[y] + cost[i][j] <= p)
//                {
//                    ans = max(ans, cost[i][j]);
//                }
            }

        if (dis1[d] > p)
            ans = -1;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
/*
500
2 2 1 2 20
1 2 10
1 2 20
*/
