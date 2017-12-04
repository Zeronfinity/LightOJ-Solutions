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

char s[23], res[23];

ll freq[26], l;

ll fact[30];

void solve(ll pos, ll n)
{
    if (pos == l)
    {
        res[pos] = 0;
        return ;
    }

    ll x, y = fact[l-pos-1], p = 0;

    for (ll i = 0; i < 26; i++)
    {
        x = y;

        if (freq[i] > 0)
        {
            for (ll j = 0; j < 26; j++)
            {
                if (freq[j] != 0)
                {
                    if (i == j)
                    {
                        if (freq[j] > 1)
                            x /= fact[freq[j] - 1];
                    }
                    else
                    {
                        x /= fact[freq[j]];
                    }


                }
            }

           // cout << pos << " " << i << " " << p << " " << x << " " << n << endl;

            if (p + x >= n)
            {
                res[pos] = i + 'a';
                freq[i]--;
                solve(pos + 1, n - p);
                return ;
            }

            p += x;
        }

    }
    strcpy(res, "Impossible");
    return ;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    fact[0] = 1;

    for (i = 1; i <= 21; i++)
        fact[i] = fact[i-1]*i;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ss(s);
        sl(n);

        l = strlen(s);

        for (i = 0; i < 26; i++)
            freq[i] = 0;

        for (i = 0; s[i] != 0; i++)
        {
            freq[s[i] - 'a']++;
        }


        solve(0, n);

        printf("Case %lld: %s\n", cs, res);
    }

    return 0;
}
