#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n); getchar();

struct node
{
    int v, c;
} tree[750100];
int arr[1000000];

void create (int n, int b, int e, int sz)
{
    if (b == e)
    {
        if (b <= sz)
        {
            //     cout << n << " " << b << " " << e << " " << arr[b] << endl;
            tree[n].v = arr[b];
            //      cout << n << " " << b << " " << e << " " << tree[n].v << " " << arr[b] << endl;
            tree[n].c = 1;
        }
        return ;
    }
    int l = 2*n;
    int r = l + 1;
    int mid = (b + e)/2;

    create(l, b, mid, sz);
    create(r, mid + 1, e, sz);
    tree[n].c = tree[l].c + tree[r].c;
}


void query(int n, int b, int e, int x)
{
    if (x > tree[n].c)
    {
        printf("none\n");
        return ;
    }

    if (b == e)
    {
        tree[n].c = 0;
        printf("%d\n", tree[n].v);
        return ;
    }

    int l = 2*n;
    int r = l + 1;
    int mid = (b + e)/2;

    //cout << n << " " << tree[n].c << " " << tree[l].c << " " << tree[r].c << endl;

    if (tree[l].c >= x)
        query(l, b, mid, x);
    else query(r, mid + 1, e, x - tree[l].c);

    tree[n].c = tree[l].c + tree[r].c;
}

void update(int n, int b, int e, int i, int x)
{
    if (b > i || e < i)
        return ;

    if (i <= b && e <= i)
    {
        tree[n].v = x;
        tree[n].c = 1;
        return ;
    }
    int l = 2*n;
    int r = l + 1;
    int mid = (b + e)/2;

    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);

    tree[n].c = tree[l].c + tree[r].c;
}

int main ()
{
//    freopen("outl.txt", "w", stdout);

    char ch;

    ll cs, t, i, j, k, n, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        for (i = 0; i <= 1000000; i++)
        {
            tree[i].v = 0;
            tree[i].c = 0;
        }

        sl(n);
        sl(q);
        for (i = 1; i <= n; i++)
        {
            sl(arr[i]);
        }

        create(1, 1, n+q, n);

        printf("Case %lld:\n", cs);

        for (i = 1; i <= q; i++)
        {
            scanf(" %c %lld", &ch, &x);

            if (ch == 'c')
                query(1, 1, n+q, x);
            else update(1, 1, n+q, n+i, x);

      //  cout << endl;
       // for (i = 1; i <= 50; i++)
         //   cout << i << " " << tree[i].v << " " << tree[i].c << endl;
       // cout << endl;

        }

    }

    return 0;
}
