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

char grid[2010][2010];

ll last[2010];
ll a[2010];

#define tsz 2110

ll tree[10*tsz];

void create(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = b;
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

    if (a[tree[left]] <= a[tree[right]])
        tree[node] = tree[left];
    else tree[node] = tree[right];
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
        return tree[node];

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

    if (a[p1] <= a[p2])
        return p1;
    else return p2;
}

ll solve(ll i, ll j, ll n)
{
    if (i > n || j < 1 || j < i)
        return 0;

    ll mn = query(1, 1, n, i, j);

    if (i == j)
    {
        return (j-i+1)*a[mn];
    }

    return max(a[mn]*(j-i+1), max(solve(i, mn-1, n), solve(mn+1, j, n)));

}

int main ()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    a[0] = LLONG_MAX;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (j = 1; j <= m; j++)
            last[j] = 0;

        ans = 0;

        for (i = 1; i <= n; i++)
        {
            ss(grid[i] + 1);

            for (j = 1; j <= m; j++)
            {
                if (grid[i][j] == '1')
                    last[j] = i;

                a[j] = i - last[j];
            }
            create(1, 1, m);

            ans = max(ans, solve(1, m, m));
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
