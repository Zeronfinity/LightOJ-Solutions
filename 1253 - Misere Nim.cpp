#include <stdio.h>
#include <climits>
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
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ans = y = 0;
        sl(n);
        z = n;
        while(n--)
        {
            sl(x);
            ans ^= x;

            if (x == 1)
                y++;
        }

        printf("Case %lld: ", cs);

        if (y == z)
        {
            if (y%2 == 0)
                printf("Alice\n");
            else printf("Bob\n");
        }
        else
        {
            if (ans)
                printf("Alice\n");
            else printf("Bob\n");
        }
    }

    return 0;
}
