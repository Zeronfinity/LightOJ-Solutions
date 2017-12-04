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

map <ll, bool> mp;

ll pp[210000];
ll dp[210000];

ll f(ll n)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll p = 0, q = n-1, ans = 0;

    while(p <= q)
    {
        ll x = (f(p)*f(q))%100000007;

        if (p != q)
            x = (x*2)%100000007;

        ans = (ans + x)%100000007;

        p++;
        q--;
    }
    return dp[n] = ans;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, p;

    k = 0;

    for (i = 2; i <= 100000; i++)
    {
        x = i*i;
        for (j = 1; x <= 10000000000; j++)
        {
            if (mp[x] == 0)
                pp[k++] = x;

            mp[x] = 1;

            x = x*i;
        }
    }

    sort(pp, pp + k);

 //   for (i = 0; i <= 50; i++)
   //     cout << pp[i] << endl;

   // cout << k << endl;

   memset(dp, -1, sizeof(dp));

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(x);
        sl(y);

        q = upper_bound(pp, pp + k, y) - pp;

      //  if (q == -1)
        //    q = 0;

        p = lower_bound(pp, pp + k, x) - pp;

//        if (p == -1)
  //          p = 0;

        m = q - p;

    //    cout << p << " " << q << " " << m << endl;

        printf("Case %lld: %lld\n", cs, m==0?0:f(m));
    }

    return 0;
}
