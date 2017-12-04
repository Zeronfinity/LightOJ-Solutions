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
#define ss(n) scanf(" %s", n)

ll cn, res[30], taken[30], m;

void fun(ll n, ll k)
{
    ll i;

    if (cn >= k)
        return ;

    if (m == n)
    {
        for (i = 1; i <= n; i++)
            printf("%c", res[i] + 'A' - 1);
        printf("\n");
        cn++;
        return ;
    }

    for (i = 1; i <= n; i++)
    {
        if (taken[i] == 0)
        {
            res[++m] = i;
            taken[i] = 1;
            fun(n, k);
            taken[i] = 0;
            m--;
        }
        if (cn > k)
            break;
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);
        m = cn = 0;
        printf("Case %lld:\n", cs);
        fun(n, k);
    }

    return 0;
}
