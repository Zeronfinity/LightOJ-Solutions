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
#define pll pair <long long, long long>
#define pb push_back

vector <ll> ed[100100];

ll vis[100100], vis1[100100], mx, cn, root, amx, hm, hmx;

void fnddfs(ll u, ll cn = 0)
{
 //   cout << "fnddfs " << u << " " << cn << " " << mx << " " << root << endl;
    if (cn > mx)
    {
        mx = cn;
        root = u;
    }

    vis[u] = 1;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == 0)
        {
            fnddfs(v, cn + 1);
        }
    }
}

void dfs(ll u, ll cn = 1)
{
   // cout << "dfs " << u << " " << cn << " " << amx << endl;
    hm++;
    if (cn > amx)
    {
        amx = cn;
    }

    vis1[u] = 1;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis1[v] == 0)
        {
            dfs(v, cn + 1);
        }
    }
}

ll tree[300010];

void create (ll node, ll b, ll e)
{
    if (b == e)
    {
        tree[node] = 0;
        return ;
    }

    ll left = 2*node;
    ll right = 2*node+1;

    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid+1, e);

    tree[node] = max(tree[left], tree[right]);
}

ll query (ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
        return tree[node];

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (b+e)/2;

    ll lmax = query(left, b, mid, i, j);
    ll rmax = query(right, mid+1, e, i, j);

   // cout << node << " " << b << " " << e << " " << lmax << " " << rmax << endl;

    return max(lmax, rmax);
}

void update (ll node, ll b, ll e, ll i, ll k)
{
    if (e < i || i < b)
        return ;

    if (i <= b && e <= i)
    {
        tree[node] = k;
        return ;
    }

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, k);
    update(right, mid+1, e, i, k);

   // cout << node << " " << b << " " << e << " " << lmax << " " << rmax << endl;

    tree[node] = max(tree[left], tree[right]);
}


int main ()
{
  //  freopen("inl.txt", "r", stdin);
  //  freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
        {
            ed[i].clear();
            vis[i] = vis1[i] = 0;
        }

        while(m--)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        create(1, 1, n);

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                hm = 0;

                mx = -1;
                fnddfs(i);

                amx = 0;

                dfs(root);
            //    cout << hm << " " << amx << endl;
                update(1, 1, n, hm, amx);
            }
        }

        printf("Case %lld:\n", cs);

     //   cout << amx << " " << hmx << endl;

        sl(q);

        while(q--)
        {
            sl(x);

            if (x <= n)
                y = query(1, 1, n, x, n);
            else y = 0;

            if (y == 0)
                printf("impossible\n");
            else if (x <= y)
                printf("%lld\n", x - 1);
            else printf("%lld\n", y - 1 + (x - y)*2 );
        }
    }

    return 0;
}
