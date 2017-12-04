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
#define ft first
#define sd second

vector <ll> ed[60];

struct edg
{
    ll u, v, w;
    bool operator < (const edg& b) const
    {
        return w < b.w;
    }
} ar[3000];

ll par[60];

ll fnd(ll n)
{
  //  cout << n << " " << par[n] << endl;
    if (par[n] == n)
        return n;
    return par[n] = fnd(par[n]);
}

bool vis[60];

void dfs(ll n)
{
  //  cout << n << endl;
    vis[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (vis[ed[n][i]] == 0)
            dfs(ed[n][i]);
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        ans = 0;

        k = 0;

        for (i = 1; i <= n; i++)
            ed[i].clear();

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                sl(x);

                if (x == 0)
                    continue;

                ed[i].pb(j);
                ed[j].pb(i);

                if (i == j)
                {
                    ans += x;
                    continue;
                }

                ar[k].u = i, ar[k].v = j, ar[k].w = x;
                k++;
            }

        memset(vis, 0, sizeof(vis));

        dfs(1);

        z = 0;

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                printf("Case %lld: -1\n", cs);
                z = 1;
                break;
            }
        }

        if (z == 1) continue;

        sort(ar, ar + k);

        for (i = 0; i <= n; i++)
            par[i] = i;


        for (i = 0; i < k; i++)
        {
            x = ar[i].u;
            y = ar[i].v;

       //     cout << i << " " << x << " " << y << endl;

            p = fnd(x);
            q = fnd(y);

       //     cout << i << " " << x << " " << y << " " << ar[i].w << " " << p << " " << q << " " << ans << endl;

            if (p != q)
            {
                par[p] = q;
            }
            else
            {
                ans += ar[i].w;
            }
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
