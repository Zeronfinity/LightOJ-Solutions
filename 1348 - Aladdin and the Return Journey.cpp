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

vector <ll> ed[30100];
ll tm;

ll st[30100], ft[30100];

ll a[30100];

#define tsz 30101

ll tree[5*tsz];

ll n;

void create(ll node, ll b, ll e)
{
    tree[node] = 0;

    if (b == e)
        return ;

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);
}


ll query(ll node, ll b, ll e, ll i, ll j, ll c = 0)
{
   // cout << node << " a " << b << " " << e << " " << i << " " << j << " " << c << endl;
    if (e < i || j < b)
        return 0;

    c += tree[node];

    if (i <= b && e <= j)
        return c;

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j, c);
    ll p2 = query(right, mid + 1, e, i, j, c);
   // cout << node << " b " << b << " " << e << " " << i << " " << j << " " << p1 << " " << p2 << endl;

    return p1|p2;
}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if (e < i || j < b)
    {
        return ;
    }

    if (i <= b && e <= j)
    {
        tree[node] += val;
        return;
    }

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
}

#define nodes_no 30100

ll L[nodes_no];
ll P[nodes_no][22];

ll lca(ll p, ll q)
{
    ll tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        ll next=log+1;
        if((1<<next)>L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return P[p][0];
}

void lca_init()
{
    ll i, j;

    for (j = 1; (1 << j) <= n; j++)
        for (i = 0; i < n; i++)
        {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
}

void dfs(ll u, ll p, ll h = 0)
{
    L[u] = h;
    P[u][0] = p;
    st[u] = ++tm;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        if (ed[u][i] != p)
            dfs(ed[u][i], u, h + 1);
    }

    ft[u] = tm;
}


int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t = 0, i, j, k, x, y, z, ans, q, m;

    sl(t);
    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            sl(a[i]);
            ed[i].clear();
        }

        for (i = 1; i <= n-1; i++)
        {
            sl(x);
            sl(y);
            ed[x].pb(y);
            ed[y].pb(x);
        }

        memset (P, -1, sizeof(P));

        tm = 0;

        dfs(0, -1);


        for (i = 0; i < n; i++)
        {
        //    cout << i << " " << st[i] << " " << ft[i] << endl;
            update(1, 1, tm, st[i], ft[i], a[i]);
        }

        lca_init();

        printf("Case %lld:\n", cs);

        sl(q);

        while(q--)
        {
            sl(k);
            sl(x);
            sl(y);

            if (k == 1)
            {
                z = query(1, 1, tm, st[x], st[x]);
           //     cout << z << endl;
                if (P[x][0] != -1)
                    z -= query(1, 1, tm, st[P[x][0]], st[P[x][0]]);

             //   cout << z << endl;

                update(1, 1, tm, st[x], ft[x], y - z);
                a[x] = y;
            }
            else
            {
                z = lca(x, y);
                ll xq = query(1, 1, tm, st[x], st[x]);
                ll yq = query(1, 1, tm, st[y], st[y]);
                ll zq = query(1, 1, tm, st[z], st[z]);

//                cout << z << " " << xq << " " << yq << " " << zq << endl;

                printf("%lld\n", xq + yq - 2*zq + a[z]);
            }
        }

        create(1, 1, tm);
    }
    return 0;
}
