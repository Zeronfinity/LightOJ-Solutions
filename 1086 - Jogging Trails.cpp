#include <bits/stdc++.h>

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
#define inf (1LL<<32)
#define fr first
#define sc second

ll deg[17];
vector <ll> ed[17];
ll cost[17][17];
ll n;
ll dp[33000];
ll solve(ll mask)
{
    if (mask == (1LL<<n)-1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    dp[mask] = inf;

    for (ll i = 0; i < n; i++)
        for (ll j = i+1; j < n; j++)
        {
            if ( (mask&(1LL<<i)) != 0 || (mask&(1LL<<j)) != 0)
                continue;

            ll nmask = mask | (1LL<<i);

            nmask = nmask | (1LL<<j);

         //   cout << bitset<5>(mask) << " " << bitset<5>(nmask) << " " << i << " " << j << " " << cost[i+1][j+1] << " " << solve(nmask) << endl;

            dp[mask] = min(dp[mask], solve(nmask) + cost[i+1][j+1]);
        }

 //   cout << bitset<5>(mask) << " " << dp[mask] << endl;

    return dp[mask];
}

int main ()
{
    #ifdef zeron
    freopen("inl.txt", "r", stdin);
    freopen("outl.txt", "w", stdout);
    #endif
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        ans = 0;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    cost[i][j] = 0;
                else cost[i][j] = inf;
            }
        }

        memset(deg, 0, sizeof(deg));

        for (i = 0; i < m; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            deg[x]++, deg[y]++;

            cost[x][y] = min(cost[x][y], z);
            cost[y][x] = min(cost[y][x], z);

            ans += z;
        }

        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

//        for (i = 1; i <= n; i++)
//            for (j = 1; j <= n; j++)
//                printf("%lld %lld %lld\n", i, j, cost[i][j]);

        ll mask = 0;

        for (i = 1; i <= n; i++)
            if (deg[i]%2 == 0)
                mask |= (1LL<<(i-1));

        memset(dp, -1, sizeof(dp));

   //     cout << ans << endl;

        ans += solve(mask);

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
