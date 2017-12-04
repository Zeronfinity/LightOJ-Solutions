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
#define pld pair <ll, double>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sd second

#define EPS 0.000000001

double p;
ll n;

ll m[110];
double l[110];

bool vis[110][10010];
double dp[110][10010];

double solve(ll i, ll make)
{
    if (make <= 0)
        return 0;
    if (i > n)
    {
        return (double) LLONG_MAX - 10000;
    }

//    cout << i << " vis " << make << " " << vis[i][make] << endl;

    if (vis[i][make] == 1)
        return dp[i][make];
    vis[i][make] = 1;

    double x = l[i] + (1-l[i])*solve(i + 1, make - m[i]);
    double y = solve(i + 1, make);

    //cout << i << " gaba " << make << " " << m[i] << " " << x << " " << y << endl;

    return dp[i][make] = min(x, y);
}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, b, e;

    double yo;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sf(p);
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(m[i]);
            sf(l[i]);
        }

        memset(vis, 0, sizeof(vis));

    //    cout << "wtf? " << vis[2][5] << endl;

        b = 0;
        e = 10010;

        ans = 0;

        while(b <= e)
        {
            ll mid = (b + e)/2;

            yo = solve(1, mid);

//            cout << "damn " << vis[2][5] << endl;

    //        cout << mid << " " << b << " " << e << " " << yo << endl;

            if (p - yo > EPS)
            {
                ans = mid;
                b = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
