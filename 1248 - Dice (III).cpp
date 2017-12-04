#include <stdio.h>
#include <iostream>
#include <climits>
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
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sd second

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    double d = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        d = 1;

        for (i = 2; i <= n; i++)
        {
            d += ((double) n/ (double) (n-i+1));
         //   cout << i << " " << d << endl;
        }

        printf("Case %lld: %0.8lf\n", cs, d);
    }

    return 0;
}
