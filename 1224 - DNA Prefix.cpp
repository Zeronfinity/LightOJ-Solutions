#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf(" %s", n);

ll mx;

struct node
{
    bool endm;
    ll cnt;
    node *p[4];
    node () {
        endm = false;
        cnt = 0;
        for (ll i = 0; i < 4; i++)
            p[i] = 0;
    }
} *root;

void ins(char *s, node *cur = root)
{
    ll id, i;

    for (i = 0; s[i] != 0; i++)
    {
        if (s[i] == 'A')
            id = 0;
        else if (s[i] == 'C')
            id = 1;
        else if (s[i] == 'G')
            id = 2;
        else id = 3;

        if (cur->p[id] == 0)
        {
            cur->p[id] = new node();
        }
        (cur->p[id])->cnt++;
        cur = cur->p[id];
    }
    cur->endm = true;
}

void fun(ll i = 0, node *cur = root)
{
//    cout << i << " " << cur->cnt << " " << mx << endl;
    if (i*cur->cnt > mx)
        mx = i*cur->cnt;

    for (ll j = 0; j < 4; j++)
        if (cur->p[j] != 0)
            fun(i+1, cur->p[j]);
    delete(cur);
}

int main ()
{
    char temp[51];
    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        root = new node();
        sl(n);

        for (i = 1; i <= n; i++)
        {
            ss(temp);
            ins(temp);
        }

        mx = 0;

        fun();

        printf("Case %lld: %lld\n", cs, mx);
    }

    return 0;
}
