#include <bits/stdc++.h>
using namespace std;
#define ftf 5000005
unsigned long long phi[ftf];
unsigned int p[156255];
int main ()
{
    long long i, j, t, sq, a, b, flag = 0;
    unsigned long long ans;
    for (i = 0; i < ftf; i++)
        phi[i] = i;

    sq = (long long) (sqrt((double) ftf) + 1.0);
    for (i = 2; i <= sq ; i+=2)
    {

        if ((p[i>>5]&(1<<(i&31))) == 0)
        {
            for (j = i; j <= ftf; j+=i)
            {
                if (j != i)
                    p[j>>5] = p[j>>5]|(1<<(j&31));
                phi[j] = phi[j]-phi[j]/i;
            }
        }

        if (i == 2)
            i = 1;
    }

    for (; i <= ftf; i+=2)
    {

        if ((p[i>>5]&(1<<(i&31))) == 0)
        {
            for (j = i; j <= ftf; j+=i)
            {
                phi[j] = phi[j]-phi[j]/i;
            }
        }
    }

    for (i = 0; i <= 30; i++)
    {
        cout << i << " " << phi[i] << endl;
    }

    phi[2] *= phi[2];
    for (i = 3; i <= ftf; i++)
    {
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }

    cout << phi[2134234] << endl;

    phi[1] = 0;

    scanf("%lld", &t);

    for (i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &a, &b);
        ans = phi[b] - phi[a-1];

        printf("Case %lld: %llu\n", i, ans);
    }

    return 0;
}
