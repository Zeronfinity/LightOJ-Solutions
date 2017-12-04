#include <stdio.h>

int main()
{
    unsigned long long n, caseno = 0, cases, f[10003];
    long long i;
    scanf("%lld", &cases);
    while( cases-- )
    {
        for (i=0; i<6; i++)
            scanf("%lld", &f[i]);
        scanf("%lld", &n);
        for (i=6; i<=n; i++)
            f[i]=(f[i-1]+f[i-2]+f[i-3]+f[i-4]+f[i-5]+f[i-6])%10000007;
        printf("Case %lld: %lld\n", ++caseno, f[n]%10000007);
    }
return 0;
}
