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

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

ll grid[205][105], dp[205][205], n;

ll solve(ll i, ll j)
{
  //  cout << "a " << i << " " << j << " " << dp[i][j] << endl;

    if (i > 2*n - 1)
        return 0;

    if (i <= n && (j > i || j < 1))
        return 0;

    if (i > n && (j > 2*n - i || j < 1))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    //cout << "b " << i << " " << j << endl;

    if (i < n)
    {
        dp[i][j] = max(solve(i+1, j) + grid[i][j], solve(i+1, j+1) + grid[i][j]);
    //    cout << "c " << i << " " << j << " " << dp[i][j] << endl;
        return dp[i][j];
    }
    if (i >= n)
    {
        if (j == 1)
        {
            dp[i][j] = solve(i+1, j) + grid[i][j];
        //cout << "c " << i << " " << j << " " << dp[i][j] << " " << grid[i][j] << endl;

            return dp[i][j];
        }
        else if (j == 2*n - i)
        {
            dp[i][j] = (solve(i+1, j-1) + grid[i][j]);
      //  cout << "c " << i << " " << j << " " << dp[i][j] << endl;

            return dp[i][j];
        }
        else
        {
            dp[i][j] = max(solve(i+1, j) + grid[i][j], solve(i+1, j-1) + grid[i][j]);
      //  cout << "c " << i << " " << j << " " << dp[i][j] << endl;;
            return dp[i][j];
        }
    }
}

int main ()
{
    ll cs, t, i, j, k, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        memset(dp, -1, sizeof(dp));
        sl(n);

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
                sl(grid[i][j]);
        }

        for (i = 1; i <= n-1; i++)
        {
            for (j = 1; j <= n - i; j++)
                sl(grid[n + i][j]);
        }

        printf("Case %lld: %lld\n", cs, solve(1,1));
    }

    return 0;
}
