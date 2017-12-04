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

char g;

ll val;

#define tsz 250000
ll tree[tsz*6], lt[tsz*6], rt[tsz*6], tp[tsz*6];

void create(ll node, ll b, ll e)
{
    tree[node] = 0;
    lt[node] = 0;
    rt[node] = 0;
    tp[node] = 0;

    if (b == e)
    {
        return ;
    }
    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);
}

void lazy(ll node, ll b, ll e)
{
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

//    if (1 <= b && e <= 8)
//        cout << node << " blazy " << b << " " << e << " " << lt[left] << " " << tree[left] << " " << tree[right] << " " << tree[node] << endl;

    if (tp[node] != 3)
    {
        if (tp[left] == 3 && b != mid)
        {
            lazy(left, b, mid);
        }
        if (tp[right] == 3 && e != mid + 1)
        {
            lazy(right, mid + 1, e);
        }

        lt[left] += lt[node];
        rt[right] += rt[node];

        ll d = (rt[node] - lt[node])/(e-b);

        rt[left] += lt[node] + (mid-b)*d;
        lt[right] += lt[node] + (mid+1-b)*d;

        tp[left] = tp[right] = tp[node];
    }
    else
    {
        lt[left] = lt[node];
        rt[right] = rt[node];

        ll d = (rt[node] - lt[node])/(e-b);

        rt[left] = lt[node] + (mid-b)*d;
        lt[right] = lt[node] + (mid+1-b)*d;

        tp[left] = tp[right] = 3;
        tree[left] = tree[right] = 0;
    }

    lt[node] = 0;
    rt[node] = 0;
    tp[node] = 0;

    tree[node] = tree[left] + ((lt[left] + rt[left])*(mid - b + 1))/2 + tree[right] + ((lt[right] + rt[right])*(e - mid))/2;
//    if (1 <= b && e <= 8)
//    cout << node << " lazy " << b << " " << e << " " << lt[left] << " " << tree[left] << " " << tree[right] << " " << tree[node] << endl;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return 0;
    if (i <= b && e <= j)
    {
     //   cout << node << " query " << b << " " << e << " " << lt[node] << " " << rt[node] << " " << tree[node] << endl;
        return tree[node] + ((lt[node] + rt[node])*(e - b + 1))/2;
    }

    if (tp[node] != 0)
        lazy(node, b, e);

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i, ll j, ll type)
{
    if (e < i || j < b)
        return;
    if (i <= b && e <= j)
    {
   //     cout << node << " bupdate " << type << " " << b << " " << e << " " << lt[node] << " " << rt[node] << " " << tree[node] << endl;

        if (type == 1)
        {
            if (tp[node] == 3 && b != e)
            {
                lazy(node, b, e);
            }

            lt[node] += b - i + 1;
            rt[node] += e - i + 1;
        }
        else if (type == 2)
        {
            if (tp[node] == 3 && b != e)
            {
                lazy(node, b, e);
            }

            lt[node] += j - b + 1;
            rt[node] += j - e + 1;
        }
        else
        {
            lt[node] = val;
            rt[node] = val;

            tree[node] = 0;
        }

  //      cout << node << " update " << type << " " << b << " " << e << " " << lt[node] << " " << rt[node] << " " << tree[node] << endl;

        tp[node] = type;

        return;
    }

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    if (tp[node] != 0)
        lazy(node, b, e);

    update(left, b, mid, i, j, type);
    update(right, mid + 1, e, i, j, type);

//    if (1 <= b && e <= 8)
//    cout << node << " update3 " << " " << b << " " << e << " " << tree[left] << " " << tree[right] << " " << tree[node] << endl;

    tree[node] = tree[left] + ((lt[left] + rt[left])*(mid - b + 1))/2 + tree[right] + ((lt[right] + rt[right])*(e - mid))/2;
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

        create(1, 1, tsz);

        printf("Case %lld:\n", cs);

        for (i = 1; i <= m; i++)
        {
            scanf(" %c", &g);

            sl(x);
            sl(y);

            if (g == 'A')
            {
                update(1, 1, tsz, x, y, 1);
            }
            else if (g == 'B')
            {
                update(1, 1, tsz, x, y, 2);
            }
            else if (g == 'C')
            {
                sl(val);
                update(1, 1, tsz, x, y, 3);
            }
            else
            {
                printf("%lld\n", query(1, 1, tsz, x, y));
            }
        }

    }

    return 0;
}
