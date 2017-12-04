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

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define ft first
#define sd second

ll x[1010], y[1010];

pll ar[1000010];

bool comp (pll l, pll r)
{
    if (l.first < r.first)
        return true;
    else if (l.first == r.first)
        return l.second < r.second;
    else return false;
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
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(x[i]);
            sl(y[i]);
        }

        k = 0;

        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                ar[k++] = pll(x[i] + x[j], y[i] + y[j]);
     //           cout << i << " " << j << " " << x[i] + x[j] << " " << y[i] + y[j] << " " << mp[pll(x[i] + x[j], y[i] + y[j])] << endl;
            }
        }

        ans = 0;

        sort(ar, ar + k, comp);

        ll c = 1;

        for (i = 0; i < k; i++)
        {
            if (ar[i-1].first == ar[i].first && ar[i-1].second == ar[i].second)
                c++;
            else
            {
                ans += c*(c-1)/2;
                c = 1;
            }
        }

        ans += c*(c-1)/2;

        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}
