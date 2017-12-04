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

ll a[400];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans = 0, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ans = 0;
        sl(n);

        for (i = 0; i < n; i++)
            sl(a[i]);

        for (i = 0; i < n; i++)
        {
            sl(x);
            y = (x - a[i] - 1);
            ans = ans^y;
         //   cout << x << " " << y << " " << ans << endl;
        }

        if (ans == 0)
            printf("Case %lld: black wins\n", cs);
        else
            printf("Case %lld: white wins\n", cs);
    }

    return 0;
}
