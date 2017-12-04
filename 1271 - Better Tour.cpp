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

#define nsz 50010 //take maximum nodes + some number
ll lv[nsz];
vector <ll> ed[nsz];
ll n;

deque <ll> dq;

ll par[nsz];

void BFS(ll src)
{
    ll i, j, ad, u;

    for(i = 0; i <= 50001; i++){
        lv[i] = -1;
        par[i] = i;
    }


    lv[src] = 0;

    dq.pb(src);

    while(!dq.empty())
    {
        ll u = dq[0];
        dq.pop_front();
        for(i=0; i<ed[u].size(); i++)
        {
            ad = ed[u][i];
            if(lv[ad] == -1)
            {
                lv[ad] = lv[u] + 1;
                par[ad] = u;
                dq.pb(ad);
            }
        }
    }
}

ll a[nsz];

void print(ll u)
{
  //  cout << u << " print " << par[u] << endl;
    if (u == a[1])
    {
        printf("%lld", u);
        return ;
    }

    print(par[u]);

    printf(" %lld", u);

}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 1; i <= 50001; i++)
            ed[i].clear();

        for (i = 1; i <= n; i++)
        {
            sl(a[i]);

            if (i != 1)
            {
                ed[a[i-1]].pb(a[i]);
                ed[a[i]].pb(a[i-1]);
            }
        }

        for (i = 1; i <= 50000; i++)
        {
            sort(ed[i].begin(), ed[i].end());
        }

        BFS(a[1]);
     //   cout << lv[a[n]] << endl;

        printf("Case %lld:\n", cs);
        print(a[n]);
        printf("\n");
    }

    return 0;
}
