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
#define ft first
#define sd second

#define mx LLONG_MAX-100000

ll n, s;

#define nsz 600

long long dis[nsz][nsz];

vector <long long> ed[nsz], cost[nsz];

void dijk(long long src)
{
    long long i, j, ad, u;

    for(i=0; i <= n + 2; i++)
    {
        dis[src][i] = LLONG_MAX-100000;
    }

    priority_queue <pll, vector<pll>, greater <pll> > pq;

    pq.push(pll(0, src));

    dis[src][src]=0;

    while(!pq.empty())
    {
        pll v = pq.top();
        u = v.second;
        pq.pop();

        for(i=0; i<ed[u].size(); i++)
        {
            ad = ed[u][i];
            if(dis[src][u]+cost[u][i]<dis[src][ad])
            {
                dis[src][ad]=dis[src][u]+cost[u][i];
                pq.push(pll(dis[src][ad], ad));
            }
        }
    }
}

ll shop[16];

pll dp[16][33000];
bool vis[16][33000];

pll solve(ll i, ll mask)
{
    if (vis[i][mask] != 0)
        return dp[i][mask];

    vis[i][mask] = 1;

    pll t, a(1, mx);

    for (ll j = 0; j < s; j++)
    {
        if ( (mask & (1LL << j)) == 0 && dis[shop[i]][shop[j]] != mx && i != j)
        {
            t = solve(j, mask | (1LL << i) );

            if (t.ft + 1 > a.ft)
            {
                a.ft = t.ft + 1;
                a.sd = t.sd + dis[shop[i]][shop[j]];
            }
            else if (t.ft + 1 == a.ft)
            {
                if (t.sd + dis[shop[i]][shop[j]] < a.sd)
                {
                    a.ft = t.ft + 1;
                    a.sd = t.sd + dis[shop[i]][shop[j]];
                }
            }
        }
      //  cout << i << " " << shop[i] << " " << mask << " " << j << " " << shop[j] << " " << dis[shop[i]][shop[j]] << " " << t.ft << " " << t.sd << " " << a.ft << " " << a.sd << endl;
    }

    if (dis[shop[i]][n-1] != mx)
    {
        if (1 > a.ft)
        {
            a.ft = 1;
            a.sd = dis[shop[i]][n-1];
        }
        else if (1 == a.ft)
        {
            if (dis[shop[i]][n-1] < a.sd)
            {
                a.ft = 1;
                a.sd = dis[shop[i]][n-1];
            }
        }
    }

    if (a.sd == mx)
    {
        if (dis[shop[i]][n-1] == mx)
        {
            a.ft = 0;
            a.sd = mx;
            return dp[i][mask] = a;
        }
        else
        {
            a.ft = 1;
            a.sd = dis[shop[i]][n-1];
            return dp[i][mask] = a;
        }
    }
    else
        return dp[i][mask] = a;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, ts, i, j, k, x, y, z, ans, q, m;

    sl(ts);

    for (cs = 1; cs <= ts; cs++)
    {
        sl(n);
        sl(m);
        sl(s);

        q = -1;

        for (i = 0; i < s; i++)
        {
            sl(shop[i]);
            if (shop[i] == 0)
                q = i;
        }

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            sl(z);
            ed[x].pb(y);
            cost[x].pb(z);
        }

        dijk(0);

        for (i = 0; i < s; i++)
        {
            dijk(shop[i]);
            // cout << i << " " << dis[2][3] << endl;
        }

        memset(vis, 0, sizeof(vis));

        pll a(0, dis[0][n-1]);

        pll t;

        for (i = 0; i < s; i++)
        {
            if (dis[0][shop[i]] != mx)
            {
          //      memset(vis, 0, sizeof(vis));
                t = solve(i, ((q==-1)?0:(1 << q)) );
             //   cout << "gaba " << i << " " << shop[i] << " " << t.ft << " " << t.sd << endl;
                if (t.ft > a.ft)
                {
                    a.ft = t.ft;
                    a.sd = t.sd + dis[0][shop[i]];
                }
                else if (t.ft == a.ft)
                {
                    if (t.sd + dis[0][shop[i]] < a.sd)
                    {
                        a.ft = t.ft;
                        a.sd = t.sd + dis[0][shop[i]];
                    }
                }
            }
        }

        if (a.ft != 0)
            printf("Case %lld: %lld %lld\n", cs, a.ft, a.sd);
        else
            printf("Case %lld: Impossible\n", cs);

        for (i = 0; i <= n; i++)
        {
            ed[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

/*

3

5 4 3
2 3 0
0 2 50
4 0 34
2 4 87
3 2 10

4 6 2
0 3
3 2 35
2 0 2
2 1 90
3 1 44
2 3 61
0 2 74
*/
