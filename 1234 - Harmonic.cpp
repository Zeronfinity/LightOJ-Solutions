#include <bits/stdc++.h>
using namespace std;
double a[2600000];
int main ()
{
    a[0] = 0;
    long long t, i, n, r, j;
    double m = 0;

    for (i = 1; i <= 100000000; i++)
    {
        m += 1.0/((double) i);
        if (i%40 == 0)
            a[i/40] = m;
    }
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        m = 0;
        scanf("%lld", &n);
        r = n%40;
        m = a[n/40];
        for (j = 1; j <= r; j++)
        {
            m += 1/((double)(40*(n/40)+j));
        }
        printf("Case %lld: %0.12lf\n", i, m);
    }

    return 0;
}
