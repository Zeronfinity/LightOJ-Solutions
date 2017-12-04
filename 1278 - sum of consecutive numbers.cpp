//critical: 12312321333

#include <bits/stdc++.h>
using namespace std;
#define up 15000000

int mark[1100000];
int primes[2100000];

int main()
{
    primes[0] = 2;
    double lg;
    long long llg, i, p, j, x, c, k=1, n, t, o;
    unsigned long long ans, temp;

    for (i=3; i<=3873; i+=2)
    {
        if ((mark[i>>5]&(1<<(i%32))) == 0)
        {
            for (j=2*i; j < up; j+=i)
                mark[j>>5] = (mark[j>>5]|(1<<(j%32)));
            primes[k] = i;
            k++;
        }
    }
    for (i=3875; i<=up; i+=2)
    {
        if ((mark[i>>5]&(1<<(i%32))) == 0)
        {
            primes[k] = i;
            k++;
        }
              //  cout << i << endl;
    }
    //cout << k << endl;
    scanf("%lld", &t);

    for (i=1; i<=t; i++)
    {
        ans = 1;
      //  lg = 5.5;
        scanf("%lld", &x);

        for (p = 0; p < k; p++)
        {
            if (primes[p] > x)
                break;
            c = 0;
            while(x%primes[p] == 0)
            {
                c++;
                x /= primes[p];
            }
            if (p!=0)
            ans *= (c+1);
         //   cout << primes[p] << " - " << c << " - " << ans << endl;

            if (x == 1)
                break;
        }
    /*    lg = log((double) x) / log(2);
        cout << lg << endl;
        if (lg != ceil(lg)) */
            if (x != 1)
                ans *= 2;

        printf("Case %lld: %lld\n", i, ans-1);
    }
    return 0;
}
