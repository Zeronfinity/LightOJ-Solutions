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

char a[104], b[104], c[104];

ll dp[104][104][104];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    ll mod = 1000000007;

    a[0] = b[0] = c[0] = '#';

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ss(a+1);
        ss(b+1);
        ss(c+1);

        x = strlen(a) - 1;
        y = strlen(b) - 1;
        z = strlen(c) - 1;


        for (i = 0; i <= x; i++)
            for (j = 0; j <= y; j++)
                for (k = 0; k <= z; k++)
                {
                    if (k == 0)
                    {
                        dp[i][j][k] = 1;
                        continue;
                    }

                    if (i == 0 && j == 0)
                    {
                        dp[i][j][k] = 0;
                        continue;
                    }

                    dp[i][j][k] = 0;

                    if (a[i] == c[k] && i > 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%mod;

                    if (b[j] == c[k] && j > 0)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k-1])%mod;
                    }

                    if (i > 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k])%mod;

                    if (j > 0)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k])%mod;
                    }

                    if (i > 0 && j > 0)
                        dp[i][j][k] = ((dp[i][j][k] - dp[i-1][j-1][k])%mod + mod)%mod;


                    cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                }


        printf("Case %lld: %lld\n", cs, dp[x][y][z]);
    }

    return 0;
}
