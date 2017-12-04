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

ll n;

struct edg
{
    ll u, v, w;
    bool operator < (const edg& b) const
    {
        return w < b.w;
    }
} ed[6010];

ll par[210];
ll fnd(ll n)
{
    if (par[n] == n)
        return n;
    return par[n] = fnd(par[n]);
}

ll edsz;

ll minst()
{
    sort(ed, ed + edsz);

    for (ll i = 0; i <= n; i++)
        par[i] = i;

    ll ans = 0, taken = 0, del = -1;

    for (ll i = 0; i < edsz; i++)
    {
        ll x = ed[i].u;
        ll y = ed[i].v;

        ll p = fnd(x);
        ll q = fnd(y);

        if (p != q)
        {
            par[p] = q;
            ans += ed[i].w;
            taken++;
            // this edge is in MST
        }
        else
        {
            del = i;
        }
    }

    if (del != -1)
        ed[del] = ed[--edsz];

    if (taken == n-1)
        return ans;
    else return -1;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, q, m, h, w, ag, ans, G, S;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        printf("Case %lld:\n", cs);

        edsz = 0;

        for (i = 1; i <= m; i++)
        {
            sl(ed[edsz].u);
            sl(ed[edsz].v);
            sl(ed[edsz].w);
            edsz++;

            x = minst();

            printf("%lld\n", x);
        }
    }

    return 0;
}

