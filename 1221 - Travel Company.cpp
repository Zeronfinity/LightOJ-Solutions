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

vector <ll> fr, to, cost;

ll dis[200];

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, r, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(r);
        sl(p);

        for (i = 0; i <= n; i++)
            dis[i] = 0;

        fr.clear();
        to.clear();
        cost.clear();

        ll I, E;

        for (i = 0; i < r; i++)
        {
            sl(x);
            sl(y);
            sl(I);
            sl(E);
            fr.pb(x);
            to.pb(y);
            cost.pb(I - p*E);
        }


        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < r; j++)
            {
                ll u = fr[j], v = to[j], d = cost[j];

                if (dis[u] + d > dis[v])
                    dis[v] = dis[u] + d;
            }
        }

        bool cycle = false;

        for (j = 0; j < r; j++)
        {
            ll u = fr[j], v = to[j], d = cost[j];

            if (dis[u] + d > dis[v])
            {
                cycle = true;
                break;
            }
        }

        if (cycle == true)
            printf("Case %lld: YES\n", cs);
        else printf("Case %lld: NO\n", cs);
    }

    return 0;
}
