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

#define tsz 200011

set <ll> st;

ll tree[tsz*4];

void create(ll node, ll b, ll e)
{
    tree[node] = 0;

    if (b == e) {
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j || tree[node] != 0)
    {
        return tree[node];
    }

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if (e < i || j < b)
        return;
    if (i <= b && e <= j) {
        tree[node] = val;
        return;
    }

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    if (tree[node] != 0)
    {
        tree[left] = tree[node];
        tree[right] = tree[node];
        tree[node] = 0;
    }

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
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
        sl(m);

        st.clear();

        create(1, 1, 2*m);

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            update(1, 1, 2*m, x, y, i);
        }

        for (i = 1; i <= 2*m; i++)
        {
            x = query(1, 1, 2*m, i, i);
            if (x != 0)
                st.insert(x);

         //   cout << i << " " << x << endl;
        }

        printf("Case %lld: %lld\n", cs, (ll) st.size());
    }

    return 0;
}
