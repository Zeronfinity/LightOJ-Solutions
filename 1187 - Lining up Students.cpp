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

ll a[100100];

#define tsz 1000001

ll tree[4*tsz];

void create(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = 1;
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll b, ll e, ll k)
{
    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = tree[left];
    ll p2 = tree[right], x;

  //  cout << node << " " << b << " " << e << " "<< k << " " << p1 << " " << p2 << endl;

    if (b == e)
        return b;

    if (k <= p2)
    {
        x = query(right, mid + 1, e, k);
    }
    else
        x = query(left, b, mid, k - p2);

    return x;
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

        for (i = 1; i <= n; i++)
        {
            sl(a[i]);
        }

        create(1, 1, n);

        for (i = n; i >= 1; i--)
        {
            x = query(1, 1, n, a[i] + 1);
           // cout << i << " " << x << endl;
            update(1, 1, n, x, 0);
        }

        printf("Case %lld: %lld\n", cs, x);
    }

    return 0;
}
