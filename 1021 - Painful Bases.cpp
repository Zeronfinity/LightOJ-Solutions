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
#define pll pair <long long, long long>
#define pb push_back

ll b, k, len, pos;

char s[20];

ll dp[67000][21];

ll pwr(ll bs, ll p, ll m)
{
    if (p == 0)
        return 1;

    ll x = pwr(bs, p/2, m);

    x = (x*x)%m;

    if (p%2 == 0)
        return x;
    else return (bs*x)%m;
}

ll solve(ll mask, ll mod)
{
    ll i = 0, x, nmask, nmod, ans = 0;

  //  cout << "a " << " " << mask << " " << mod << endl;

    if (mask == (1 << len) - 1)
    {
        if (mod == 0)
            return 1;
        else return 0;
    }

    if (dp[mask][mod] != -1)
        return dp[mask][mod];

    for (i = 0; i < len; i++)
    {
        if ( (mask & (1 << i)) == 0 )
        {
            if ('A' <= s[i] && s[i] <= 'F')
            {
                x = s[i] - 'A' + 10;
            }
            else
            {
                x = s[i] - '0';
            }
            nmask = mask | (1 << i);
            nmod = (mod + (x*pwr(b, pos, k))%k)%k;
            pos++;
            ans += solve(nmask, nmod);
            pos--;
        }
    }

    return dp[mask][mod] = ans;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(b);
        sl(k);

        ss(s);

        len = strlen(s);

        pos = 0;

        x = 1 << b;

        for (i = 0; i < x; i++)
            for (j = 0; j <= k; j++)
                dp[i][j] = -1;

        printf("Case %lld: %lld\n", cs, solve(0, 0));
    }

    return 0;
}
