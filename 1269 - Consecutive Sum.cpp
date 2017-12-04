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
#define pll pair <long long, long long>
#define pb push_back

ll ar[60000], cx[60000];

char s[35];

ll pwr(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2);

    x = (x*x);

    if (p%2 == 0)
        return x;
    else return (b*x);
}


struct node
{
    ll cnt;
    bool endm;
    node *next[3];
    node()
    {
        cnt = endm = 0;
        for(ll i=0; i < 3; i++)
            next[i] = 0;
    }
} *root;

void insert(char *str)
{
    ll id;

    node *cur = root;

    ll len = strlen(str);

    for(ll i = 0; i < len; i++)
    {
        id = s[i] - '0';

        if(cur->next[id] == 0)
            cur->next[id] = new node();

        cur = cur->next[id];
    }

    cur->endm = 1;
}

void del(node *cur)
{
    for(ll i=0; i < 3; i++)
        if(cur->next[i] != 0)
            del(cur->next[i]) ;

    delete(cur) ;
}

char res[35];

void traverse(node *cur, ll cnt = 0)
{
//   cout << cnt << " " << s[cnt] << " " << cur->next[0] << " " << cur->next[1] << " " << res << endl;
    if (cnt == 33)
        return ;

    if (s[cnt] == '0')
    {
        if (cur->next[1] != 0)
        {
            res[cnt] = '1';
            traverse(cur->next[1], cnt + 1);
        }
        else
        {
            res[cnt] = '0';
            traverse(cur->next[0], cnt + 1);
        }
    }
    else
    {
        if (cur->next[0] != 0)
        {
            res[cnt] = '0';
            traverse(cur->next[0], cnt + 1);
        }
        else
        {
            res[cnt] = '1';
            traverse(cur->next[1], cnt + 1);
        }
    }
}

void traverse2(node *cur, ll cnt = 0)
{
//   cout << cnt << " " << s[cnt] << " " << cur->next[0] << " " << cur->next[1] << " " << res << endl;
    if (cnt == 33)
        return ;

    if (s[cnt] == '0')
    {
    //    cout << cnt << " " << s[cnt] << " " << cur->next[0] << endl;
        if (cur->next[0] != 0)
        {
            res[cnt] = '0';
            traverse2(cur->next[0], cnt + 1);
        }
        else
        {
            res[cnt] = '1';
            traverse2(cur->next[1], cnt + 1);
        }
    }
    else
    {
        if (cur->next[1] != 0)
        {
            res[cnt] = '1';
            traverse2(cur->next[1], cnt + 1);
        }
        else
        {
            res[cnt] = '0';
            traverse2(cur->next[0], cnt + 1);
        }
    }
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, mx, mn, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
            cx[i] = cx[i-1]^ar[i];
        }

        root = new node();

        j = 0;

        for (i = 32; i >= 0; i--)
        {
            if ( (cx[n] & (1LL << i)) == 0)
                s[j++] = '0';
            else s[j++] = '1';

        //    cout << j << " " << s[j-1] << endl;
        }

        s[j] = 0;

        mx = mn = cx[1];

  //      cout << mx << " " << cx[1] << endl;

//        cout << s << endl;

        insert(s);

        for (i = n-1; i >= 0; i--)
        {
            j = 0;

            for (k = 32; k >= 0; k--)
            {
                if ( (cx[i] & (1LL << k)) == 0)
                    s[j++] = '0';
                else s[j++] = '1';
            }

            s[j] = 0;

  //          cout << s << endl;

            traverse(root);

    //        cout << res << endl;

            x = 0, j = 0;
            for (k = 32; k >= 0; k--, j++)
            {
                if (res[k] == '1')
                {
                  x += pwr(2, j);
                }
            }

            mx = max(mx, x^cx[i]);

        //    cout << s << endl;

            traverse2(root);

         //   cout << res << endl;

            x = 0, j = 0;
            for (k = 32; k >= 0; k--, j++)
            {
                if (res[k] == '1')
                {
                  x += pwr(2, j);
                }
            }

            mn = min(mn, x^cx[i]);


            insert(s);

       //     cout << i << " " << mn << " " << x << " " << cx[i] << " " << (x^cx[i]) << endl;
        }


        printf("Case %lld: %lld %lld\n", cs, mx, mn);

        del(root);
    }

    return 0;
}
