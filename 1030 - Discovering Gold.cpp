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
#define pll pair <long long, long long>
#define pb push_back

double ar[200];
double ans[200];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, z, q, m, x, n;

    double y;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            sf(ar[i]);
        }

        ans[n-1] = ar[n-1];

        for (i = n-2; i >= 0; i--)
        {
            x = 0;
            y = 0;
//            cout << i << " " << j << " " << n << " " << j - i << endl;
            for (j = i + 1; j < n && j - i <= 6; j++)
            {
  //              cout << j << " " << ans[j] << x << endl;
                y += ans[j];
                x++;
            }
            if (x == 0)
                x = 1;
            ans[i] = ar[i] + y/x;
    //        cout << i << " " << ans[i] << " " << ar[i] << " " << y << " " << x << endl;
        }

        printf("Case %lld: %0.8lf\n", cs, ans[0]);
    }

    return 0;
}
