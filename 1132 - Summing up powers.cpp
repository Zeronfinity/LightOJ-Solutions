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

ll mod; //modulo

ll cn, rn;

ll Cm[55][55];

struct matrix
{
    unsigned int mat[52][52];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < 52; i++)
            for (ll j = 0; j < 52; j++)
                mat[i][j] = 0;
    }
} unit;

matrix mmul(matrix A, matrix B)
{
    ll i, j, k;
    unsigned int s;

    matrix res;

 //   cout << rn << " " << cn << endl;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            s = 0;
            for (k = 0; k < rn; k++)
                s = (s + (A.mat[i][k]*B.mat[k][j]));
            res.mat[i][j] = s;
        }
  //  cout << "amul\n";
    return res;
}

matrix mpwr(matrix b, ll p)
{
   // cout << "powr " << p << endl;
    if (p == 0)
    {
        return unit;
    }

    matrix x = mpwr(b, p/2);

 //   cout << "apwr " << p << endl;

    if (p%2 == 0)
    {
        return mmul(x, x);
    }
    else
    {
        return mmul(b, mmul(x, x));
    }
}


int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m;
    unsigned int ans;

    Cm[0][0] = Cm[1][0] = Cm[1][1] = 1;

    for (i = 2; i <= 51; i++)
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                Cm[i][j] = 1;
            else
            {
                Cm[i][j] = Cm[i-1][j-1] + Cm[i-1][j];
            }
        }

    for (i = 0; i < 52; i++)
        for (j = 0; j < 52; j++)
            if (i == j)
                unit.mat[i][j] = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

        if (n == 1)
        {
            printf("Case %lld: 1\n", cs);
        }
        else if (k == 0)
        {
            ans = n;
            printf("Case %lld: %u\n", cs, ans);
        }
        else
        {
            matrix base;

            cn = rn = k + 2;


            for (i = 1; i < rn; i++)
                for (j = i; j < rn; j++)
                {
                    base.mat[i][j] = Cm[k-i+1][j-i];

               //     cout << i << " " << j << " " << base.mat[i][j] << " " << Cm[k-i+1][j-1] << endl;
                }

            for (i = 1; i < cn; i++)
                base.mat[0][i] = Cm[k][i-1];

            base.mat[0][0] = 1;

//            for (i = 0; i < rn; i++)
//            {
//                for (j = 0; j < cn; j++)
//                    printf("%d ", base.mat[i][j]);
//                printf("\n");
//            }

            matrix R = mpwr(base, n-1);
       //     cout << "test\n";

            ans = 0;

            for (i = 0; i < cn; i++)
            {
                ans = ans + R.mat[0][i];
            }

            printf("Case %lld: %u\n", cs, ans);
        }
    }

    return 0;
}


