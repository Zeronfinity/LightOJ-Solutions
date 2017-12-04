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

ll x[50010], y[50010];

set <ll> :: iterator sit;
set <ll> st;
map <ll, ll> mp;

ll quer[50010];

#define tsz 150011

struct tnode
{
    ll sum, prop;
} tree[tsz*5];

void create(ll node, ll b, ll e)
{
    tree[node].prop = 0;
    tree[node].sum = 0;
    if (b == e) {
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
    {
        return tree[node].sum + carry*(e - b + 1);
    }

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if (e < i || j < b)
        return;
    if (i <= b && e <= j) {
        tree[node].sum += val*(e-b+1);
        tree[node].prop += val;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop*(e-b+1);
}


int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, z, ans, q, m, n, limit;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(q);

        for (i = 1; i <= n; i++)
        {
            sl(x[i]);
            sl(y[i]);
            st.insert(x[i]);
            st.insert(y[i]);
        }

        for (i = 1; i <= q; i++)
        {
            sl(quer[i]);
            st.insert(quer[i]);
        }

        limit = 0;

        for (sit = st.begin(); sit != st.end(); sit++)
        {
            mp[(*sit)] = ++limit;
        }

        create(1, 1, limit);

        for (i = 1; i <= n; i++)
        {
        //    cout << mp[x[i]] << " " << mp[y[i]] << endl;
            update(1, 1, limit, mp[x[i]], mp[y[i]], 1);
        }

        printf("Case %lld:\n", cs);

        for (i = 1; i <= q; i++)
        {
        //    cout << mp[quer[i]] << endl;
            printf("%lld\n", query(1, 1, limit, mp[quer[i]], mp[quer[i]]));
        }

        st.clear();
        mp.clear();
    }

    return 0;
}
