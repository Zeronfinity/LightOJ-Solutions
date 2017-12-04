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

#define ll unsigned int
#define sl(n) scanf("%u", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

ll adj[7][131][131], temp[131][131], res[131][131];

struct data
{
    ll mat[131][131];
};

map <ll, data> pmp;
ll sz[8];

ll cn, rn;

void pwr(ll n, ll p)
{
    ll i, j, k, s;
//    cout << "pwr " << p << endl;
//
//        cout << endl;
//
//        for (ll i = 0; i <= 6; i++)
//        {
//            for (ll j = 0; j <= 6; j++)
//            {
//                cout << res[i][j] << " ";
//         //       ans += res[i][j];
//            }
//            cout << endl;
//        }


    if (p == 0)
    {
//        cout << "oi " << rn << " " << cn << endl;
        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                if (i != j)
                    res[i][j] = 0;
                else res[i][j] = 1;
//                cout << i << " " << j << " " << res[i][j] << endl;
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

    pwr(n, p/2);

//        cout << endl;
//
//        for (ll i = 0; i <= 6; i++)
//        {
//            for (ll j = 0; j <= 6; j++)
//            {
//                cout << res[i][j] << " ";
//         //       ans += res[i][j];
//            }
//            cout << endl;
//        }
//
//    cout << "apwr " << p << endl;

    for (i = 0; i < cn; i++)
        for (j = 0; j < rn; j++)
            temp[i][j] = res[i][j];

    if (p%2 == 0)
    {
        for (i = 0; i < cn; i++)
            for (j = 0; j < rn; j++)
            {
                s = 0;
                for (k = 0; k < rn; k++)
                    s = (s + (temp[i][k]*temp[k][j]));
                res[i][j] = s;
            }
    }
    else
    {
        for (i = 0; i < cn; i++)
            for (j = 0; j < cn; j++)
            {
                s = 0;
                for (k = 0; k < rn; k++)
                    s = (s + (temp[i][k]*(temp[k][j])));
                res[i][j] = s;
            }

        for (i = 0; i < rn; i++)
            for (j = 0; j < rn; j++)
                temp[i][j] = res[i][j];

        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                s = 0;
                for (k = 0; k < cn; k++)
                    s = (s + (adj[n][i][k]*(temp[k][j])));
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

//        cout << endl << "keekee\n";
//
//        for (ll i = 0; i <= 6; i++)
//        {
//            for (ll j = 0; j <= 6; j++)
//            {
//                cout << res[i][j] << " ";
//         //       ans += res[i][j];
//            }
//            cout << endl;
//        }
}

void make_adj(ll n)
{
    ll i, mx, x, j, cnt = n;
    for (i = 0; i <= n-1; i++)
    {
        mx = max(i - 0, n - i);

        mx = mx*mx - 1;


        for (j = 1; j < mx; j++)
        {
            adj[n][cnt + j][cnt + j+1] = 1;
        }

        adj[n][i][cnt + 1] = 1;

        for (j = 0; j <= n; j++)
        {
            if (i == j)
                continue;

            x = i - j;

            x = x*x;

            x--;

            if (x == 0)
                adj[n][i][j] = 1;
            else
                adj[n][cnt + x][j] = 1;
        }

        cnt += mx;
    }

    sz[n] = cnt + 2;
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, mx, cnt = 6;


    for (i = 2; i <= 6; i++)
        make_adj(i);
  //  cout << cnt << endl;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);

//        cout << sz[n] << endl;

        cn = rn = sz[n];

        pwr(n, k);

        ans = 0;

//        for (i = 0; i <= 5; i++)
//        {
//            for (j = 0; j <= 5; j++)
//            {
//                cout << adj[i][j] << " ";
//         //       ans += res[i][j];
//            }
//            cout << endl;
//        }
//
//        cout << endl;
//
//        for (i = 0; i <= 5; i++)
//        {
//            for (j = 0; j <= 5; j++)
//            {
//                cout << res[i][j] << " ";
//         //       ans += res[i][j];
//            }
//            cout << endl;
//        }

        for (i = 1; i <= n - 1; i++)
        {
            for (j = 0; j <= n - 1; j++)
            {
//                cout << i << " " << j << " " << res[i][j] << " " << ans << endl;
                ans += res[i][j];
            }
        }

        printf("Case %u: %u\n", cs, ans);
    }

    return 0;
}
