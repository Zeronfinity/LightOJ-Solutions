#include <bits/stdc++.h>
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

struct edd
{
    ll u, v, w;
}ed[30010];

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

        sz = 0;

        for (i = 1; i <= n; i++)
        {
            ed[sz].u = i;
            ed[sz].v = i+n+1;
            ed[sz++].w = -1;
        }

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            if (x > y)
                swap(x, y);

            ed[sz].u = x==0?0:x + n + 1;
            ed[sz].v = y;
            ed[sz++].w = z;
        }

        sl(k);

        ll b = 0, e = INT_MAX, mid;

        ans = 0;

        while(b<=e)
        {
            mid = (b+e)/2;

            init(0, n+1, 2*n+1);

            for (i = 0; i < sz; i++)
            {
           //     cout << i << " damn " << ed[i].w << endl;
                if (ed[i].w == -1)
                {
                    add_edge(ed[i].u, ed[i].v, 1);
              //      cout << i << " " << ed[i].u << " " << ed[i].v << endl;
                }
                else if (ed[i].w <= mid)
                {
             //       cout << i << " " << ed[i].u << " " << ed[i].v << endl;
                    add_edge(ed[i].u, ed[i].v, 1);
                }
            }

            ll x = dinitz();

        //    cout << b << " " << e << " " << mid << " " << k << " " << x << endl;

            if (x >= k)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                b = mid + 1;
            }

        //   return 0;
        }

        if (ans != 0)
            printf("Case %lld: %lld\n", cs, ans);
        else printf("Case %lld: no solution\n", cs);

    }

    return 0;
}
