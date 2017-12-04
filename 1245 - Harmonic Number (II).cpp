#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, sq, pv = 0;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ans = 0;
        sl(n);

        x = n;

        sq = ceil(sqrt((double) n));

        for (i = 1; i <= sq && x >= i; i++)
        {
            if (i != ((n/i)+1))
                ans += n/i;

            ans += (x - n/i)*(i-1);

            x = n/i;

        //    cout << i << " " << x << " " << n/i << " " << ans << endl;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
