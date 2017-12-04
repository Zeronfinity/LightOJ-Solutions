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

/*

    MAX FLOW Template code credit: Zobayer vai
    Link: http://zobayer.blogspot.com/2010/05/maximum-flow-dinitz-algorithm.html

*/
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

const int INF = 1000000000;
const int MAXN = 210, MAXE = 20010; //take node and edge twice in case node splitting

int src, snk, nNode, nEdge;
int Q[MAXN], last_edge[MAXN], pro[MAXN], dist[MAXN];
int flow[2*MAXE], cap[2*MAXE], prev_edge[2*MAXE], to[2*MAXE];


inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(last_edge);
}



inline void add_edge(int u, int v, int c, int bi = 0) { //bi = 0 for unidirected or directed
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;

    to[nEdge] = u, cap[nEdge] = bi==1?c:0, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;

}

bool bfs() {
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while (st < en) {
        u = Q[st++];
        for (i = last_edge[u]; i >= 0; i = prev_edge[i]) {
            v = to[i];
            if (flow[i] < cap[i] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk] != -1;
}

int dfs(int u, int fl) {
    if (u == snk) return fl;

    for (int &e = pro[u], v, df; e >= 0; e = prev_edge[e]) {
        v = to[e];
        if (flow[e] < cap[e] && dist[v] == dist[u] + 1) {
            df = dfs(v, min(cap[e] - flow[e], fl));
            if (df > 0) {
                flow[e] += df;
                flow[e ^ 1] -= df;
                return df;
            }
        }
    }
    return 0;
}

ll dinitz() {
    ll ret = 0;
    int df;
    while (bfs()) {
        for (int i = 0; i <= nNode; i++) pro[i] = last_edge[i];
        while (true) {
            df = dfs(src, INF);
            if (df) ret += (ll)df;
            else break;
        }
    }
    return ret;
}

char s[20];

int main ()
{
  //  freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, m, p, q, n, num, sz = 0;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        init(0, m+13, m+13);

        for (i = 1; i <= m; i++)
        {
            add_edge(0, i, 1);

            ss(s);

            if (!strcmp(s, "XXL"))
                add_edge(i, m+1, INF);
            else if (!strcmp(s, "XL"))
                add_edge(i, m+2, INF);
            else if (!strcmp(s, "L"))
                add_edge(i, m+3, INF);
            else if (!strcmp(s, "M"))
                add_edge(i, m+4, INF);
            else if (!strcmp(s, "S"))
                add_edge(i, m+5, INF);
            else if (!strcmp(s, "XS"))
                add_edge(i, m+6, INF);

            ss(s);

            if (!strcmp(s, "XXL"))
                add_edge(i, m+1, INF);
            else if (!strcmp(s, "XL"))
                add_edge(i, m+2, INF);
            else if (!strcmp(s, "L"))
                add_edge(i, m+3, INF);
            else if (!strcmp(s, "M"))
                add_edge(i, m+4, INF);
            else if (!strcmp(s, "S"))
                add_edge(i, m+5, INF);
            else if (!strcmp(s, "XS"))
                add_edge(i, m+6, INF);
        }

        for (i = 1; i <= 6; i++)
        {
            add_edge(m+i, m+6+i, n);
            add_edge(m+6+i, m+13, INF);
        }

        if (dinitz() >= m)
        {
            ans = 1;
        }
        else
            ans = 0;

        if (ans == 1)
            printf("Case %lld: YES\n", cs);
        else printf("Case %lld: NO\n", cs);
    }

    return 0;
}
