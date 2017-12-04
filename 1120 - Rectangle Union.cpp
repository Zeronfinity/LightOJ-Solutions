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

struct data
{
    ll x;
    ll y1, y2;
    bool type;

    data() {}
    data(ll _x, ll _y1, ll _y2, bool _type)
    {
        x = _x, y1 = _y1, y2 = _y2, type = _type;
    }

} points[60010];

bool comp(data l, data r)
{
    if (l.x == r.x)
        return l.type < r.type;
    else return l.x < r.x;
}

set <ll> st;

map <ll, ll> mp;
ll rmp[60010];

#define tsz 60011

struct tnode
{
    ll sum, freq;
} tree[tsz*5];

void create(ll node, ll b, ll e)
{
    tree[node].sum = 0;
    tree[node].freq = 0;

    if (b == e) {
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);
}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if (i > j)
        return ;

    if (e < i || j < b)
        return;

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    if (i <= b && e <= j) {
        tree[node].freq += val;

   //     cout << node << " updating " << b << " " << e << " " << rmp[b] << " " << rmp[e] << endl;

        if (tree[node].freq != 0)
        {
            tree[node].sum = rmp[e] - rmp[b-1];
        }
        else
        {
            if (b == e)
                tree[node].sum = 0;
            else
            {
                tree[node].sum = tree[left].sum + tree[right].sum;
            }
        }

        return;
    }

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    if (tree[node].freq == 0)
        tree[node].sum = tree[left].sum + tree[right].sum;
    else
        tree[node].sum = rmp[e] - rmp[b-1];
}



int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, x1, y1, x2, y2;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        st.clear();
        mp.clear();

        for (i = 0; i < n; i++)
        {
            sl(x1);
            sl(y1);
            sl(x2);
            sl(y2);

            st.insert(y1);
            st.insert(y2);

            points[2*i] = data(x1, y1, y2, 0);
            points[2*i + 1] = data(x2, y1, y2, 1);
         //   cout << points[0].x << " " << points[0].y1 << " " << points[0].y2 << endl;
           // cout << points[1].x << " " << points[1].y1 << " " << points[1].y2 << endl;
        }

        sort(points, points + 2*n, comp);

        z = 0;

        for (set<ll> :: iterator sit = st.begin(); sit != st.end(); sit++)
        {
            mp[*sit] = ++z;
            rmp[z] = *sit;
        //    cout << z << " " << *sit << endl;
        }

        ans = 0;

        create(1, 1, z);

      //  cout << z << " " << points[0].y1 << " " << points[0].y2 << " " << mp[points[0].y1] << " " << mp[points[0].y2] << endl;

        update(1, 1, z, mp[points[0].y1] + 1, mp[points[0].y2], 1);

        for (i = 1; i < 2*n; i++)
        {
            ans += (points[i].x - points[i-1].x)*tree[1].sum;

         //   cout << i << " " << points[i-1].x << " " << points[i].x << " " << ans << endl;

            if (points[i].type == 0)
            {
                update(1, 1, z, mp[points[i].y1] + 1, mp[points[i].y2], 1);
            }
            else
            {
                update(1, 1, z, mp[points[i].y1] + 1, mp[points[i].y2], -1);
            }
        }

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
