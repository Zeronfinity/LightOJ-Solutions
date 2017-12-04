#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#define tte 100000000

unsigned int prime[3300000];
unsigned int primes[5761500][2];

int main()
{
    primes[0][0] = 2;
    primes[0][1] = 2;
    unsigned long long temp;
    unsigned long long st, en, md, i, j, ei, k=1, n, t, q, p, pk1;
    unsigned long long test, ans, power, lg;
    double l, dpower, pw;
    pw = pow(2, 32);
    q = (long long) pw;

    for (j=4; j <= tte; j+=2)
        prime[j>>5] = (prime[j>>5]|(1<<(j%32)));

    for (i=3; i<=10000; i+=2)
    {
        if ((prime[i>>5]&(1<<(i%32))) == 0)
        {
            for (j=2*i; j < 100000000; j+=i)
                prime[j>>5] = (prime[j>>5]|(1<<(j%32)));
            primes[k][0] = i;
            pk1 = (long long) primes[k-1][1];
            temp = ((pk1%q)*(i%q))%q;
            primes[k][1] = (unsigned int) temp;
            k++;
        }
    }
    for (i=10001; i<=100000000; i+=2)
    {
        if ((prime[i>>5]&(1<<(i%32))) == 0)
        {
            primes[k][0] = i;
            pk1 = (long long) primes[k-1][1];
            temp = ((pk1%q)*(i%q))%q;
            primes[k][1] = (unsigned int) temp;
            k++;
        }
    }

    scanf("%lld", &t);

    for (i=1; i<=t; i++)
    {
        ans = 1;
        scanf("%lld", &n);

        for (j = 0; primes[j][0] <= 10000; j++)
        {
            l = 0;
            temp = primes[j][0]*primes[j][0];
            if (temp > n)
                break;

            l = ( (log((long double) n)/log((long double) primes[j][0])) );
            lg = (long long) l;
            dpower = pow((double) primes[j][0], (double) (lg-1));
            power = (long long) dpower;

            ans = ((ans%q)*(power%q))%q;

        }

        st = 0;
        en = k-1;
        while (1)
        {
            md = (st+en)/2;

            if ( (primes[md][0] == n) || (primes[md][0] < n && primes[md+1][0] > n) )
            {
                j = md;
                break;
            }
            else if (n > primes[md][0])
            {
                st = md+1;
            }
            else if (n < primes[md][0])
            {
                en = md-1;
            }
            if (st == en)
            {
                j = st;
                break;
            }
        }
        temp = (long long) primes[j][1];
        test = (ans%q)*(temp%q);
        ans = (test)%q;
        printf("Case %lld: %lld\n", i, ans);
    }
    return 0;
}
