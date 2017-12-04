#include <stdio.h>
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

char a[35], b[35];
ll dp[35][35], dp1[35][35][65], ans, pi, pj, li, lj, la, lb;

ll ncr(ll n, ll r);

ll lcs(ll i, ll j)
{
    if (a[i] == 0 || b[j] == 0)
        return 0;

    ll an, an1, an2;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
    {
        an = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        an1 = lcs(i, j + 1);
        an2 = lcs(i + 1, j);

        an = max(an1, an2);
    }

    return (dp[i][j] = an);
}

ll solve(ll i, ll j, ll num)
{
  //  cout << "a " << i << " " << j << " " << dp1[i][j][num] << " " << num << " " << la + lb - ans << endl;

    if (a[i] == 0)
    {
        if (num + lb - j == la + lb - ans)
        {
    //        cout << "GABA" << endl;
            return 1;
        }
        else return 0;
    }

    if (b[j] == 0)
    {
        if (num + la - i == la + lb - ans)
        {
      //      cout << "HABA" << endl;
            return 1;
        }
        else return 0;
    }

    ll an, an1, an2;


    if (dp1[i][j][num] != -1)
        return dp1[i][j][num];


    if (a[i] == b[j])
    {
        an = solve(i + 1, j + 1, num + 1);
    }
    else
    {
        an1 = solve(i, j + 1, num + 1);
        an2 = solve(i + 1, j, num + 1);

        an = an1 + an2;
    }

//    cout << "b " << i << " " << j << " " << an1 << " " << an2 << " " << an << endl;

    return (dp1[i][j][num] = an);
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans1, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ss(a);
        ss(b);

        la = strlen(a);
        lb = strlen(b);

        for (i = 0; i <= 32; i++)
            for (j = 0; j <= 32; j++)
                dp[i][j] = -1;

        for (i = 0; i <= 32; i++)
            for (j = 0; j <= 32; j++)
                for (k = 0; k <= 63; k++)
                    dp1[i][j][k] = -1;

        ans = lcs(0, 0);

        ans1 = solve(0, 0, 0);

        printf("Case %lld: %lld %lld\n", cs, la + lb - ans, ans1);
    }

    return 0;
}
