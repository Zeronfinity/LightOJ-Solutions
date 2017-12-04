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

ll n;

ll ar[35], dp[35][2][2][2][35];

ll pwr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2);

    if (p%2 == 0)
        return x*x;
    else return b*x*x;
}

ll solve(ll pos, bool prev, bool started, bool lesser, ll cnt)
{
   // cout << "a " << pos << " " << prev << " " << started << " " << lesser << endl;
    if (pos == -1)
    {
        return cnt;
    }

    if (dp[pos][prev][started][lesser][cnt] != -1)
        return dp[pos][prev][started][lesser][cnt];

    ll ans = 0;

    if (lesser == 0)
    {
        if (ar[pos] == 1)
        {
            ans += solve(pos - 1, 0, started | 0, 1, cnt);
            if (prev == 1)
                ans += solve(pos - 1, 1, started | 1, 0, cnt + 1);
            else ans += solve(pos - 1, 1, started | 1, 0, cnt);
        }
        else
        {
            ans += solve(pos - 1, 0, started | 0, 0, cnt);
        }
    }
    else
    {
            ans += solve(pos - 1, 0, started | 0, 1, cnt);
            if (prev == 1)
                ans += solve(pos - 1, 1, started | 1, 1, cnt + 1);
            else ans += solve(pos - 1, 1, started | 1, 1, cnt);
    }

  //  cout << "b " << pos << " " << prev << " " << started << " " << lesser << " " << ans << endl;

    return dp[pos][prev][started][lesser][cnt] = ans;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        k = 0;

        while(n != 0)
        {
            ar[k++] = n%2;
        //    cout << k - 1 << " " << ar[k-1] << " " << n << endl;
            n /= 2;
        }

        memset(dp, -1, sizeof(dp));

        printf("Case %lld: %lld\n", cs, solve(k - 1, 0, 0, 0, 0));
    }

    return 0;
}
