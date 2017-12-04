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

ll p[15], r[15], s1, s2, t1, t2;

ll ex_eucl(ll x, ll y)
{
    ll q, r, temp;

    q = x/y;

    r = x - q*y;

    temp = s2 - q*s1;
    s2 = s1;
    s1 = temp;

    temp = t2 - q*t1;
    t2 = t1;
    t1 = temp;

    if (r == 1)
        return s1;
    else return ex_eucl(y, r);
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, mul = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        ans = 0;
        mul = 1;

        for (i = 1; i <= n; i++)
        {
            sl(p[i]);
            sl(r[i]);
            mul *= p[i];
        }

        for (i = 1; i <= n; i++)
        {
            x = mul/p[i];
            s2 = t1 = 1;
            s1 = t2 = 0;
            ans += ((r[i]*x)%mul*ex_eucl(x, p[i]))%mul;

            if (ans < 0)
                ans = (ans + mul)%mul;
        }

        printf("Case %lld: %lld\n", cs, ans%mul);
    }

    return 0;
}
