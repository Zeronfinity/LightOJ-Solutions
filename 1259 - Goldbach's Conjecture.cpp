#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)

bool p[10000100];
int prime[5000000];

int main ()
{
    ll cs, t, i, j, k = 0, n, x, y, ans, q;

    for (i = 3; i <= 10000000; i += 2)
    {
        if (p[i] == 0)
        {
            for (j = i*i; j <= 10000000; j += 2*i)
                p[j] = 1;
            prime[k++] = i;
        }
    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ans = 0;
        sl(n);

        if (n == 4)
        {
            printf("Case %lld: 1\n", cs);
            continue;
        }

        for (i = 0; ; i++)
        {
            if (prime[i] > n - prime[i])
                break;

            if (p[n - prime[i]] == 0)
                ans++;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
