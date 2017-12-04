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

ll A[2][2], res[2][2], temp[2][2];

ll pr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pr(b, p/2);

    if (p%2 == 0)
        return x*x;
    else return b*x*x;
}

void pwr(ll p, ll m)
{
    ll i, j, k, s;

    if (p == 0)
    {
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                res[i][j] = 0;

        res[0][0] = res[1][1] = 1;

        return ;
    }

    pwr(p/2, m);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = res[i][j];

    if (p%2 == 0)
    {
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                    s = (s + (temp[i][k]%m*(temp[k][j]%m))%m)%m;
                res[i][j] = s;
            }
    }
    else
    {
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                    s = (s + (temp[i][k]%m*(temp[k][j]%m))%m)%m;
                res[i][j] = s;
            }

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                temp[i][j] = res[i][j];

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                    s = (s + (A[i][k]%m*(temp[k][j]%m))%m)%m;
                res[i][j] = s;
            }
    }
}

int main ()
{
    ll cs, m, t, i, j, k, n, x, y, ans, q, a, b, c;

    A[0][0] = A[1][0] = A[0][1] = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(a);
        sl(b);
        sl(n);
        sl(m);

        m = pr(10, m);

        if (n == 0)
            ans = a%m;
        else if (n == 1)
            ans = b%m;
        else
        {
            pwr(n - 1, m);
            ans = ((res[0][0]%m*(b%m))%m + ((res[0][1]%m)*(a%m))%m)%m;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
