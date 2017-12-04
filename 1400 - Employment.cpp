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

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

ll pref[210][210];
map <pll , ll> mp;

ll last[300], st[300];


int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, free, w;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 1; i <= 2*n; i++)
        {
            last[i] = st[i] = 0;
        }
        mp.clear();

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &pref[i][j]);
            }

        for (i = n + 1; i <= 2*n; i++)
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &pref[i][j]);
                mp[pll(i,pref[i][j])] = j;
            }

        free = n;

        while (free > 0)
        {
            for (i = 1; i <= n; i++)
            {
             //   cout << i << " " << st[i] << " " << free << endl;
                if (st[i] == 0)
                {
                    w = pref[i][last[i]];
                    last[i]++;
                    if (st[w] == 0)
                    {
                        st[w] = i;
                        free--;
                        st[i] = w;
                    }
                    else
                    {
                        if (mp[pll(w,i)] < mp[pll(w, st[w])])
                        {
                            st[st[w]] = 0;
                            st[w] = i;
                            st[i] = w;
                        }
                    }
                }
            }
        }

        printf("Case %d:", cs);
        for (i = 1; i <= n; i++)
            printf(" (%d %d)", i, st[i]);
        printf("\n");
    }

    return 0;
}
