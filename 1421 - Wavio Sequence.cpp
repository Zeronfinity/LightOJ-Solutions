#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)

ll n;

ll ar[100100], rar[100100];

ll lis[100100], rlis[100100];

ll ic[100100], ric[100100];

int main ()
{
    ll cs, t, i, k, ans;
    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 1; i <= n; i++)
        {
            ic[i] = ric[i] = LLONG_MAX;
            sl(ar[i]);
            rar[n-i+1] = ar[i];
        }
        ic[0] = ric[0] = -LLONG_MAX;


        for (i = 1; i <= n; i++)
        {
            k = lower_bound(ic, ic+n+1, ar[i]) - ic;

            ic[k] = ar[i];
            lis[i] = k;

            k = lower_bound(ric, ric+n+1, rar[i]) - ric;

            ric[k] = rar[i];
            rlis[i] = k;
        }

        for (i = 1; i <= n/2; i++)
        {
            swap(rlis[i], rlis[n-i+1]);
        }

        ans = 0;
        lis[0] = rlis[n+1] = 0;
        for (i = 1; i <= n; i++)
        {
       //     cout << i << " " << lis[i] << " " << rlis[i] << endl;

                ans = max(ans, min(lis[i], rlis[i])*2-1);
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
