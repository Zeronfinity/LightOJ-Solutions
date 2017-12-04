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

ll a[55], d[55], f[55];

ll mark[10010];

vector <pll > vec;


/*

    MAX FLOW Template code credit: Zobayer vai
    Link: http://zobayer.blogspot.com/2010/05/maximum-flow-dinitz-algorithm.html

*/
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

const int INF = 1000000000;
const int MAXN = 510, MAXE = 100010; //take node and edge twice in case node splitting

int src, snk, nNode, nEdge;
int Q[MAXN], last_edge[MAXN], pro[MAXN], dist[MAXN];
int flow[2*MAXE], cap[2*MAXE], prev_edge[2*MAXE], to[2*MAXE];
int edge_no[MAXN][MAXN];


inline void init(int _src, int _snk, int _n)
{
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(last_edge);
}


inline void add_edge(int u, int v, int c, int bi = 0)   //bi = 0 for unidirected or directed
{
    edge_no[u][v] = nEdge;

    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;

    to[nEdge] = u, cap[nEdge] = bi==1?c:0, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;

}

bool bfs()
{
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while (st < en)
    {
        u = Q[st++];
        for (i = last_edge[u]; i >= 0; i = prev_edge[i])
        {
            v = to[i];
            if (flow[i] < cap[i] && dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk] != -1;
}

int dfs(int u, int fl)
{
    if (u == snk) return fl;

    for (int &e = pro[u], v, df; e >= 0; e = prev_edge[e])
    {
        v = to[e];
        if (flow[e] < cap[e] && dist[v] == dist[u] + 1)
        {
            df = dfs(v, min(cap[e] - flow[e], fl));
            if (df > 0)
            {
                flow[e] += df;
                flow[e ^ 1] -= df;
                return df;
            }
        }
    }
    return 0;
}

ll dinitz()
{
    ll ret = 0;
    int df;
    while (bfs())
    {
        for (int i = 0; i <= nNode; i++) pro[i] = last_edge[i];
        while (true)
        {
            df = dfs(src, INF);
            if (df) ret += (ll)df;
            else break;
        }
    }
    return ret;
}

char s[10010][33];

int itstart[10010], itsend[10010];


ll vecin[10010];

int main ()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ll tab, c, e;

        sl(n);
        sl(tab);
        sl(c);
        sl(e);

        memset(mark, 0, sizeof(mark));

        ll sum = 0;

        memset(itstart, 0, sizeof(itstart));
        memset(itsend, 0, sizeof(itsend));

        for (i = 1; i <= n; i++)
        {
            sl(a[i]);
            sl(d[i]);
            sl(f[i]);

            itstart[a[i]] = 1;
            itsend[d[i]-1] = 1;

            for (j = a[i]; j < d[i]; j++)
            {
                mark[j]++;
            }

            sum += f[i];
        }

        bool act = 0;

        ll st;

        vec.clear();

        for (i = 1; i <= 10005; i++)
        {
//            if (i <= 6)
  //              cout << i << " arkoto " << act << " " << mark[i] << " " << itstart[i] << " " << itsend[i-1] << endl;

            if (act == 0 && mark[i] != 0)
            {
                act = 1;
                st = i;
            }
            else if (act == 1 && (mark[i] != mark[i-1] || itstart[i] == 1 || itsend[i-1] == 1))
            {
                vec.pb(pll(st, i-1));

                if (mark[i] == 0)
                    act = 0;
                else
                {
                    st = i;
                }
            }
        }
//
//        for (i = 0; i < vec.size(); i++)
//        {
//            cout << i << " partn " << vec[i].fr << " " << vec[i].sd << endl;
//        }

        init(0, vec.size() + n + 1, vec.size() + n + 1);

        for (i = 1; i <= n; i++)
        {
            add_edge(0, i, f[i]);

            for (j = 0; j < vec.size(); j++)
            {
                if (a[i] <= vec[j].fr && vec[j].sd < d[i])
                {
                    add_edge(i, n+j+1, vec[j].sd - vec[j].fr + 1);
                }
            }
        }

        for (i = 0; i < vec.size(); i++)
        {
            add_edge(n+i+1, n+vec.size()+1, tab*c*(vec[i].sd - vec[i].fr + 1));
        }

        //     cout << "vec " << vec.size() << endl;
//
//        for (i = 0; i < vec.size(); i++)
//        {
//            cout << i << " " << vec[i].fr << " " << vec[i].sd << endl;
//        }

        printf("Case %lld: ", cs);

        ll din = dinitz();

        if (din != sum)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");

            for (i = 1; i <= e-1; i++)
            {
                for (j = 1; j <= tab*c; j++)
                {
                    s[i][j] = '.';
                }
            }

            for (i = 1; i <= e-1; i++)
            {
                for (j = 0; j < vec.size(); j++)
                {
                    if (vec[j].fr <= i && i <= vec[j].sd)
                    {
                        vecin[i] = j;
                        break;
                    }
                }
            }

            ll yo = tab*c;

            for (ll yoo = 1; yoo <= yo; yoo++)
            {
                for (j = 1; j <= e-1; j++)
                    for (i = 1; i <= n; i++)
                    {
                        if (a[i] <= j && j < d[i] && a[i] <= vec[vecin[j]].fr && vec[vecin[j]].sd < d[i])
                        {
                            x = flow[edge_no[i][vecin[j]+n+1]];
                    //    cout << yo << " " << j << " " << i << " " << vecin[j] << " " << x << endl;

                            if (x > 0)
                            {
                                if (i <= 26)
                                    s[j][yoo] = 'a' + i - 1;
                                else
                                    s[j][yoo] = 'A' + i - 27;

                                flow[edge_no[i][vecin[j]+n+1]]--;
                                break;
                            }
                        }
                    }
            }

            for (i = 1; i <= e-1; i++)
            {
                for (j = 1; j <= tab*c; j++)
                {
                    printf("%c", s[i][j]);
                    if (j%c == 0 && j != tab*c)
                        printf("|");
                }
                printf("\n");
            }
        }
    }

    return 0;
}

