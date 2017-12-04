#include <bits/stdc++.h>
using namespace std;

#define m 1000003

long long f[1000005];

long long pwr(long long b, long long p)
{
    if (p == 0)
        return 1;

    long long x = pwr(b, p/2);

    x = (x*x)%m;

    if (p%2 == 0)
        return x;
    else return (x*b)%m;
}

int main ()
{
    long long i, j, t, n, k, ans;

    f[0] = 1;

    for (i = 1; i <= 1000000; i++)
        f[i] = (i*f[i-1])%m;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cin >> n >> k;

        cout << pwr( ((f[k]*f[n-k])%m), m-2 )%m  << endl;

        printf("Case %lld: %lld\n", i, ( f[n]%m * pwr( ((f[k]*f[n-k])%m), m-2 )%m )%m);
    }

    return 0;
}
