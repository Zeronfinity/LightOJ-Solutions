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
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

vector <ll> ed[1040], red[1040];
ll vis[1040], rvis[1040], et[1040], tm, comp[1040], compvis[1040];
bool last[1040];
map <ll, ll> pos;
map <ll, bool> is_node;
map <ll, map<ll,bool> > entered;
void dfs(ll u)  //forward DFS to find finishing time for each nodes
{
    vis[u] = 1;
    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];
        if (vis[v] == 0)
        {
            dfs(v);
        }
    }
    et[u] = tm++;
    pos[et[u]] = u; //saving that node u has et[u] finishing time
}
void rdfs(ll u, ll k) //reverse dfs to find connected components
{
    rvis[u] = 1;
    comp[u] = k;
    for (ll i = 0; i < red[u].size(); i++)
    {
        ll v = red[u][i];
        if (rvis[v] == 0)
        {
//            cout << ", " << rmp[v]; //printing the nodes in this component
            rdfs(v, k);
        }
    }
}

bool ans;

void fdfs(ll n)
{
    compvis[n] = 1;
    vis[n] = 1;


    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll v = ed[n][i];

     //   cout << n << " " << v << " " << comp[n] << " " << comp[v] << endl;

        if (comp[v] != comp[n])
        {
            if (last[comp[n]] == 0)
            {
                last[comp[n]] = 1;
            }
            else
            {
                ans = 0;
            }
        }

        if (vis[v] == 0)
        {

            fdfs(v);
        }
    }
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
  //   freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < 1000; i++)
        {
            ed[i].clear();
            red[i].clear();
        }

        is_node.clear();

        entered.clear();

        while(n--)
        {
            sl(k);

            while(k--)
            {
                sl(x);
                sl(y);
                //cout << x << " " << y << " " << entered[x][y] << " " << entered[2][3] << endl;
                if (entered[x][y] == 0)
                {
                    is_node[x] = 1;
                    is_node[y] = 1;
                    ed[x].pb(y);
                    red[y].pb(x);
                }
                entered[x][y] = 1;
               // cout << entered[x][y] << " " << entered[2][3] << endl;
            }
        }

        tm = 0;
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < 1000; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }
        sort(et, et + 1000, greater<ll>());
        k = 1;
        memset(rvis, 0, sizeof(rvis));
        for (i = 0; i < 1000; i++)
        {
            x = pos[et[i]]; // node with et[i] finishing time
            if (rvis[x] == 0)
            {
                //cout << rmp[x]; //printing the nodes in this component in a line, they all will become visited
                rdfs(x, k++);
                //    printf("\n");
            }
        }

        memset(vis, 0, sizeof(vis));
        memset(compvis, 0, sizeof(compvis));
        memset(last, 0, sizeof(last));

        ans = 1;

        fdfs(0);

        //  cout << ans << " " << k << endl;

        for (i = 0; i < 1000; i++)
        {
            if (compvis[i] == 0 && is_node[i] == 1)
            {
                ans = 0;
                break;
            }
        }

        if (ans == 1)
            printf("Case %lld: YES\n", cs);
        else printf("Case %lld: NO\n", cs);
    }

    return 0;
}
