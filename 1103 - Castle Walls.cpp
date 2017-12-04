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

pll blue[100100], red[100100];

#define tsz 200100

ll tree[5*tsz];

void create(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = 0;
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
        return tree[node];

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

 //   cout << "query " << node << " " << b << " " << e << " " << i << " " << j << " " << p1 + p2 << endl;

    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if (e < i || i < b)
        return;
    if (i <= b && e <= i) {
        tree[node] = val;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);
    tree[node] = tree[left] + tree[right];
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
        {
            sl(blue[i].fr);
            sl(blue[i].sd);
        }

        for (i = 1; i <= m; i++)
        {
            sl(red[i].fr);
            sl(red[i].sd);
        }

        sort(blue + 1, blue + n + 1);
        sort(red + 1, red + m + 1);

        ans = 0;

        create(1, 1, n+m);

        for (j = 1, i = 1; j <= m; j++)
        {
            for (; blue[i].fr < red[j].fr && i <= n; i++)
            {
           //     cout << "updating " << i << " " << blue[i].sd << endl;
                update(1, 1, n+m, blue[i].sd, 1);
            }

            x = query(1, 1, n+m, red[j].sd, n+m);
            ans += x;
           // cout << j << " " << i << " " << x << " " << ans << endl;
        }

        create(1, 1, n+m);

        for (j = m, i = n; j >= 1; j--)
        {
            for (; blue[i].fr > red[j].fr && i >= 1; i--)
            {
                update(1, 1, n+m, blue[i].sd, 1);
            }

            ans += query(1, 1, n+m, 1, red[j].sd);
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
