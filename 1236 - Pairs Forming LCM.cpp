#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)

bool p[10000101];
int prime[5000000];

int main ()
{
    ll cs, t, i, j, sq, n, x, y, ans, q, cn = 0, i1, i2, k = 0;

    prime[k++] = 2;
    for (i = 3; i <= 10000100; i+=2)
    {
        if (p[i] == 0)
        {
            for (j = i*i; j <= 10000100; j += 2*i)
            {
                p[j] = 1;
            }
            prime[k++] = i;
        }
    }

    cin >> t;

    for (cs = 1; cs <= t ; cs++)
    {
        ans = 1;
        sl(n);

        sq = sqrt(n);

        for (i = 0; prime[i] <= sq; i++)
        {
            cn = 0;
            while (n%prime[i] == 0)
            {
                cn++;
                n /= prime[i];
            }
            ans *= (2*cn + 1);
        }
        if (n != 1)
            ans *= 3;

        ans = (ans + 1)/2;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
