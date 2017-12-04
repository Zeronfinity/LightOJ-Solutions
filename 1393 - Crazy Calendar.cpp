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
        ans = 0;
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                sl(x);

                y = n - i + m - j;

                if (y%2 != 0)
                    ans ^= x;
            }

        printf("Case %lld: ", cs);

            if (ans)
                printf("win\n");
            else printf("lose\n");
    }

    return 0;
}
