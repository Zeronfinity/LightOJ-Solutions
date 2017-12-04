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

int ar[100010];

int tree[600010];

int prev[100010], loc[100010];

struct node
{
    ll x, y, r, in;
} que[60000];

bool comp (node a, node b)
{
    if (a.x < b.x)
        return true;
    else return false;
}

bool comp2(node a, node b)
{
    if (a.in < b.in)
        return true;
    else return false;
}

void create(ll n, ll b, ll e)
{
 //   cout << n << " " << b << " " << e << endl;

    if (b == e)
    {
        tree[n] = ar[b];
        return ;
    }

    ll l, r, m;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;
    create(l, b, m);
    create(r, m + 1, e);
    tree[n] = tree[l] + tree[r];

 //   cout << n << " " << b << " " << e << " " << tree[n] << " " << tree[l] << " " << tree[r] << endl;
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
  //  cout << n << " " << b << " " << e << " " << i << " " << j << endl;
    if (j < b || e < i)
        return 0;


    if (i <= b && e <= j)
    {
        return tree[n];
    }

    ll l, r, m, ab, cd;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    ab = query(l, b, m, i, j);
    cd = query(r, m + 1, e, i, j);
 //   cout << n << " " << b << " " << e << " " << m << " " << ab << " " << cd << endl;
    return (ab + cd);
}

void update(ll n, ll b, ll e, ll i, ll x)
{
    if (i < b || e < i)
        return ;

    if (i <= b && e <= i)
    {
        tree[n] = x;
        return ;
    }

    ll l, r, m;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    update(l, b, m, i, x);
    update(r, m + 1, e, i, x);

    tree[n] = tree[l] + tree[r];
}

int main ()
{
   // freopen("out.txt", "w", stdout);
    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        printf("Case %lld:\n", cs);
        sl(n);
        sl(q);

        for (i = 0; i <= 100005; i++)
        {
            prev[i] = loc[i] = ar[i] = 0;
        }

    //    for (i = 0; i <= 600000; i++)
      //  {
        //    tree[i] = 0;
       // }

        for (i = 1; i <= n; i++)
        {
            sl(x);

            if (prev[x] == 0)
            {
                prev[x] = i;
                ar[i] = 1;
            }
            else
            {
                loc[prev[x]] = i;   // loc is next position
                prev[x] = i;
            }

        }

    //    for (i = 1; i <= n; i++)
      //      cout << ar[i] << " ";
        //cout << endl;

        create(1, 1, n);

        //cout << tree[1] << endl;

        for (i = 1; i <= q; i++)
        {
           sl(que[i].x);
           sl(que[i].y);
           que[i].in = i;
        }

        sort(que + 1, que+ q + 1, comp);

        j = 1;

        for (i = 1; i <= q; i++)
        {
            while (j < que[i].x)
            {
                if (loc[j] != 0)
                {
                    update(1, 1, n, loc[j], 1);
                }
                j++;
            }
       //     cout << que[i].x << " " << que[i].y << endl;
            que[i].r = query(1, 1, n, que[i].x, que[i].y);
        }

        sort(que + 1, que+ q + 1, comp2);

        for (i = 1; i <= q; i++)
        {
            printf("%lld\n", que[i].r);
        }
    }

    return 0;
}
