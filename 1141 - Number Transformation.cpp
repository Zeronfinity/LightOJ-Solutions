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

bool p[1005];
int prime[600];
ll dp[1010];


ll DFS(ll n, ll dst)
{
  //  cout << "A " << n << " " << dst << " " << dp[n] << endl;
    if (n == dst)
        return 0;

    if (n > dst)
        return 9999999999999999;

    if (dp[n] != -1)
        return dp[n];

    ll sq = sqrt(n), mx = 9999999999999999, temp = n;

//    cout << prime[0] << " " << sq << endl;

    for (ll i = 0; prime[i] <= sq; i++)
    {
        if (temp%prime[i] == 0)
        {
            ll v = DFS(n + prime[i], dst);

        //    cout << "c " << n << " " << prime[i] << " " << mx << " " << v << endl;

            mx = min(mx, 1 + v);

            while (temp%prime[i] == 0)
                temp /= prime[i];
        }
    }

    if (temp != 1 && temp != n)
    {
        ll v = DFS(n + temp, dst);

      //  cout << "c " << n << " " << temp << " " << mx << " " << v << endl;

        mx = min(mx, 1 + v);
    }

   // cout << "b " << n << " " << mx << " " << dp[n] << endl;

    return (dp[n] = mx);
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k = 1, n, x, y, z, ans, q, m;

    prime[0] = 2;

    for (i = 3; i <= 1000; i += 2)
    {
        if (p[i] == 0)
        {
            if (i <= 33)
                for (j = i*i; j <= 1000; j += 2*i)
                {
                    p[j] = 1;
                }
            prime[k++] = i;
        }
    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);

        ans = 9999999999999999;

        if (x <= y)
        {
            for (i = x; i <= y; i++)
                dp[i] = -1;

            ans = DFS(x, y);

        }

        if (ans == 9999999999999999)
            ans = -1;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
