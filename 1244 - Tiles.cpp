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

#define msz 4

ll mod;

ll mat[msz][msz], temp[msz][msz], res[msz][msz];

struct data
{
    ll mat[msz][msz];
};

map <ll, data> pmp;

ll cn, rn;

void mpwr(ll p)
{
    ll i, j, k, s;

  //  cout << "pwr " << p << endl;

    if (p == 0)
    {
//        cout << "oi " << rn << " " << cn << endl;
        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                if (i != j)
                    res[i][j] = 0;
                else res[i][j] = 1;
            }
        return ;
    }

//    if (pmp.count(p) != 0)
//    {
//        for (i = 0; i < cn; i++)
//            for (j = 0; j < cn; j++)
//                res[i][j] = pmp[p].mat[i][j];
//
//        return ;
//    }

    mpwr(p/2);

//    cout << "apwr " << p << endl;

    for (i = 0; i < cn; i++)
        for (j = 0; j < rn; j++)
            temp[i][j] = res[i][j];


        for (i = 0; i < cn; i++)
            for (j = 0; j < rn; j++)
            {
                s = 0;
                for (k = 0; k < rn; k++)
                    s = (s + (temp[i][k]*temp[k][j])%mod)%mod;
                res[i][j] = s;
            }

    if (p%2 == 0)
    {
    }
    else
    {

        for (i = 0; i < rn; i++)
            for (j = 0; j < rn; j++)
                temp[i][j] = res[i][j];

        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                s = 0;
                for (k = 0; k < cn; k++)
                    s = (s + (mat[i][k]*(temp[k][j]))%mod)%mod;
                res[i][j] = s;
            }
    }
//    data temp;
//
//    for (i = 0; i < cn; i++)
//        for (j = 0; j < cn; j++)
//            temp.mat[i][j] = res[i][j];
//
//    pmp[p] = temp;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;


    mat[0][0] = mat[0][1] = mat[0][2] = mat[0][3] = mat[1][0] = mat[2][1] = mat[2][3] = mat[3][1] = mat[3][3] = 1;

    cn = rn = 4;

    mod = 10007;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        if (n == 1)
            printf("Case %lld: 1\n", cs);
        else if (n == 2)
            printf("Case %lld: 2\n", cs);
        else
        {
            mpwr(n-2);
        //    cout << "t";

            ans = ((((2*res[0][0])%mod + res[0][1])%mod + res[0][2])%mod + res[0][3])%mod;

            printf("Case %lld: %lld\n", cs, ans);
        }
    }

    return 0;
}
