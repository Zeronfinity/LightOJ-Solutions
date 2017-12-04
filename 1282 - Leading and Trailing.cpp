#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%llu", &n)
#define si(n) scanf("%d", &n)


ll pwrt(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwrt(b, p/2)%1000;

    if (p%2 == 0)
        return (x%1000*x%1000)%1000;
    else return ((x%1000*x%1000)%1000*b%1000)%1000;
}


int main ()
{
    ll cs, t, i, j, k, n, y, ans, q, p;
    double x;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        sl(p);

        x = p*log10( (double) n);

        x = x - floor(x);

        printf("Case %lld: %03lld %03lld\n", cs, (ll) pow(10.0, x + 2), pwrt(n, p));
    }

    return 0;
}
