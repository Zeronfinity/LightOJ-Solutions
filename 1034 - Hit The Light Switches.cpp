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

int in[10011], vis[10011], out[10011], nodes[10011];
map <int, vector <int> > ed;

void dfs(ll n)
{
    for (ll i = 0; i < ed[n].size(); i++)
    {
       ll v = ed[n][i];
       in[v]--;
       if (vis[v] == 0)
       {
           vis[v] = 1;
           dfs(v);
       }
    }
}

bool comp(int left, int right)
{
    return out[left] > out[right];
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
        sl(m);

        ed.clear();
        ans = 0;

        for (i = 1; i <= 10010; i++)
        {
            in[i] = out[i] = vis[i] = 0;
        }

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            ed[x].push_back(y);
            in[y]++;
            out[x]++;
        }


        for (i = 1; i <= n; i++)
        {
            nodes[i] = i;

            if (in[i] == 0 && vis[i] == 0)
            {
               // cout << "a " << i << " " << ans << endl;
                ans++;
                vis[i] = 1;
                dfs(i);
            }
        }

        sort(nodes + 1, nodes + n + 1, comp);

        for (i = 1; i <= n; i++)
        {
            if (vis[nodes[i]] == 0)
            {
             //   cout << "b " << nodes[i] << " " << out[i] << " " << ans << endl;
                ans++;
                dfs(nodes[i]);
            }
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
