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

ll pre[100010], pst[100010], sum, vis[100010], num;

map <ll, vector <ll> > ed;

ll DFS(ll n, ll s = 0)
{
    pre[n] = s;
    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll v = ed[n][i];

        if (vis[v] == 0)
        {
            vis[v] = 1;

            pst[n] += DFS(v, s + 1);
        }
    }

//    cout << n << " " << pre[n] << " " << pst[n] << " " << sum << endl;

    sum += num - pre[n] - pst[n];

    return pst[n];
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
        sl(num);

        for (i = 1; i <= num-1; i++)
        {
            sl(x);
            sl(y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        sum = 0;

        for (i = 1; i <= num; i++)
        {
            pst[i] = 1;
            vis[i] = pre[i] = 0;
        }

        vis[1] = 1;
        DFS(1);

        ans = 0;

        for (i = 2; i <= num; i++)
        {
            if (vis[i] == 1)
                ans++;
        }

        if (num == 1)
            ans = sum = 0;

        printf("Case %lld: %lld %lld\n", cs, ans, sum/2);
    }

    return 0;
}
