#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

ll A[4][4], res[4][4], temp[4][4];

void pwr(ll p)
{
    ll i, j, k, s;

    if (p == 0)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                res[i][j] = 0;

        res[0][0] = res[1][1] = res[2][2] = res[3][3] = 1;

        return ;
    }

    pwr(p/2);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[i][j] = res[i][j];

    if (p%2 == 0)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                s = 0;
                for (k = 0; k < 4; k++)
                    s = (s + (temp[i][k]%10007*(temp[k][j]%10007))%10007)%10007;
                res[i][j] = s;
            }
    }
    else
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                s = 0;
                for (k = 0; k < 4; k++)
                    s = (s + (temp[i][k]%10007*(temp[k][j]%10007))%10007)%10007;
                res[i][j] = s;
            }

        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                temp[i][j] = res[i][j];

        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                s = 0;
                for (k = 0; k < 4; k++)
                    s = (s + (A[i][k]%10007*(temp[k][j]%10007))%10007)%10007;
                res[i][j] = s;
            }
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, a, b, c;

    A[0][3] = A[1][0] = A[2][1] = A[3][3] = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(a);
        sl(b);
        sl(c);

        A[0][0] = a;
        A[0][2] = b;

        if (n <= 2)
            ans = 0;
        else
        {
            pwr(n - 2);
            ans = (res[0][3]%10007*(c%10007))%10007;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
