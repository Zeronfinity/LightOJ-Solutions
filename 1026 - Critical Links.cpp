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

char s[15];

struct node
{
    ll x, y;
} ar[100100];


#define nsz 10010

vector <ll> ed[nsz];

ll tm, cn, vis[nsz], par[nsz], low[nsz], disc[nsz];

void artidfs(ll u)
{
    vis[u] = 1;
    disc[u] = low[u] = tm++;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == false)
        {
            par[v] = u;
            artidfs(v);
            low[u] = min(low[u], low[v]);
            if (disc[u] < low[v])
            {
                // edge u to v is an articulation bridge
                ar[cn].x = min(u, v);
                ar[cn].y = max(u, v);
                cn++;

            }
        }
        else if (par[u] != v)
            low[u] = min(low[u], disc[v]);
    }
}

bool comp (node a, node b)
{
    if (a.x < b.x)
        return true;
    else if (a.x == b.x)
    {
        if (a.y < b.y)
            return true;
        else return false;
    }
    else return false;
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

        for (i = 0; i < n; i++)
        {
            ed[i].clear();
            vis[i] = 0;
            par[i] = -1;
        }

        for (i = 0; i < n; i++)
        {
            sl(x);
            ss(s);
            y = 0;
            z = strlen(s);
            for (j = 1; j < z-1; j++)
                y = 10*y + s[j] - '0';

      //      cout << i << " " << x << " " << s << " " << y << endl;

            while(y--)
            {
                sl(z);
                ed[x].pb(z);
                ed[z].pb(x);
            }
        }

        tm = cn = 0;

        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                artidfs(i);
        }

        sort(ar, ar + cn, comp);

        printf("Case %lld:\n%lld critical links\n", cs, cn);

        for (i = 0; i < cn; i++)
            printf("%lld - %lld\n", ar[i].x, ar[i].y);
    }

    return 0;
}
