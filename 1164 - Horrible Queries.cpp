#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll prop = 0, s;
} tr[300000];

void create(ll n, ll b, ll e)
{
    tr[n].s = 0;
    if (b == e)
        return ;
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    create(l, b, m);
    create(r, m+1, e);
}

void update(ll n, ll b, ll e, ll i, ll j, ll v)
{
    if (b > j || e < i)
        return ;
    if (i <= b && e <= j)
    {
        tr[n].s += v*(e - b + 1);
        tr[n].prop += v;
        return ;
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    update(l, b, m, i, j, v);
    update(r, m+1, e, i, j, v);
    tr[n].s = tr[l].s + tr[r].s + tr[n].prop*(e-b+1);
 }

ll query(ll n, ll b, ll e, ll i, ll j, ll c = 0)
{
    if (b > j || e < i)
        return 0;
    if (i <= b && e <= j)
    {
    //    cout << b << " " << e << " " << tr[n].s << " " << c << endl;
        return tr[n].s + c*(e-b+1);
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    return (query(l, b, m, i, j, c + tr[n].prop) + query(r, m+1, e, i, j, c + tr[n].prop));
}

void reset(ll n, ll b, ll e)

{
    if (b == e)
    {
        tr[n].prop = 0;
        return ;
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    reset(l, b, m);
    reset(r, m+1, e);
    tr[n].prop = 0;
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, v;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        printf("Case %lld:\n", cs);
        cin >> n >> q;
        create(1, 1, n);
        while(q--)
        {
            scanf("%lld", &k);
            if (k == 0)
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                x++;
                y++;
                update(1, 1, n, x, y, v);
            }
            else
            {
                scanf("%lld %lld", &x, &y);
                x++;
                y++;
                printf("%lld\n", query(1, 1, n, x, y));
            }
        }
        reset(1, 1, n);
    }

    return 0;
}
