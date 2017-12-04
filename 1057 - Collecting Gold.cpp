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
#define ft first
#define sd second

char s[22][22];

vector <pll > vec;

ll x, y;

ll dp[16][33000];

ll solve(ll i, ll m)
{
    if (m == (1 << vec.size()) - 1)
    {
        return 0;
    }

    if (dp[i][m] != -1)
        return dp[i][m];

    ll a = LLONG_MAX;
    ll p;

    for (ll j = 0; j < vec.size(); j++)
    {
        if ( (m & (1 << j)) == 0 )
        {
            p = solve(j, m | (1 << j)) + max(fabs(vec[j].ft - vec[i].ft), fabs(vec[j].sd - vec[i].sd));
         //   cout << i << " " << j << " " << m << " " << p << endl;
            if ( (m | (1 << j)) == (1 << vec.size()) - 1)
                p += max(fabs(vec[j].ft - x), fabs(vec[j].sd - y));
           // cout << i << " " << j << " " << m << " " << p << endl;
            a = min(a, p);
        }
    }


    return dp[i][m] = a;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(m);
        sl(n);

        for (i = 0; i < m; i++)
        {
            ss(s[i]);
        }

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
                if (s[i][j] == 'g')
                {
                    vec.pb(pll(i,j));
                }

                if (s[i][j] == 'x')
                {
                    x = i;
                    y = j;
                }
            }

        memset(dp, -1, sizeof(dp));

        ans = LLONG_MAX;

        for (i = 0; i < vec.size(); i++)
        {
            ans = min( ans, (solve(i, (1<<i)) + (ll) max(fabs(vec[i].ft - x), fabs(vec[i].sd - y))) );
          //  cout << i << " " << ans << endl;
        }

        if (vec.size() == 0)
            ans = 0;
        else if (vec.size() == 1)
            ans *= 2;

        printf("Case %lld: %lld\n", cs, ans);

        vec.clear();
    }

    return 0;
}
