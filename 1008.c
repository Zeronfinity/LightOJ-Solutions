#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main ()
{
    long long p, d, t, caseno = 0;
    double sq;
    unsigned long long x, a, b, cs;
    scanf("%lld", &t);
    while(t--)
    {
        caseno++;
        scanf("%lld", &x);
        sq = sqrt(x);
        if ((sq - ceil(sq)) == 0)
        {
            if (x%2==0)
                a = sq, b = 1;
            else a = 1, b = sq;
        }
        else
        {
            cs = sq;
            cs++;
            cs = cs*cs;
            p = round(sqrt(cs)) - 1;
            d = cs - x;

            if (cs%2==0)
                {a = round(sqrt(cs)), b = 1;}
            else a = 1, b = round(sqrt(cs));

            if (cs%2 == 0)
            {
                d=d-p;
                if(d<0)
                    b=b+p+d;
                else b = b+p;
                if (d>0)
                    a=a-d;
            }
            else
            {
                d=d-p;
                if (d<0)
                    a=a-d;
                else a = a+p;
                if (d>0)
                    b=b-d;
            }
        }
        printf("Case %lld: %lld %lld\n", caseno, a, b);
    }
    return 0;
}
