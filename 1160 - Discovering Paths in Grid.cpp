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

ll adj[35][35], temp[35][35], res[35][35], avail;

struct data
{
    ll mat[35][35];
};

map <ll, ll> mp;
map <ll, data> pmp;

void fnd(ll i, ll num, ll anum, ll cnt);

void create(ll i, ll cnt, ll num)
{
    if (i >= 7)
    {
        if (cnt == 4)
        {
            //       cout << num << endl;
            if (mp.count(num) == 0)
            {
                mp[num] = avail++;
            }
            fnd(0, num, 0, 0);
        }
        return ;
    }

    create(i + 1, cnt, num);

    if (cnt < 4)
        create(i + 1, cnt + 1, (num | (1 << i)));
}

void fnd(ll i, ll num, ll anum, ll cnt)
{
    // cout << i << " " << num << " " << anum << " " << cnt << " " << (num & (1 << i)) << endl;
    if (i >= 7)
    {
        if (cnt == 4)
        {
            if (mp.count(anum) == 0)
            {
                mp[anum] = avail++;
            }
            adj[mp[num]][mp[anum]] = (adj[mp[num]][mp[anum]] + 1)%mod;
            //  cout << num << " " << anum << " " << adj[num][anum] << endl;
        }
        return ;
    }

    if ( (num & (1 << i)) != 0)
    {
        if (i != 0)
        {
            if ((anum & (1 << (i-1))) == 0 && cnt < 4)
                fnd(i + 1, num, anum | (1 << (i-1)), cnt + 1);
        }

        if (i != 6)
        {
            if ((anum & (1 << (i+1))) == 0 && cnt < 4)
                fnd(i + 1, num, anum | (1 << (i+1)), cnt + 1);
        }
    }
    fnd(i + 1, num, anum, cnt);
}

ll cn, rn;

void pwr(ll p)
{
    ll i, j, k, s;
  //  cout << "pwr " << p << endl;

    if (p == 0)
    {
        for (i = 0; i < rn; i++)
            for (j = 0; j < cn; j++)
            {
                if (i != j)
                    res[i][j] = 0;
                else res[i][j] = 1;
            }
        return ;
    }

    if (pmp.count(p) != 0)
    {
        for (i = 0; i < cn; i++)
            for (j = 0; j < cn; j++)
                res[i][j] = pmp[p].mat[i][j];

        return ;
    }

    pwr(p/2);

   // cout << "apwr " << p << endl;

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
                    s = (s + (temp[i][k]*temp[k][j])%mod)%mod;
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
                    s = (s + (temp[i][k]*(temp[k][j]))%mod)%mod;
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
                    s = (s + (adj[i][k]*(temp[k][j]))%mod)%mod;
                res[i][j] = s;
            }
    }
    data temp;

    for (i = 0; i < cn; i++)
        for (j = 0; j < cn; j++)
            temp.mat[i][j] = res[i][j];

    pmp[p] = temp;
}


int main ()
{
    //  freopen("inl.txt", "r", stdin);
//     freopen("outl.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    mod = 1000000007;

    avail = 0;

    create(0, 0, 0);


    cn = rn = 35;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        x = 0;

        for (i = 6; i >= 0; i--)
        {
            sl(y);

            if (y != 0)
                x = x | (1 << i);
        }

        x = mp[x];

        if (n == 1)
        {
            printf("Case %lld: 1\n", cs);
        }
        else
        {
            //     cout << x << endl;
//            for (i = 0; i < cn; i++)
//            {
//                for (j = 0; j < cn; j++)
//                    printf("%lld ", adj[i][j]);
//                printf("\n");
//            }
//            cout << endl;
            pwr(n-1);

//            for (i = 0; i < 7; i++)
//            {
//                for (j = 0; j < 7; j++)
//                    printf("%lld ", res[i][j]);
//                printf("\n");
//            }

            //   cout << "t\n";
            ans = 0;
            for (i = 0; i < cn; i++)
            {
         //       cout << i << " " << x << " " << adj[x][i] << endl;
                ans = (ans + res[x][i])%mod;
            }

            printf("Case %lld: %lld\n", cs, ans);
        }
    }

    return 0;
}
