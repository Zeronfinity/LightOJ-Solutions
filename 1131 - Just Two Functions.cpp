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

#define rn 6  //number of rows in matrix
#define cn 6  //number of column in matrix

ll mod; //modulo

struct matrix
{
    ll mat[rn][cn];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < rn; i++)
            for (ll j = 0; j < cn; j++)
                mat[i][j] = 0;
    }
} base, unit;

matrix mul(matrix A, matrix B)
{
    ll i, j, k, s;

    matrix res;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            s = 0;
            for (k = 0; k < rn; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j])%mod)%mod;
            res.mat[i][j] = s;
        }
    return res;
}

matrix pwr(matrix b, ll p)
{
    if (p == 0)
    {
        return unit;
    }

    matrix x = pwr(b, p/2);

    if (p%2 == 0)
    {
        return mul(x, x);
    }
    else
    {
        return mul(b, mul(x, x));
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, f[3], g[3];

    sl(t);

    for (i = 0; i < rn; i++)  //initializing unit matrix
        for (j = 0; j < cn; j++)
            if (i == j)
                unit.mat[i][j] = 1;

    base.mat[1][0] = base.mat[2][1] = base.mat[4][3] = base.mat[5][4] = 1;


    for (cs = 1; cs <= t; cs++)
    {
        sl(base.mat[0][0]);
        sl(base.mat[0][1]);
        sl(base.mat[0][5]);
        sl(base.mat[3][3]);
        sl(base.mat[3][4]);
        sl(base.mat[3][2]);

        sl(f[0]);
        sl(f[1]);
        sl(f[2]);
        sl(g[0]);
        sl(g[1]);
        sl(g[2]);

        sl(mod);

        sl(q);

        printf("Case %lld:\n", cs);


        while(q--)
        {
            sl(n);

            if (n == 0)
            {
                printf("%lld %lld\n", f[0]%mod, g[0]%mod);
            }
            else if (n == 1)
            {
                printf("%lld %lld\n", f[1]%mod, g[1]%mod);
            }
            else if (n == 2)
            {
                printf("%lld %lld\n", f[2]%mod, g[2]%mod);
            }
            else
            {
                matrix R = pwr(base, n-2);

                for (i = 0; i < rn; i++)
                {
                    for (j = 0; j < cn; j++)
                        printf("%lld ", R.mat[i][j]);
                    cout << endl;
                }

                x = 0;

                for (i = 0; i < 6; i++)
                {
                    if (i <= 2)
                    {
                        x = (x + (R.mat[0][i]*(f[2-i]%mod))%mod)%mod;
                    }
                    else
                        x = (x + (R.mat[0][i]*(g[5-i]%mod))%mod)%mod;
                }

                y = 0;

                for (i = 0; i < 6; i++)
                {
                    if (i <= 2)
                    {
                        y = (y + (R.mat[3][i]*(f[2-i]%mod))%mod)%mod;
                    }
                    else
                        y = (y + (R.mat[3][i]*(g[5-i]%mod))%mod)%mod;
                }

                printf("%lld %lld\n", x, y);
            }
        }
    }

    return 0;
}
