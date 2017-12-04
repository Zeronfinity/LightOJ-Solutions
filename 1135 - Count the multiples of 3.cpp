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

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

struct node
{
    ll cnt[3], p;
} tree[400000];



void create(ll n, ll b, ll e)
{
    tree[n].p = 0;
    if (b == e)
    {
        tree[n].cnt[0] = 1;
        tree[n].cnt[1] = 0;
        tree[n].cnt[2] = 0;
        return ;
    }

    ll l, r, m;

    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    create(l, b, m);
    create(r, m + 1, e);

    tree[n].cnt[0] = tree[l].cnt[0] + tree[r].cnt[0];
    tree[n].cnt[1] = tree[l].cnt[1] + tree[r].cnt[1];
    tree[n].cnt[2] = tree[l].cnt[2] + tree[r].cnt[2];
}

void update(ll n, ll b, ll e, ll i, ll j)
{
    ll temp[3];
    if (j < b || e < i)
        return ;

    if (i <= b && e <= j)
    {
        temp[0] = tree[n].cnt[0];
        temp[1] = tree[n].cnt[1];
        temp[2] = tree[n].cnt[2];
        tree[n].cnt[0] = temp[2];
        tree[n].cnt[1] = temp[0];
        tree[n].cnt[2] = temp[1];
        tree[n].p++;
        return ;
    }

    ll l, r, m;

    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    update(l, b, m, i, j);
    update(r, m + 1, e, i, j);

    tree[n].cnt[0] = tree[l].cnt[0] + tree[r].cnt[0];
    tree[n].cnt[1] = tree[l].cnt[1] + tree[r].cnt[1];
    tree[n].cnt[2] = tree[l].cnt[2] + tree[r].cnt[2];
    temp[0] = tree[n].cnt[0];
    temp[1] = tree[n].cnt[1];
    temp[2] = tree[n].cnt[2];
    tree[n].cnt[(2+tree[n].p)%3] = temp[2];
    tree[n].cnt[(0+tree[n].p)%3] = temp[0];
    tree[n].cnt[(1+tree[n].p)%3] = temp[1];
}

ll query(ll n, ll b, ll e, ll i, ll j, ll carry = 0)
{
    ll temp[3];
    if (j < b || e < i)
        return 0;

    if (i <= b && e <= j)
    {
        if ((2+carry)%3 == 0)
            return tree[n].cnt[2];
        if ((1+carry)%3 == 0)
            return tree[n].cnt[1];
        if ((0+carry)%3 == 0)
            return tree[n].cnt[0];
    }

    ll l, r, m, ab, cd;

    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    ab = query(l, b, m, i, j, carry + tree[n].p);
    cd = query(r, m + 1, e, i, j, carry + tree[n].p);

    return ab + cd;
}


int main ()
{
  //  freopen("out.txt", "w", stdout);
    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        printf("Case %lld:\n", cs);
        sl(n);
        sl(q);

        create(1, 1, n);

        for (i = 1; i <= q; i++)
        {
            sl(k);
            sl(x);
            sl(y);
            x++;
            y++;
            if (k == 0)
            {
                update(1, 1, n, x, y);
            }
            else
            {
                printf("%lld\n", query(1, 1, n, x, y));
            }
        }
    }

    return 0;
}
