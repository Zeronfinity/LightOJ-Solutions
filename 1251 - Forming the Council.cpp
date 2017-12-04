#include <bits/stdc++.h>

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
#define inf (1LL<<62)
#define fr first
#define sc second
#define EPS 0.0000000001

#define nsz 16010

vector <ll> ed[nsz+10], red[nsz+10];
bool vis[nsz+10];
vector <ll> order;
ll comp[nsz+10];

void dfs1(ll u)
{
    if (vis[u]) return ;
    vis[u] = 1;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        dfs1(ed[u][i]);
    }
    order.push_back(u);
}

void dfs2(ll u, ll cno)
{
    comp[u] = cno;
    for (ll i = 0; i < red[u].size(); i++)
    {
        ll v = red[u][i];
        if (comp[v] == -1)
            dfs2(v, cno);
    }
}

vector <ll> vec;

int main ()
{
    // #ifndef zeron
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  #endif
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(m);
        sl(n);

        for (i = 0; i <= 2*n; i++) //will use 0 indexed nodes
        {
            vis[i] = 0;
            ed[i].clear();
            red[i].clear();
            comp[i] = -1;
        }

        for (i = 1; i <= m; i++)
        {
            char ch1, ch2;
            scanf(" %c%lld %c%lld", &ch1, &x, &ch2, &y);

            x = 2*(x-1); //making node number 1 to 0, 2 to 2, 3 to 4 and so on..
            y = 2*(y-1);

            if (ch1 == '-')
                x ^= 1;

            if (ch2 == '-')
                y ^= 1;

          //  cout << x << " " << y << endl;

            ed[x^1].pb(y);
            ed[y^1].pb(x);

            red[y].pb(x^1);
            red[x].pb(y^1);
        }

        order.clear();

        for (i = 0; i < 2*n; i+= 2)
        {
        //    cout << i << " " << vis[i] << " " << vis[i^1] << endl;

            if (!vis[i])
                dfs1(i);
            if (!vis[i^1])
                dfs1(i^1);
        }

        reverse(order.begin(), order.end());
        for (i = 0, j = 1; i < order.size(); i++)
        {
            ll v = order[i];
            if (comp[v] == -1)
                dfs2(v, j++);
     //       cout << v << " yo " << comp[v] << endl;
        }

        printf("Case %lld: ", cs);

        for (i = 0; i < n; i++)
            if (comp[i] == comp[i^1])
            {
                printf("No\n");
                break;
            }

        if (i != n)
            continue;

        vec.clear();

        for (i = 0; i < 2*n; i += 2)
        {
            // if comp[i] > comp[i^1], we are taking i = 1, otherwise i = 0
            if (comp[i] > comp[i^1]) //have to take the one which comes later in top sort
            {
                vec.pb(i/2 + 1); //converting node to original 1-based index
            }
        }

        sort(vec.begin(), vec.end());

        printf("Yes\n");
        printf("%lld", (ll) vec.size());

        for (i = 0; i < vec.size(); i++)
        {
            printf(" %lld", vec[i]);
        }

        printf("\n");
    }

    return 0;
}
