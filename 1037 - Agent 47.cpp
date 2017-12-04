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

ll hp[16];

char dm[17][17];

ll dp[33000];

ll solve(ll mask)
{
  //  cout << "a " << mask << " " << gun << endl;
    if (mask == ((1<<n) - 1))
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    ll ans = LLONG_MAX - 1000000000000000;

    for (ll i = 0; i < n; i++)
    {
        if ( (mask & (1 << i)) == 0 )
        {
//            cout << "b " << mask << " " << gun << " " << hp[i] << " " << dm[gun][i] << " " << ( (int) dm[gun][i] - '0') << " " << (hp[i]/(dm[gun][i]-'0') ) << endl;
            for (ll j = 0; j < n; j++)
            {
                if ( (mask & (1 << j)) != 0 )
                {
                    if ((dm[j][i]-'0') != 0)
                        ans = min(ans, solve(mask | (1<<i)) + ((hp[i]%(dm[j][i]-'0') == 0)?0:1) + hp[i]/(dm[j][i]-'0'));
                }
            }
            ans = min(ans, solve(mask | (1<<i)) +  ((hp[i]%(dm[16][i]-'0') == 0)?0:1) + hp[i]/(dm[16][i]-'0'));
        }
    }

//    cout << mask << " " << gun << " " << ans << endl;

    return dp[mask] = ans;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    strcpy(dm[16], "1111111111111111");

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            sl(hp[i]);
        }

        for (i = 0; i < n; i++)
            ss(dm[i]);

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: %lld\n", cs, solve(0));
    }

    return 0;
}
