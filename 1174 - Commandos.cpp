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

map <ll, vector<ll> > ed;
deque <ll> dq;

ll lv1[200], lv2[200];

void bfs1(ll src)
{
    dq.pb(src);
    lv1[src] = 0;

    while(dq.empty() == false)
    {
        ll u = dq[0];
        dq.pop_front();

        for (ll i = 0; i < ed[u].size(); i++)
        {
            ll v = ed[u][i];
            if (lv1[v] == -1)
            {
                lv1[v] = lv1[u] + 1;
                dq.pb(v);
            }
        }
    }
}

void bfs2(ll src)
{
    dq.pb(src);
    lv2[src] = 0;

    while(dq.empty() == false)
    {
        ll u = dq[0];
        dq.pop_front();

        for (ll i = 0; i < ed[u].size(); i++)
        {
            ll v = ed[u][i];
            if (lv2[v] == -1)
            {
                lv2[v] = lv2[u] + 1;
                dq.pb(v);
            }
        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, s, d;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 0; i < n; i++)
        {
            lv1[i] = lv2[i] = -1;
        }

        ed.clear();

        while(m--)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        sl(s);
        sl(d);

        bfs1(s);
        bfs2(d);

        ans = 0;

        for (i = 0; i < n; i++)
        {
            if (lv1[i] + lv2[i] > ans)
                ans = lv1[i] + lv2[i];
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
