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

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;
    return gcd(b, a%b);
}

#define tsz 150011

struct tnode
{
    ll sum, prop;
} tree[tsz*5];

void create(ll node, ll b, ll e)
{
    tree[node].sum = 0;
    tree[node].prop = -1;

    if (b == e) {
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);
}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry = -1)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
    {
        if (carry == -1)
            return tree[node].sum;
        else return carry*(e-b+1);
    }

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry==-1?tree[node].prop:carry);
    ll p2 = query(right, mid + 1, e, i, j, carry==-1?tree[node].prop:carry);

    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i, ll j, ll val, ll carry = -1)
{
    if (e < i || j < b)
    {
        if (carry != -1)
        {
            tree[node].sum = carry*(e-b+1);
            tree[node].prop = carry;
        }
        return;
    }
    if (i <= b && e <= j) {
        tree[node].sum = val*(e-b+1);
        tree[node].prop = val;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, j, val, carry==-1?tree[node].prop:carry);
    update(right, mid + 1, e, i, j, val, carry==-1?tree[node].prop:carry);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop = -1;
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
        sl(q);

        create(1, 1, n);

        printf("Case %lld:\n", cs);

        while(q--)
        {
            sl(x);

            if (x == 1)
            {
                sl(i);
                sl(j);
                i++;
                j++;
                sl(k);
                update(1, 1, n, i, j, k);
            }
            else
            {
                sl(i);
                sl(j);
                i++;
                j++;
                x = query(1, 1, n, i, j);

                if (x != 0)
                {
                    y = j - i + 1;
                    z = gcd(x, y);
                    x /= z;
                    y /= z;
                }
                else
                {
                    x = 0;
                    y = 1;
                }

                if (y  == 1)
                    printf("%lld\n", x);
                else printf("%lld/%lld\n", x,y);
            }
        }


    }

    return 0;
}
