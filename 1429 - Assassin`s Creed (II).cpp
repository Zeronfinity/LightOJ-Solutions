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

#define nsz 2010

map <ll, map <ll, bool> > done;

vector <ll> ed[nsz], red[nsz], scced[nsz];

ll sccno, n, tm, etime[nsz], tarrsz, wscc[nsz], in[nsz], out[nsz];

ll ar[nsz];

bool vis[nsz];

pll tarr[nsz];

void fdfs(ll n)
{
   // cout << "fdfs a " << n << endl;
    vis[n] = 1;
    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll ad = ed[n][i];
        if (vis[ad] == 0)
            fdfs(ad);
    }
    etime[n] = tm++;
 //   cout << "fdfs b " << tarrsz << endl;
    tarr[tarrsz++] = pll(etime[n], n);
}

void rdfs(ll n)
{
    wscc[n] = sccno;
    for (ll i = 0; i < red[n].size(); i++)
    {
        ll ad = red[n][i];
        if (wscc[ad] == 0)
            rdfs(ad);
    }
}

void findscc()
{
    ll i, j;

    tm = 1;
    tarrsz = 0;

    for (i = 0; i <= n; i++)
        vis[i] = 0;

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            fdfs(i);
        }
      //  cout << i << " " << tarrsz << endl;
    }

    sort(tarr, tarr + tarrsz);

    for (i = 0; i <= n; i++)
        wscc[i] = 0;

    sccno = 1;

 //   cout << "tarrsz " << tarrsz << endl;

    for (i = tarrsz - 1; i >= 0; i--)
    {
        ll u = tarr[i].second;
        if (wscc[u] == 0)
        {
            rdfs(u);
            sccno++;
        }
    }
}

void dfs(ll n)
{
    vis[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll ad = ed[n][i];

   //     cout << "dfs " << n << " " << ad << " " << done[n][ad] << " " << wscc[n] << " " << wscc[ad] << endl;

        if (done[n][ad] == 0 && wscc[n] != wscc[ad])
        {
            done[n][ad] = 1;
            in[wscc[ad]]++;
            scced[wscc[n]].pb(wscc[ad]);
        }

        if (vis[ad] == 0)
        {
            dfs(ad);
        }
    }
}

bool comp(ll l, ll r)
{
    return in[l] < in[r];
}

bool svis[nsz][nsz], ovis[nsz];

void sdfs(ll n, ll root)
{
    svis[root][n] = 1;
    ovis[n] = 1;

    for (ll i = 0; i < scced[n].size(); i++)
    {
        if (svis[root][scced[n][i]] == 0)
        {
            sdfs(scced[n][i], root);
            break;
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

        for (i = 0; i <= n; i++)
        {
            scced[i].clear();
            ed[i].clear();
            red[i].clear();
        }

        while(m--)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            red[y].pb(x);
        }

        findscc();

        for (i = 0; i <= n; i++)
        {
            vis[i] = 0;
            in[i] = 0;
            out[i] = 0;
        }

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }

        x = 0;
        y = 0;

    //    cout << sccno << endl;

        for (i = 1; i < sccno; i++)
        {
            ar[i] = i;
        }

        sort(ar + 1, ar + sccno, comp);

        ans = 0;
        memset(svis, 0, sizeof(svis));
        memset(ovis, 0, sizeof(ovis));

        //gotta find minimum path cover for the scc-made DAG now

        for (i = 1; i < sccno; i++)
        {
        //  cout << i << " " << svis[i] << " " << ans << endl;
            if (ovis[i] == 0)
            {
                sdfs(i, i);
                ans++;
            }
        }

        printf("Case %lld: %lld\n", cs, ans);
        done.clear();
    }

    return 0;
}
