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

#define prlimit 3600

ll mod = 1000000007;

bool p[prlimit];
int prime[prlimit/2 + 5];

ll pwr[505], dp[505][505];

int main ()
{
   // freopen("inl.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    k = 1;
    prime[k++] = 2;

    for (i = 3; i <= prlimit; i += 2)
    {
        if (p[i] == 0)
        {
            prime[k++] = i;
            for (j = i*i; i <= (sqrt(prlimit) + 10) && j <= prlimit; j += 2*i)
            {
                p[j] = 1;
            }
        }
    }

    pwr[0] = 1;
    for (i = 1; i <= 502; i++)
        pwr[i] = (pwr[i-1]*2)%mod;

    for (i = 1; i <= 500; i++)
        dp[1][i] = ((pwr[i] - pwr[i-1])%mod + mod)%mod;

    for (i = 2; i <= 500; i++)
    {
    //    cout << i << " " << prime[i] << endl;
        pwr[0] = 1;
        for (j = 1; j <= 502; j++)
            pwr[j] = (pwr[j-1]*prime[i])%mod;

        for (j = i; j <= 500; j++)
        {
            dp[i][j] = 0;

            for (k = i-1; k < j; k++)
            {
                ll rem = j - k;

                x = (dp[i-1][k]*(((pwr[rem] - pwr[rem-1])%mod + mod)%mod))%mod;

                dp[i][j] = (dp[i][j] + x)%mod;
            }

        }
    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);

        printf("Case %lld: %lld\n", cs, dp[y][x]);
    }

    return 0;
}
