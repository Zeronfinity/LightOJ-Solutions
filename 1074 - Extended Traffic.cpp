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

ll bus[300];

ll dis[300];

vector <ll> fr, to;

bool imp[300];

void belman(ll src, ll n)
{
    dis[src] = 0;

    ll i;

    for (i = 0; i < n-1; i++)
    {
        bool flag = false;
        for (ll j = 0; j < fr.size(); j++)
        {
            ll d = bus[to[j]] - bus[fr[j]];

            d = d*d*d;

            if (dis[fr[j]] == LLONG_MAX)
                continue;

            if (dis[fr[j]] + d < dis[to[j]])
            {
                dis[to[j]] = dis[fr[j]] + d;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }

    for (ll j = 1; j <= n; j++)
        imp[j] = false;

    for (ll j = 0; j < fr.size(); j++)
    {
        ll d = bus[to[j]] - bus[fr[j]];

        d = d*d*d;

        if (dis[fr[j]] == LLONG_MAX)
            continue;

        if (dis[fr[j]] + d < dis[to[j]])
        {
            dis[to[j]] = dis[fr[j]] + d;
            imp[to[j]] = true;
        }
    }
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
   //  freopen("outl.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        fr.clear();
        to.clear();

        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(bus[i]);
        }

        sl(m);

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            fr.pb(x);
            to.pb(y);
        }

        for (i = 1; i <= n; i++)
        {
            dis[i] = LLONG_MAX;
        }

        belman(1, n);

//        for (i = 1; i <= n; i++)
  //          cout << i << " " << dis[i] << endl;

        printf("Case %lld:\n", cs);

        sl(q);

        while(q--)
        {
            sl(y);

            if (dis[y] >= 3 && dis[y] != LLONG_MAX && imp[y] == false)
                printf("%lld\n", dis[y]);
            else printf("?\n");
        }
    }

    return 0;
}
