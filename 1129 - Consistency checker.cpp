#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf(" %s", n);

struct node
{
    bool endm, flag;
    node *p[12];

    node()
    {
        endm = flag = false;
        for (ll i = 0; i < 12; i++)
            p[i] = 0;
    }
} *root;

void ins(char *s)
{
    node *cur = root;
    int id;
    for (ll i = 0; s[i] != 0; i++)
    {
        id = s[i] - '0';

    //    cout << i << " " << (char) (id + '0') << " " << cur << " " << cur->p[id] << endl;

        if (cur->p[id] == 0)
        {
            cur->p[id] = new node();
            cur->flag = true;
        }
        cur = cur->p[id];
    }
    cur->endm = true;
}

bool srch(char *s, node *cur = root)
{
    int id;
    for (ll i = 0; s[i] != 0; i++)
    {
        id = s[i] - '0';

        cur = cur->p[id];
    }
    if (cur->flag == true)
        return true;
    else return false;
}

void del(node *cur)
{
    for (ll i = 0; i < 12; i++)
    {
        if (cur->p[i] != 0)
            del(cur->p[i]);
    }
    delete(cur);
}

int main ()
{
    bool f;
    char s[10010][15], temp[10010];
    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        root = new node();
        sl(n);

        for (i = 1; i <= n; i++)
        {
            ss(s[i]);
            strcpy(temp, s[i]);
      //      cout << i << " " << s[i] << " " << temp << endl;
            ins(temp);
        }

        f = false;

        for (i = 1; i <= n; i++)
        {
            strcpy(temp, s[i]);
            f = srch(temp);
            if (f == true)
                break;
        }

        if (f == true)
            printf("Case %lld: NO\n", cs);
        else printf("Case %lld: YES\n", cs);

        del(root);
    }

    return 0;
}
