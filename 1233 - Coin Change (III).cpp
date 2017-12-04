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

ll n;
ll coin[101], freq[101];

bool dp[100001];
ll taken[100001];

ll solve(ll amt)
{
    dp[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        memset(taken, 0, sizeof(taken));
        for (ll j = coin[i]; j <= amt; j++)
        {
            if (dp[j] == 0 && taken[j-coin[i]] + 1 <= freq[i])
            {
                taken[j] = taken[j-coin[i]] + 1;
                dp[j] = dp[j] | dp[j - coin[i]];
            }
        }

    //    for (ll j = 0; j <= amt; j++)
      //      cout << j << " " << dp[j] << " " << taken[j] << endl;
       // cout << endl;
    }

    ll c = 0;

    for (ll i = 1; i <= amt; i++)
    {
        if (dp[i] >= 1)
            c++;
//        cout << i << " " << dp[i] << " " << c << endl;
    }

    return c;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

        for (j = 0; j < k + 2; j++)
            dp[j] = 0;

        for (i = 0; i < n; i++)
            sl(coin[i]);

        for (i = 0; i < n; i++)
            sl(freq[i]);

     //   sort(coin, coin + n);

        printf("Case %lld: %lld\n", cs, solve(k));
    }

    return 0;
}
