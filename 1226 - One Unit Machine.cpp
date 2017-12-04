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
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

ll mod = 1000000007;

ll f[1000100];

ll pwr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2);

    x = (x*x)%mod;

    if (p%2 == 0)
        return x;
    else return (b*x)%mod;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    ll sum;

    f[0] = 1;

    for (i = 1; i <= 1000010; i++)
        f[i] = (f[i-1]*i)%mod;

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        sum = 0;
        ans = 1;

        for (i = 1; i <= n; i++)
        {
            sl(x);

            ans = (((((ans*f[sum + x - 1])%mod)*pwr(f[x - 1], mod - 2))%mod)*pwr(f[sum], mod-2))%mod;

            sum += x;

        //    cout << i << " " << x << " " << f[x-1] << " " << f[sum] << " " << sum << " " << ans << endl;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
