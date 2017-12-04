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
    ll mat[52][52];

    matrix() //initializing to 0
    {
        for (ll i = 0; i < 52; i++)
            for (ll j = 0; j < 52; j++)
                mat[i][j] = 0;
    }
} unit;

matrix madd(matrix A, matrix B)
{
    ll i, j;

    matrix res;

    for (i = 0; i < rn; i++)
        for (j = 0; j < cn; j++)
        {
            res.mat[i][j] = (A.mat[i][j] + B.mat[i][j])%10;
        }
        return res;
}

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
                s = (s + (A.mat[i][k]*B.mat[k][j])%10)%10;
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

matrix solve(matrix A, ll p)
{
    if (p == 1)
    {
//        cout << p << endl;
//        for (ll i = 0; i < rn; i++)
//        {
//            for (ll j = 0; j < cn; j++)
//                printf("%lld ", A.mat[i][j]);
//            printf("\n");
//        }
        return A;
    }

//    cout << "b " << p << "\n";

    matrix x = solve(A, p/2);
    matrix y = mpwr(A, p/2);

//    cout << "a " << p << "\n";
//
//        for (ll i = 0; i < rn; i++)
//        {
//            for (ll j = 0; j < cn; j++)
//                printf("%lld ", x.mat[i][j]);
//            printf("\n");
//        }

    if (p%2 == 0)
    {
        return mmul(x, madd(unit, y));
    }
    else
    {
        return madd(mmul(x, madd(unit, y)), mpwr(A, p));
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    for (i = 0; i < 40; i++)
        for (j = 0; j < 40; j++)
            if (i == j)
                unit.mat[i][j] = 1;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

        matrix A;

        rn = cn = n;

        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                sl(A.mat[i][j]);
            }

        matrix R = solve(A, k);

        printf("Case %lld:\n", cs);
        for (i = 0; i < rn; i++)
        {
            for (j = 0; j < cn; j++)
                printf("%lld", R.mat[i][j]);
            printf("\n");
        }
    }

    return 0;
}
