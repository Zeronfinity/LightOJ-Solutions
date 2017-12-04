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

ll dp[2][15010];

ll csum[15010];

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, s;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);
        sl(s);

        if (s == 0)
        {
            printf("Case %lld: %lld\n", cs, 0);
            continue;
        }

        for (i = 0; i <= s; i++)
        {
            if (1 <= i && i <= k)
                dp[1][i] = i;
            else dp[1][i] = 0;
         //   cout << i << " " << csum[1][i] << endl;
        }

        csum[1][s] = dp[1][s];

        x = 2;

        for (i = s - 1; i >= 0; i--, x++)
        {
            csum[1][i] = csum[1][i+1] + x*dp[1][i];
        }

        for (j = 2; j <= n; j++)
            for (i = 0; i <= s; i++)
            {
                dp[j%2][i] = ((csum[(j-1)%2][max(0LL, i-1)] - csum[(j-1)%2][max(i-k-1, 0LL)])%100000007 + 100000007)%100000007;
                csum[j%2][i] = (csum[j%2][i-1] + dp[j%2][i])%100000007;
//                cout << j << " " << i << " " << (j-1)%2 << " " << max(0LL,i-1) << " " << csum[(j-1)%2][min(0LL,i-1)] << " " << dp[j%2][i] << endl;
            }

        printf("Case %lld: %lld\n", cs, dp[n%2][s]);
    }

    return 0;
}

