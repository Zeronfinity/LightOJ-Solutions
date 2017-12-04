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
#define pb push_back

char gr[15][15];

deque <pll > dq;

ll mx, dirx[] = {1, -1, 0, 0}, diry[] = {0, 0, 1, -1}, lv[15][15], n;
bool flag;
ll BFS(ll srcx, ll srcy, ll alp)
{
  //  cout << "alp = " << alp << endl;
    if (alp > mx)
        return 0;

    dq.clear();
    for (ll i = 0; i < 13; i++)
        for (ll j = 0; j < 13; j++)
            lv[i][j] = -1;


    dq.pb(pll(srcx, srcy));
    lv[srcx][srcy] = 0;

    while(dq.empty() == false)
    {
        pll u = dq[0];
        dq.pop_front();

      //  cout << "Starting from " << u.first << " " << u.second << " " << gr[u.second][u.first] << endl;

        for (ll i = 0; i < 4; i++)
        {
            ll vx = u.first + dirx[i];
            ll vy = u.second + diry[i];

            if (0 <= vx && vx < n && 0 <= vy && vy < n)
            {
            //    cout << vx << " " << vy << " " << lv[vx][vy] << " " << gr[vy][vx] << endl;

                if (lv[vx][vy] == -1 && gr[vy][vx] != '#')
                {
                    lv[vx][vy] = lv[u.first][u.second] + 1;
                    if (gr[vy][vx] - 'A' == alp)
                    {
                        return lv[vx][vy] + BFS(vx, vy, alp + 1);
                    }
                    else if ('A' + alp <= gr[vy][vx] && gr[vy][vx] <= 'Z')
                        continue;

                 //   cout << vx << " " << vy << " " << gr[vy][vx] << " is being pushed\n";

                    dq.pb(pll(vx, vy));
                }
            }
        }
    }
    flag = 1;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outl.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, startx, starty;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        mx = 0;

        for (i = 0; i < n; i++)
        {
            ss(gr[i]);

            for (j = 0; j < n; j++)
            {
                if ('A' <= gr[i][j] && gr[i][j] <= 'Z')
                {
                    if (gr[i][j] - 'A' > mx)
                        mx = gr[i][j] - 'A';

                    if (gr[i][j] == 'A')
                    {
                    //    cout << j << " " << i << endl;
                        startx = j, starty = i;
                    }
                }
            }
        }

       // cout << startx << " " << starty << endl;

        flag = 0;
        ans = BFS(startx, starty, 1);

        if (flag == 0)
            printf("Case %lld: %lld\n", cs, ans);
        else printf("Case %lld: Impossible\n", cs);
    }

    return 0;
}
