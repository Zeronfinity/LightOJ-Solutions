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

ll ar[110], n;

ll dp[2][100010];

int main ()
{
    //  freopen("inl.txt", "r", stdin);
//     freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        z = 0;

        for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
            z += ar[i];
        }

        dp[0][0] = 1;

        for (i = 1; i <= z/2; i++)
            dp[0][i] = 0;

        ans = 0;

        for (i = 1; i <= n; i++)
            for (j = 0; j <= z/2; j++)
            {
                if (j >= ar[i])
                {
                    y = dp[(i-1)%2][j - ar[i]];

                    if ( (y&(1LL << 62)) != 0)
                    {
                        y &= ((1LL << 62) - 1);
                    }
                    y = (y << 1);
                }
                else y = 0;

                dp[i%2][j] = dp[(i-1)%2][j] | y;

                x = dp[i%2][j];

            //    cout << i << " " << j << " " << dp[(i-1)%2][j] << " " << x << endl;

                if (i == n && n%2 == 0)
                {
                    //       cout << (x & (1 << n/2)) << endl;
                    if ( (x & (1LL << n/2)) != 0)
                    {
                        ans = max(ans, j);
                    }
                }
                else if (i == n)
                {
                    if (((x & (1LL << n/2)) != 0) || ((x & (1LL << (n/2 + 1))) != 0))
                    {
                        ans = max(ans, j);
                    }
                }
            }

        printf("Case %lld: %lld %lld\n", cs, ans, z-ans);
    }

    return 0;
}
