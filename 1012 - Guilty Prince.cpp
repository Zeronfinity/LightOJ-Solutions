#include <stdio.h>
#include <iostream>
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
#define pll pair <long long, long long>

char grid[25][25];
bool vis[25][25];

ll dirx[] = {1, -1, 0, 0}, w, h;
ll diry[] = {0, 0, 1, -1};

void DFS(ll x, ll y)
{
   // cout << "a " << x << " " << y << endl;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dirx[i];
        ll ny = y + diry[i];

    //    cout << "b " << nx << " " << ny << endl;

        if (0 <= nx && nx < w && 0 <= ny && ny < h)
        {
            if (vis[nx][ny] == 0 && grid[nx][ny] == '.')
            {
                vis[nx][ny] = 1;
                DFS(nx, ny);
            }
        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, rx, ry;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(w);
        sl(h);

        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
            {
                vis[j][i] = 0;
                scanf(" %c", &grid[j][i]);
                if(grid[j][i] == '@')
                {
                    rx = j;
                    ry = i;
                }
            }

        vis[rx][ry] = 1;


        DFS(rx, ry);

        ans = 0;

        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
            {
                if (vis[j][i] == 1)
                    ans++;
            }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
