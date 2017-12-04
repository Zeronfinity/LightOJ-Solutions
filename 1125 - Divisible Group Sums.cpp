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
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

ll dp[210][11][22], val[210];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, d;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(q);

        for (i = 1; i <= n; i++)
        {
            sl(val[i]);
        }

        printf("Case %lld:\n", cs);

        while (q--)
        {
            sl(d);
            sl(m);

            memset(dp, 0, sizeof(dp));

            for (i = 0; i <= n; i++)
                for (j = 0; j <= min(i, m); j++)
                    for (k = 0; k < d; k++)
                    {
                        if (i == 0 || j == 0)
                        {
                            if (k == 0)
                                dp[i][j][k] = 1;
                            else dp[i][j][k] = 0;
                        }
                        else dp[i][j][k] = dp[i-1][j-1][((k - val[i]%d)%d + d)%d] + dp[i-1][j][k];

                     //   cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                    }

            if (n >= m)
                printf("%lld\n", dp[n][m][0]);
            else printf("0\n");
        }

    }

    return 0;
}
