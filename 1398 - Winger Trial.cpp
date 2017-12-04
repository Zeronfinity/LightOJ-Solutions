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

ll xi[110], yi[110];

int main ()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ll l, w, n, d;

        sl(l);
        sl(w);
        sl(n);
        sl(d);

        init(0, 2*n+1, 2*n+1);

        for (i = 1; i <= n; i++)
        {
            sl(xi[i]);
            sl(yi[i]);

            add_edge(i, n+i, 1);

            if (yi[i] >= w - d)
                add_edge(0, i, 1);

            if (yi[i] <= d)
                add_edge(n+i, 2*n+1, 1);
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if ( (xi[i] - xi[j])*(xi[i] - xi[j]) + (yi[i] - yi[j])*(yi[i] - yi[j]) <= 4*d*d )
                {
                    add_edge(n+i, j, 1);
                    add_edge(n+j, i, 1);
                }
            }
        }

        printf("Case %lld: %lld\n", cs, dinitz());

    }

    return 0;
}

