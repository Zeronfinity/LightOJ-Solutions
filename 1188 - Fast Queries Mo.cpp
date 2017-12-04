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
#define fr first
#define sd second

#define qsize 50010

ll cur_ans, cl, cr;
ll cnt[100100];

ll ans[qsize];
ll bsize; //block size, sqrt of n

ll a[100100];

struct moq
{
    ll l, r, id;
} qr[qsize];

bool mo_comp(moq l, moq r)
{
    ll block_l = l.l/bsize;
    ll block_r = r.l/bsize;
    if(block_l != block_r)
        return block_l < block_r; //sorting by block number of queries first
    return l.r < r.r; //if block numbers are equal, sorting by right limit
}

void add(ll x)
{
 //   cout << "add " << x << " " << cnt[x] << endl;
    cnt[x]++;
    if (cnt[x] == 1)
        cur_ans++;
}

void rem(ll x)
{
    if (cnt[x] > 0)
    {
        cnt[x]--;
        if (cnt[x] == 0)
            cur_ans--;
    }
}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 1; i <= n; i++)
            sl(a[i]);

        for (i = 1; i <= m; i++)
        {
            sl(qr[i].l);
            sl(qr[i].r);
            qr[i].id = i;
        }

        bsize = sqrt((double) n);
        sort(qr + 1, qr + m + 1, mo_comp);

        memset(cnt, 0, sizeof(cnt));

        cl = cr = 1;
        cur_ans = 0;
        add(a[1]);

        for (i = 1; i <= m; i++)
        {
            while (cr < qr[i].r)
            {
                cr++;
                add(a[cr]);
            }

            while(cr > qr[i].r)
            {
                rem(a[cr]);
                cr--;
            }

            while (cl < qr[i].l)
            {
                rem(a[cl]);
                cl++;
            }

            while(cl > qr[i].l)
            {
                cl--;
                add(a[cl]);
            }

            ans[qr[i].id] = cur_ans;
        }

        printf("Case %lld:\n", cs);
        for (i = 1; i <= m; i++)
            printf("%lld\n", ans[i]);
    }

    return 0;
}
