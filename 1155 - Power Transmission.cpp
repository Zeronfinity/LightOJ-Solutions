#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>

#define ll long long
#define lf double

#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INFP ((ll)1<<62)
#define INFN (0-(ll)1<<62)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

/*

    MAX FLOW Template code credit: Zobayer vai
    Link: http://zobayer.blogspot.com/2010/05/maximum-flow-dinitz-algorithm.html

*/

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

const int INF = 1000000000;
const int MAXN = 300, MAXE = 9010;

int src, snk, nNode, nEdge;
int Q[MAXN], last_edge[MAXN], pro[MAXN], dist[MAXN];
int flow[2*MAXE], cap[2*MAXE], prev_edge[2*MAXE], to[2*MAXE];


inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(last_edge);
}



inline void add_edge(int u, int v, int c, int bi = 1) { //bi = 0 for unidirected or directed
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
        for (int i = 1; i <= nNode; i++) pro[i] = last_edge[i];
        while (true) {
            df = dfs(src, INF);
            if (df) ret += (ll)df;
            else break;
        }
    }
    return ret;
}
int main ()
{
  //  freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, m, p, q, n;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        init(2*n+1, 2*n+2, 2*n+2);

        for (i = 1; i <= n; i++)
        {
            sl(x);

            add_edge(i, n+i, x);
         //   cout << i << " add " << n+i << " " << x << " " << nEdge << endl;
        }


        sl(m);

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            add_edge(x+n, y, z, 0);
         //   cout << x+n << " add " << y << " " << z << " " << nEdge << endl;

        }

        sl(p);
        sl(q);

        for (i = 1; i <= p; i++)
        {
            sl(x);
            add_edge(2*n+1, x, INF);
      //      cout << 2*n+1 << " add " << x << " " << INF << " " << nEdge << endl;

        }

        for (i = 1; i <= q; i++)
        {
            sl(x);
            add_edge(x+n, 2*n+2, INF);
   //         cout << x+n << " add " << 2*n+2 << " " << INF << " " << nEdge << endl;

        }



        printf("Case %lld: %lld\n", cs, dinitz());
    }

    return 0;
}
