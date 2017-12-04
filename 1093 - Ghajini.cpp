#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[100010];
struct node
{
    int mx;
    int mn;
} tr[400010];;

void create (ll n, ll b, ll e)
{
    if (b == e)
    {
        tr[n].mx = a[b];
        tr[n].mn = a[b];
        return ;
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    create(l, b, m);
    create(r, m + 1, e);

    if (tr[l].mx >= tr[r].mx)
        tr[n].mx = tr[l].mx;
    else tr[n].mx = tr[r].mx;

    if (tr[l].mn <= tr[r].mn)
        tr[n].mn = tr[l].mn;
    else tr[n].mn = tr[r].mn;
}

int querymx (ll n, ll b, ll e, ll i, ll j)
{
    if (b > j || e < i)
        return 0;

    if (i <= b && e <= j)
    {
        return tr[n].mx;
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    int lm = querymx(l, b, m, i, j);
    int rm = querymx(r, m + 1, e, i, j);

    if (lm >= rm)
        return lm;
    else return rm;
}

int querymn (ll n, ll b, ll e, ll i, ll j)
{
    if (b > j || e < i)
        return 100000010;

    if (i <= b && e <= j)
    {
        return tr[n].mn;
    }
    ll l = 2*n;
    ll r = 2*n + 1;
    ll m = (b+e)/2;

    int lm = querymn(l, b, m, i, j);
    int rm = querymn(r, m + 1, e, i, j);

    if (lm <= rm)
        return lm;
    else return rm;
}

int main ()
{
    ll cs, t, i, j, k, n, m, d, dm, c;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        dm = 0;
        cin >> n >> d;

        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        create(1, 1, n);

        for (i = 1; i + d - 1 <= n; i++)
        {
           c = querymx(1, 1, n, i, i+d-1) - querymn(1, 1, n, i, i+d-1);
           if (c > dm)
            dm = c;
        }
        printf("Case %lld: %lld\n", cs, dm);
    }

    return 0;
}
