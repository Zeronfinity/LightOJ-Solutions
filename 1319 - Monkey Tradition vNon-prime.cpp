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

    if (r == 1)
        return s1;
    else return ex_eucl(y, r);
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, mul = 1, lcm, m,a ,b;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);

        sl(m);
        sl(a);

        lcm = m;

        for (i = 2; i <= x; i++)
        {
            sl(n);
            sl(b);

            s2 = 1;
            s1 = 0;

            k = ex_eucl(m, n);

            k = (k%n + n)%n; //here gcd is 1, generally we'd have to mod by n/gcd

            k = ((b-a)*k)%n;

            lcm = m*n;

            a = (a + (k*m)%lcm)%lcm;

            if (a < 0)
                a = (a + lcm)%lcm;

            m = lcm;
        }

        printf("Case %lld: %lld\n", cs, a%lcm);
    }

    return 0;
}
