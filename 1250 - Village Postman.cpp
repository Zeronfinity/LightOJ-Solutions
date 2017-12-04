#include<bits/stdc++.h>
using namespace std;

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define LL long long
#define fr first
#define pb push_back
#define sc second
#define pls pair<long long,string>
#define inf 1000000000
#define POP 1ll<<40
#define SZ(a) (a.size())

#define nsize 210

vector <ll> ed[nsize];
vector <ll> EulerTour;
ll deg[nsize];

void EulerDFS(ll u) //complexity O(VE)
{
    ll i,v;
    for(i = 0; i < ed[u].size(); i++)
    {
        v = ed[u][i];

        if(v != -1)
        {
            ed[u][i] = -1;

                for (ll j = 0; j < ed[v].size(); j++)
                    if (ed[v][j] == u)
                    {
                        ed[v][j] = -1;
                        break;
                    }

            EulerDFS(v);
        }
    }


// to save edge in EulerTour, send it as parameter to DFS, edge from parent to u
    EulerTour.pb(u);
}

bool Euler(ll edgeno = -5)
{
    ll i, Start, End, c = 0;
    Start = End = -1;
    for(i = 0; i < nsize; i++)
    {
            if (!(deg[i]&1)) continue;
            if (Start == -1)
                Start = i;
            else End = i;
            c++;
            continue;
    }

    if(c > 2 || c == 1) return false;

    if(Start == -1)
    {
        for(i = 0; i < nsize; i++)
            if (deg[i])
            {
                Start = i;
                break;
            }
    }

    EulerTour.clear();
    EulerDFS(Start);
    reverse(EulerTour.begin(), EulerTour.end());

    if (edgeno != -5)
        if (EulerTour.size() != edgeno + 1) return false; //if graph is connected, depends on what is saved in EulerTour

    return true;
}

int main()
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
        sl(n);
        sl(m);

        z = 0;

        for (i = 1; i <= n; i++)
        {
            sl(x);
            z += x;
            z -= i;
        }

        z -= m;

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);

            ed[x].pb(y);
            ed[y].pb(x);
        }

        EulerTour.clear();
        EulerDFS(1);
        reverse(EulerTour.begin(), EulerTour.end());

        printf("Case %lld: %lld\n", cs, z);

        for (i = 0; i < EulerTour.size(); i++)
        {
            if (i) printf(" ");
            printf("%lld", EulerTour[i]);
        }
        printf("\n");

        assert(Euler() == true);
    }

    return 0;
}
/*
7
6 1
1 3
3 5
1 2
2 3
1 4
4 3
*/
