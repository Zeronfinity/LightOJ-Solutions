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

ll avail;
map <ll, ll> mp, rmp;

#define msz 36

unsigned int mat[msz][msz], temp[msz][msz], res[msz][msz];

//struct data
//{
//    ll mat[msz][msz];
//};
//
//map <ll, data> pmp;

ll cn, rn;

void mpwr(ll p)
{
    ll i, j, k;
    unsigned int s;

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
                s = (s + (temp[i][k]*temp[k][j]));
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
                    s = (s + (mat[i][k]*(temp[k][j])));
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

void createg(ll i, ll cnt, ll n, ll p);

void createn(ll i, ll cnt, ll n)
{
//   cout << "n " << i << " " << cnt << " " << n << endl;
    if (i >= 10)
    {
        if (cnt == 2)
            createg(0, 0, 0, n);
        return ;
    }

    if (cnt < 2)
    {
        bool allowed = true;

        if (i != 0)
        {
            if ( (n & (1LL << (i-1))) != 0)
                allowed = false;
        }

        if (allowed == true)
            createn( i + 1, cnt + 1, n | (1LL << i) );
    }
    createn( i+1, cnt, n );
}

void createg(ll i, ll cnt, ll n, ll p)
{
    // cout << "g " << i << " " << cnt << " " << n << " " << p << endl;

    if (i >= 10)
    {
        if (cnt == 2)
        {
            if (mp.count(n) == 0)
            {
                mp[n] = avail++;
                rmp[avail - 1] = n;
            }
            if (mp.count(p) == 0)
            {
                mp[p] = avail++;
                rmp[avail - 1] = p;
            }
            mat[mp[p]][mp[n]] = 1;
        }
        return ;
    }

    if (cnt < 2)
    {
        bool allowed = true;

        if (i != 0)
            if ( (p & (1LL << (i-1)) ) != 0 ) allowed = false;

        if (i != 0)
            if ( (n & (1LL << (i-1)) ) != 0 ) allowed = false;

        if (i != 9)
            if ( (p & (1LL << (i+1)) ) != 0 ) allowed = false;

        if ( (p & (1LL << (i)) ) != 0 ) allowed = false;

        if (allowed == true)
            createg( i + 1, cnt + 1, n | (1LL << i), p );
    }

    createg(i + 1, cnt, n, p);

}

void bin(ll n, ll cnt)
{
    if (cnt == 10)
        return ;

    bin(n/2, cnt + 1);

    cout << n%2;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m;
    unsigned int ans;

    avail = 0;
    createn(0, 0, 0);
    //cout << avail << endl;

    cn = rn = msz;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

//        if (n == 1)
//        {
//            printf("Case %lld: 36\n", cs);
//            continue;
//        }

        mpwr(n-1);

//        for (i = 0; i < rn; i++)
//            for (j = 0; j < cn; j++)
//            {
//                if (res[i][j] == 1)
//                {
//                    bin(rmp[i], 0);
//                    //             cout << rmp[i];
//                    cout << " ";
//                    bin(rmp[j], 0);
//                    //           cout << rmp[j];
//                    cout << " " << res[i][j] << " " << ans++ << endl;
//                }
//            }

        ans = 0;

        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                //       cout << i << " " << j << " " << res[i][j] << " " << ans << endl;
                ans += res[i][j];
            }
        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
