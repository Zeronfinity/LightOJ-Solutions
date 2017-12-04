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
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sd second

#define nodes_no 1010

vector <ll> ed[nodes_no];

bool vis[nodes_no];
ll amt, no, coin[nodes_no];

ll dfs(ll u)
{
    amt += coin[u];
    no++;
    vis[u] = 1;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == 0)
            dfs(v);
    }
}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
        {
            vis[i] = 0;
            ed[i].clear();
        }

        for (i = 1; i <= n; i++)
            sl(coin[i]);

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        bool pos = 1;

        x = -1;

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                amt = no = 0;
                dfs(i);

                if (amt%no != 0)
                {
                    pos = 0;
                    break;
                }

                if (x == -1)
                    x = amt/no;

                if (amt/no != x)
                {
                    pos = 0;
                    break;
                }
            }
        }

        printf("Case %lld: ", cs);

        if (pos == 0)
            printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
