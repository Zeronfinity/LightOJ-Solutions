#include <stdio.h>
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

vector <ll> ed[30000];

ll vis[30000], yo[30000], in[30000], out[30000];

void dfs(ll n)
{
    vis[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (vis[ed[n][i]] == 0)
        {
            dfs(ed[n][i]);
        }
    }
}


int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, ans, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        ans = 0;

        for (i = 0; i < n; i++)
        {
            ed[i].clear();
            out[i] = yo[i] = in[i] = 0;
            vis[i] = 0;
        }

        for (i = 1; i <= n-1; i++)
        {
            sl(x);
            sl(y);
            ed[x].push_back(y);
            out[x]++;
            in[y]++;
        }


        for (i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                yo[i] = out[i];
                dfs(i);
            }
        }

        for (i = 0; i < n; i++)
        {
            ans += yo[i];
        }

        printf("Case %lld: %lld\n", cs, ans);

        ins.clear();
    }

    return 0;
}
