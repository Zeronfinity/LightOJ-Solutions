#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

unsigned int prime[100000];

void sieve ()
{
    long long i, j, k = 1;

    prime[0] = 2;

    for (i = 3; i <= 317; i+= 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
            for (j = i*i; j <= 10000; j+=i)
                prime[j] = 1;
        }
    }
    for (; i <= 100000; i+= 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
        }
    }
}

long long pwr(long long b, long long p)
{
    if (p == 0)
        return 1;

    long long x = pwr(b, p/2);

    x = (x*x)%mod;

    if (p%2 == 0)
        return x;
    else return (x*b)%mod;
}


int main ()
{
    long long i, t, n, m, p, j, temp, sum, x, c, a, b;
    double ca, cb, cc;
    sieve();
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> n >> m;
        sum = 1;

        temp = n;

        for (j = 0; temp != 1; j++)
        {
            p = (long long) prime[j]*prime[j];
            if (p > n)
                break;
            c = 0;

            while (temp%prime[j] == 0)
            {
                temp /= prime[j];
                c++;
            }
            if (c > 0)
            {
                x = ((pwr(prime[j], c*m+1)%mod - 1 + mod)%mod*(pwr(prime[j]-1, mod-2)%mod))%mod;
                sum = (sum*x)%mod;
            }
        }
        if (temp != 1)
        {
            x = ((pwr(temp, m+1)%mod - 1 + mod)%mod*pwr(temp - 1, mod-2)%mod)%mod;
            sum = (sum*x)%mod;
        }

        cout << "Case " << i << ": " << sum << endl;
    }

    return 0;
}
