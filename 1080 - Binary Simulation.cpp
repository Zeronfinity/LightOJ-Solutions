#include <bits/stdc++.h>
using namespace std;

#define ll long long

string arr;

struct info
{
    ll inv;
    ll value;
} tree[500005];

void create(ll node, ll b, ll e)
{
    tree[node].inv = 0;
    if (b == e)
    {
        tree[node].value = arr[b-1] - '0';
        return ;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    create(left, b, mid);
    create(right, mid+1, e);
}

void update(ll node, ll b, ll e, ll i, ll j)
{
    if (b > j || e < i)
        return ;
  //  cout << "before if " << i << " " << b << " " << e << " " << j << endl;
    if (i <= b && e <= j)
    {
    //    cout << "node " << node << endl;
        tree[node].inv++;
        return ;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
 //   cout << node << " " << b << " " << mid << " " << e << " " << left << " " << right << endl;
    if (node < 1 || node > 100)
        return ;
    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);
}

void query(ll node, ll b, ll e, ll i, ll carry = 0)
{
  //  cout << "before if " << node << " " << b << " " << e << " " << i << endl;


    if (b > i || e < i)
        return ;
    if (i <= b && e <= i)
    {
        carry += tree[node].inv;
        if (carry%2 == 1)
            printf("%lld\n", (tree[node].value+1)%2);
        else printf("%lld\n", tree[node].value);
        return ;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

//    cout << node << " " << b << " " << mid << " " << e << " " << left << " " << right << endl;

    query(left, b, mid, i, carry + tree[node].inv);
    query(right, mid+1, e, i, carry + tree[node].inv);
}

int main()
{
    freopen("inl.txt", "r", stdin);

    char g;
    ll cs, t, n, i, j, k, q, x, y;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ":\n";
        cin >> arr;

        n = arr.size();

        create(1, 1, n);

        cin >> q;

        for (i = 1; i <= q; i++)
        {
            scanf(" %c", &g);
            if (g == 'I')
            {
                scanf("%lld %lld", &x, &y);
                update(1, 1, n, x, y);
            }
            else
            {
                scanf("%lld", &x);
                query(1, 1, n, x);
            }
        }
    }

    return 0;
}
