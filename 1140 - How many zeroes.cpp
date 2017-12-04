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

ll dp[12][2][2][12];

ll solve(ll i, ll isSmall, ll isStart, ll howmany)
{
 //   cout << i << " " << howmany << endl;
    if (i == digits.size())
        return howmany;

    if (dp[i][isSmall][isStart][howmany] != -1)
        return dp[i][isSmall][isStart][howmany];

    ll limit = isSmall ? 9 : digits[i], ans = 0, x = 0, y = 0, z = 0;

//    cout << "a " << i << " " << digits[i] << " " << limit << " " << isSmall << " " << isStart << " " << howmany << endl;

    if (isStart == 0)
    {
        for (ll j = 0; j <= limit; j++)
        {
            x += solve(i + 1, isSmall | j < digits[i], 0, howmany + (j == 0));
        }
    }
    else
    {
        for (ll j = 1; j <= limit; j++)
        {
            y += solve(i + 1, isSmall | j < digits[i], 0, howmany);
        }
        z += solve(i + 1, 1, 1, 0);
    }

    ans = x + y + z;

  //  cout << "b " << i << " " << digits[i] << " " << limit << " " << x << " " << y << " " << z << " " << ans << endl;

    return (dp[i][isSmall][isStart][howmany] = ans);
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, p, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);

        digits.clear();

        z = x - 1;

        while(z > 0)
        {
            digits.push_front(z%10);
            z /= 10;
        }
        memset(dp, -1, sizeof(dp));

        p = solve(0, 0, 1, 0);

        if (z != -1)
            p++;

    //    cout << p << endl;

        digits.clear();

        z = y;

        while(z > 0)
        {
            digits.push_front(z%10);
            z /= 10;
        }
        memset(dp, -1, sizeof(dp));

        q = solve(0, 0, 1, 0) + 1;

        ans = q - p;

      //  cout << x << " " << p << " " << y << " " << q << endl;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
