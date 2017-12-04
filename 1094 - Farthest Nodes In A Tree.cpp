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

map <ll, vector <ll> > ed;
map < ll, map <ll, ll> > cost;

ll leaf, mx, ans, visited[30010];

void DFS1(ll n, ll s = 0)
{
    visited[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (visited[ed[n][i]] == 0)
        {
            visited[ed[n][i]] = 1;
            if (s + cost[n][ed[n][i]] > mx)
            {
                mx = s + cost[n][ed[n][i]];
                leaf = ed[n][i];
            }

            DFS1(ed[n][i], s + cost[n][ed[n][i]]);
        }
    }
}

void DFS(ll n, ll s = 0)
{
    visited[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (visited[ed[n][i]] == 0)
        {
            visited[ed[n][i]] = 1;

            if (s + cost[n][ed[n][i]] > ans)
            {
                ans = s + cost[n][ed[n][i]];
            }

            DFS(ed[n][i], s + cost[n][ed[n][i]]);
        }
    }
}



int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        mx = 0;
        ed.clear();
        cost.clear();
        sl(n);
        for (i = 1; i <= n-1; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            ed[x].push_back(y);
            ed[y].push_back(x);

            cost[x][y] = z;
            cost[y][x] = z;

 //           cout << i << " " << x << " " <<  y << " " << z << endl;
        }

        leaf = 0;

        for (i = 0; i <= 30009; i++)
        {
            visited[i] = 0;
        }

        DFS1(0);

        for (i = 0; i <= 30009; i++)
        {
            visited[i] = 0;
        }

//        cout << leaf << endl;


        ans = 0;

        DFS(leaf);

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
