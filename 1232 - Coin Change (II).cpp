#include <stdio.h>
using namespace std;

#define ll int
#define sl(n) scanf("%d", &n)

ll n;
ll coin[101];

int dp[10001];

ll solve(ll amt)
{
    dp[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = coin[i]; j <= amt; j++)
        {
            dp[j] = (dp[j] + dp[j - coin[i]])%100000007;
        }
    }

    return dp[amt];
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

     //   sort(coin, coin + n);

        printf("Case %d: %d\n", cs, solve(k));
    }

    return 0;
}
