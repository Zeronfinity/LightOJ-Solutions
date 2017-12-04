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

map <int, vector <int> > ed;
map <int, vector <int> > :: iterator mit;

int vis[20010];
deque <int> dq;

ll BFS(ll src)
{
    ll mx1 = 0, mx0 = 0;

    vis[src] = 1;
    mx1++;

    dq.push_back(src);

    while(dq.empty() == false)
    {
        ll u = dq[0];
        dq.pop_front();

      //  cout << u << " " << ed[u].size() << endl;

        for (ll i = 0; i < ed[u].size(); i++)
        {
            ll v = ed[u][i];

            if (vis[v] == -1)
            {
                vis[v] = (vis[u] + 1)%2;
                if (vis[v] == 1)
                    mx1++;
                else mx0++;

                dq.push_back(v);
            }
        }
    }

    return max(mx1, mx0);
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
        ed.clear();
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(x);
            sl(y);

            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        for (i = 0; i <= 20009; i++)
            vis[i] = -1;

        ans = 0;

        for (mit = ed.begin(); mit != ed.end(); mit++)
        {
            if (vis[mit->first] == -1)
                ans += BFS(mit->first);
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
