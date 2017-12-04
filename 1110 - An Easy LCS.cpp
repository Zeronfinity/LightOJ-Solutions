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

char a[1000], b[1000];

string dp[110][110];

ll lcs(ll i, ll j)
{
    if (a[i] == 0 || b[j] == 0)
    {
        dp[i][j] = "";
         return 0;
    }

    if (dp[i][j] != "-1")
    {
        return dp[i][j].size();
    }

    ll p, q;

    p = q = 0;

    if (a[i] == b[j])
    {
        p = lcs(i + 1, j + 1) + 1;
        string tmp = "a";
        tmp[0] = a[i];
        dp[i][j] = tmp + dp[i+1][ j+1];
    }
    else
    {
        p = lcs(i + 1, j);
        q = lcs(i, j + 1);

        if (p > q)
            dp[i][j] = dp[i+1][j];
        else if (p == q)
        {
            if (dp[i+1][j] <= dp[i][j+1])
                 dp[i][j] = dp[i+1][j];
              else dp[i][j] = dp[i][j+1];
        }
        else dp[i][j] = dp[i][j+1];
    }

    return max(p, q);
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, r, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ss(a);
        ss(b);

        ll la = strlen(a);
        ll lb = strlen(b);

        for (i = 0; i <= la; i++)
            for (j = 0; j <= lb; j++)
                dp[i][j] = "-1";

        if (lcs(0, 0) == 0)
        {
            printf("Case %lld: :(\n", cs);
        }
        else {
            printf("Case %lld: ", cs);
        cout << dp[0][0] << "\n";
        }
    }

    return 0;
}
