#include <bits/stdc++.h>
using namespace std;

bool p[25000000], ans[100010];
int prime[1565928];

int main ()
{
//    freopen("inl.txt", "r", stdin);
    long long i, j, pr = 0, t, a, b, c = 0, k, f, sj, l, u, cs;
    p[1] = 1;
    for (i = 2; i <= 25000000; i+=2)
    {
        if (p[i] == 0)
        {
            prime[pr++] = i;

            if (i <= 5000)
                for (j = i*i; j <= 25000000; j+=2*i)
                {
                    p[j] = 1;
                }
        }
        if (i == 2)
            i = 1;
    }

    for (j = 6; j <= 25000000; j+=4)
    {
        p[j] = 1;
    }


    /*    for (; i <= 30000000; i+=2)
        {
            if (p[i] == 0)
            {
                prime[pr++] = i;
            }
        } */

    /*   while(1)
       {
           int x;
           cin >> x;
           cout << lower_bound(prime, prime+1565928, x) - prime << endl;
       } */


    scanf("%lld", &t);


    for (cs = 1; cs <= t; cs++)
    {
        scanf("%lld %lld", &a, &b);

        c = 0;

        if (b <= 25000000)
        {
  //          l = lower_bound(prime, prime+1565928, a) - prime;
    //        u = upper_bound(prime, prime+1565928, b) - prime - 1;

                  for (j = a; j <= b; j++)
                  {
            //                if (j < 100)
                      //              cout << j << " " << p[j] << endl;
                      if (p[j] == 0)
                          c++;
                  }
            //     cout << l << " " << u << endl;
            //    for (i = l; i <= u; i++)
            //      cout << i << " " << prime[i] << endl;
//            c += u - l + 1;
        }
        else
        {
            if (a <= 24000500)
            {
            //    l = lower_bound(prime, prime+1565928, a) - prime;
             //   u = upper_bound(prime, prime+1565928, 24000500) - prime - 1;
             //   c += u - l + 1;

                         for (j = a; j <= 24000500; j++)
                             if (p[j] == 0)
                                 c++;

                a = 24000501;
                memset(ans, 0, b-a+1);
                sj = sqrt(b);
                for (j = 0; prime[j] <= sj; j++)
                {
                    f = a/prime[j];
                    f = f*prime[j];
                    for (; f <= b ; f += prime[j])
                    {
                        if (f >= a)
                            ans[f-a] = 1;
                    }
                }
                for (j = 0; j <= b-a; j++)
                {
                    if (ans[j] == 0)
                        c++;
                }
            }
            else
            {
                memset(ans, 0, b-a+1);
                sj = sqrt(b);
                for (j = 0; prime[j] <= sj; j++)
                {
                    f = a/prime[j];
                    f = f*prime[j];
                    for (; f <= b ; f += prime[j])
                    {
                        if (f >= a)
                            ans[f-a] = 1;
                    }
                }
                for (j = 0; j <= b-a; j++)
                {
                    if (ans[j] == 0)
                        c++;
                }
            }
        }

        printf("Case %lld: %lld\n", cs, c);
    }

    return 0;
}
