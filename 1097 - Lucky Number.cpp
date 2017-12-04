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

#define tsz 1429441

ll tree[5*tsz];

void create(ll node, ll b, ll e)
{
    if (b == e) {
        if (b%2 != 0 && (b+1)%6 != 0)
        {
    //        cout << b << endl;
            tree[node] = 1;
           // getchar();
        }
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
    if (b == e)
        return b;

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    if (k <= tree[left])
    {
        return query(left, b, mid, k);
    }
    else return query(right, mid + 1, e, k - tree[left]);
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

ll dp[100010];

deque <ll> dq;

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    create(1, 1, tsz);

    k = 3;

    while(k < tsz)
    {
        x = query(1, 1, tsz, k);
     //   cout << k << " " << x << endl;

        if (x > tsz)
            break;

        for (i = x; i <= tsz; i += x)
        {
            y = query(1, 1, tsz, i);
     //       cout << i << " " << y << endl;
     //       getchar();
            dq.pb(y);
        }

        while(!dq.empty())
        {
            update(1, 1, tsz, dq[0], 0);
            dq.pop_front();
        }

        k++;
    }

//    for (i = 1; i <= 10; i++)
//    {
//        cout << kth(1, tsz, i) << endl;
//    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        if (dp[n] == 0)
            dp[n] = query(1, 1, tsz, n);

        printf("Case %lld: %lld\n", cs, dp[n]);
    }

    return 0;
}
