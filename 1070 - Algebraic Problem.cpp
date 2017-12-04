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

#define ll unsigned long long
#define sl(n) scanf("%llu", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

ll A[2][2], res[2][2], temp[2][2];

void pwr(ll n)
{
    ll i, j, k, s;
    if (n == 0)
    {
        res[0][0] = 1, res[0][1] = 0;
        res[1][0] = 0, res[1][1] = 1;
        return ;
    }

    pwr(n/2);

 //   cout << "n is " << n << endl;
   // for (i = 0; i < 2; i++)
     //   for (j = 0; j < 2; j++)
       //     printf("%llu ", res[i][j]);
         //   cout << "\n";

    if (n%2 == 0)
    {
        temp[0][0] = res[0][0];
        temp[0][1] = res[0][1];
        temp[1][0] = res[1][0];
        temp[1][1] = res[1][1];

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                {
                    s += temp[i][k]*temp[k][j];
                }
                res[i][j] = s;
            }
    }
    else
    {
        temp[0][0] = res[0][0];
        temp[0][1] = res[0][1];
        temp[1][0] = res[1][0];
        temp[1][1] = res[1][1];

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                {
                    s += temp[i][k]*temp[k][j];
                }
                res[i][j] = s;
            }

        temp[0][0] = res[0][0];
        temp[0][1] = res[0][1];
        temp[1][0] = res[1][0];
        temp[1][1] = res[1][1];

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                s = 0;
                for (k = 0; k < 2; k++)
                {
                    s += temp[i][k]*A[k][j];
                }
                res[i][j] = s;
            }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, p, q, m;

    sl(t);

    long long nen;

    for (cs = 1; cs <= t; cs++)
    {
        sl(p);
        sl(q);
        sl(n);

//        cout << p << endl;

        if (n == 0)
            ans = 2;
        else if (n == 1)
            ans = p;
        else
        {
            nen = q;
            nen *= -1;
            q = nen;

            A[0][0] = p;
            A[0][1] = q;
            A[1][0] = 1;
            A[1][1] = 0;

            pwr(n-1);

            ans = res[0][0]*p + res[0][1]*2;
        }
        printf("Case %llu: %llu\n", cs, ans);
    }

    return 0;
}
