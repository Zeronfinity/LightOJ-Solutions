#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ar[100010];
ll tree[300010];

void create (ll node, ll b, ll e)
{
    if (b == e)
    {
        tree[node] = ar[b];
        return ;
    }

    ll left = 2*node;
    ll right = 2*node+1;

    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);
}

ll query (ll node, ll b, ll e, ll sb, ll se)
{
    if (sb > e || se < b)
        return 1000000;

    if (b >= sb && e <= se)
        return tree[node];

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (b+e)/2;

    ll lmin = query(left, b, mid, sb, se);
    ll rmin = query(right, mid+1, e, sb, se);

   // cout << node << " " << b << " " << e << " " << lmin << " " << rmin << endl;

    return min(lmin, rmin);
}

int main ()
{
    ll t, cs, i, j, n, q, x, y;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        printf("Case %lld:\n", cs);

        scanf("%lld %lld", &n, &q);

        for (i = 1; i <= n; i++)
            scanf("%lld", &ar[i]);

        create(1, 1, n);

        for (i = 1; i <= q; i++)
        {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }

    }

    return 0;
}
