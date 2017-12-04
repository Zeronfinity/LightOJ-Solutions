//(a+b)%c*k%c*(n^(k-1)))%c
#include <bits/stdc++.h>
using namespace std;

long long pwr(long long b, long long p, long long m)
{
    if (p == 0)
        return 1;
    long long x = pwr(b, p/2, m);

    if (p%2 == 0)
        return ((x%m)*(x%m))%m;
    else return (((x%m)*(x%m))%m*(b%m))%m;
}

int main ()
{
    long long i, t, n, k, m, j, res, x;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        res = 0;
        cin >> n >> k >> m;
        for (j = 0; j < n; j++)
        {
            cin >> x;
            res = (res%m+x%m)%m;
        }
        res = (res%m*k%m)%m;
        res = (res*pwr(n, k-1, m))%m;
        cout << "Case " << i << ": " << res << endl;
    }

    return 0;
}
