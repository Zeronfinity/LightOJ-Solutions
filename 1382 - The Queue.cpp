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

ll in[1010], vis[1010], mod = 1000000007, fact[1010];

ll pwr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2);
    x = (x*x)%mod;

    if (p%2 == 0)
        return x;
    else return (b*x)%mod;
}

vector <ll> ed[1010];



pll dfs(ll u)
{
    vis[u] = 1;

    pll p;

    ll cn = 1, ans = 1;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll ad = ed[u][i];
        if (vis[ad] == 0)
        {
            p = dfs(ad);
            cn += p.sd;
            ans = (ans*pwr(fact[p.sd], mod - 2))%mod;
            ans = (ans*p.fr)%mod;
        }
    }

    ans = (ans*fact[cn-1])%mod;

    return pll(ans, cn);
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    fact[0] = 1;

    for (i = 1; i <= 1008; i++)
        fact[i] = (fact[i-1]*i)%mod;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(m);

        z = m-1;

        while(z--)
        {
            sl(x);
            sl(y);
            in[y]++;
            ed[x].pb(y);
        }

        for (i = 1; i <= m; i++)
        {
            if (in[i] == 0)
                ans = dfs(i).fr;
        }

        for (i = 1; i <= m; i++)
        {
            in[i] = vis[i] = 0;
            ed[i].clear();
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
