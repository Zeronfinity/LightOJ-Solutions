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
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sd second

#define nsz 50010

//map <ll, map <ll, bool> > done;

vector <ll> ed[nsz], red[nsz], ded[nsz];

ll sccno, n, tm, etime[nsz], tarrsz, wscc[nsz];

bool vis[nsz];

pll tarr[nsz];

vector <ll> sccnodes[nsz];

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
  //  cout << "fdfs b " << tarrsz << endl;
    tarr[tarrsz++] = pll(etime[n], n);
}

void rdfs(ll n)
{
    sccnodes[sccno].pb(n);
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
    {
        vis[i] = 0;
        sccnodes[i].clear();
    }

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

     //   cout << u << " " << sccno << endl;
    }
}

void dagdfs(ll n)
{
    vis[n] = 1;
    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll ad = ed[n][i];

        if (/*done[wscc[n]][wscc[ad]] == 0 &&*/ wscc[n] != wscc[ad])
        {
            ded[wscc[n]].pb(wscc[ad]);

        //    cout << n << " " << wscc[n] << " " << ad << " " << wscc[ad] << endl;

     //       done[wscc[n]][wscc[ad]] = 1;
       //     done[wscc[ad]][wscc[n]] = 1;
        }

        if (vis[ad] == 0)
            dagdfs(ad);
    }
}

ll dp[nsz];

ll best;

vector <ll> res;

void dfs(ll n)
{
    vis[n] = 1;

    ll mx = 0;
    dp[n] = sccnodes[n].size();

 //   cout << "DFS " << n << " " << ded[n].size() << endl;

    for (ll i = 0; i < ded[n].size(); i++)
    {
        ll ad = ded[n][i];

   //     cout << "Dfs " << n << " " << ad << " " << vis[ad] << endl;

        if (vis[ad] == 0)
        {
            dfs(ad);
        }

        mx = max(mx, dp[ad]);
    }

    dp[n] += mx;

    if (dp[n] > best)
    {
        best = dp[n];
        res.clear();
        res.pb(n);
    }
    else if (dp[n] == best)
    {
        res.pb(n);
    }

//    cout << n << " " << dp[n] << " " << mx << " " << best << endl;
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

//        done.clear();

        for (i = 0; i <= n; i++)
        {
            ed[i].clear();
            red[i].clear();
            vis[i] = 0;
        }

        for (i = 1; i <= n; i++)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            red[y].pb(x);
        }

        findscc();

        //creating DAG
        for (i = 0; i <= n; i++)
        {
            vis[i] = 0;
            ded[i].clear();
        }

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dagdfs(i);
            }
        } //DAG created

        for (i = 0; i <= sccno; i++)
            vis[i] = 0;

//        cout << "sccno = " << sccno << endl;

        best = 0;

        res.clear();

        for (i = 1; i < sccno; i++)
        {
            if (vis[i] == 0)
                dfs(i);
        }

        ans = INT_MAX;

//        for (i = 1; i < sccno; i++)
//        {
//            cout << "scc " << i << ": ";
//            for (j = 0; j < sccnodes[i].size(); j++)
//                cout << sccnodes[i][j] << " ";
//            cout << endl;
//        }

        for (i = 0; i < res.size(); i++)
        {
            sort(sccnodes[res[i]].begin(), sccnodes[res[i]].end());
            ans = min(ans, sccnodes[res[i]][0]);
     //       cout << i << " " << res[i] << " " << ans << endl;
        }


        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}
