#include <stdio.h>
#include <climits>
#include <iostream>
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

deque <ll> digits;

ll k;

ll pwr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2);

    x = (x*x)%k;

    if (p%2 == 0)
        return x;
    else return (b*x)%k;
}

ll dp[10][2][82][82];

ll solve(ll i, ll isSmall, ll mod, ll mod2)
{
    if (i == -1)
    {
        if (mod == 0 && mod2 == 0)
            return 1;
        else return 0;
    }

    if (dp[i][isSmall][mod][mod2] != -1)
        return dp[i][isSmall][mod][mod2];

    ll limit = isSmall == 1? 9 : digits[i], ans = 0;

    //  cout << i << " " << isSmall << " " << mod << " " << limit << " " << digits[i] << endl;

    for (ll j = 0; j <= limit; j++)
    {
        ans += solve(i - 1, isSmall | (j < digits[i]), (mod + (j*pwr(10, i))%k)%k, (mod2 + j)%k);
    }

    return (dp[i][isSmall][mod][mod2] = ans);
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);
        sl(k);

        if (k <= 81)
        {
            digits.clear();

            while (y != 0)
            {
                digits.push_back(y%10);
                y /= 10;
            }

            memset(dp, -1, sizeof(dp));

            ans = solve(digits.size() - 1, 0, 0, 0);

        //    cout << ans << endl;

            x--;

            if (x != 0)
            {
                digits.clear();

                while (x != 0)
                {
                    digits.push_back(x%10);
                    x /= 10;
                }

                memset(dp, -1, sizeof(dp));

                ans -= solve(digits.size() - 1, 0, 0, 0);
            }
            else ans--;
        }
        else ans = 0;
        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
