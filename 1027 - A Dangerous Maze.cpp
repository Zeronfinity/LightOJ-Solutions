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

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;

    return gcd(b, a%b);
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, c;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        c = ans = 0;

        for (i = 1; i <= n; i++)
        {
            sl(x);

            if (x < 0)
            {
                c++;
                ans += -1*x;
            }
            else ans += x;
        }

        y = n - c;

        k = gcd(y, ans);

        if (n == c)
            printf("Case %lld: inf\n", cs);
        else printf("Case %lld: %lld/%lld\n", cs, ans/k, y/k);
    }

    return 0;
}
