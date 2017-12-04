#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)

#define md 1000000007

ll srt[200000], ar[200000];
map <ll, ll> pos;

ll tree[400000];

void create(ll n, ll b, ll e)
{
    tree[n] = 0;

    if (b == e)
        return ;

    ll l = 2*n;
    ll r = l + 1;
    ll mid = (b + e)/2;

    create(l, b, mid);
    create(r, mid + 1, e);
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if (j < i) return 0;

    if (j < b || e < i)
        return 0;

    if (i <= b && e <= j)
    {
        return tree[n];
    }

    ll l = 2*n;
    ll r = l + 1;
    ll mid = (b + e)/2;

    ll x = query(l, b, mid, i, j);
    ll y = query(r, mid + 1, e, i, j);

    return x + y;
}

void update(ll n, ll b, ll e, ll i, ll k)
{
 //cout << n << " " << b << " " << e << " " << i << " " << k << endl;

    if (i < b || e < i)
        return ;

    if (i <= b && e <= i)
    {
        tree[n] = (tree[n] + k)%md;
        return ;
    }

    ll l = 2*n;
    ll r = l + 1;
    ll mid = (b + e)/2;

    update(l, b, mid, i, k);
    update(r, mid + 1, e, i, k);

    tree[n] = (tree[l] + tree[r])%md;
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        pos.clear();
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
            srt[i] = ar[i];
        }

        sort(srt + 1, srt + n + 1);

        for (i = 1; i <= n; i++)
        {
           // cout << srt[i] << " " << i << endl;
            pos[srt[i]] = i;
        }

        cout << cs << " " << n << " " << ar[n] << endl;

        create(1, 1, n);

        for (i = 1; i <= n; i++)
        {
            p = pos[ar[i]];
            q = query(1, 1, n, 1, p - 1);
            update(1, 1, n, p, (q + 1)%md);
        //    cout << i << " " << ar[i] << " " << p << " " << q << " " << tree[1] << endl;
        }

        printf("Case %lld: %lld\n", cs, tree[1]);
    }

    return 0;
}
