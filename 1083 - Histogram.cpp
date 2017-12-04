#include <bits/stdc++.h>
using namespace std;

long long arr[30011], tree[90010], mx, n;

void create (long long node, long long b, long long e)
{
    if (b == e)
    {
        tree[node] = b;
    }
    else
    {
        long long left = 2*node;
        long long right = 2*node + 1;
        long long mid = (b+e)/2;

        create(left, b, mid);
        create(right, mid + 1, e);

        if (arr[tree[left]] <= arr[tree[right]])
            tree[node] = tree[left];
        else tree[node] = tree[right];
    }
}

long long query (long long node, long long b, long long e, long long i, long long j)
{

    if (b > j || e < i)
    {
        return 30010;
    }

    if (i <= b && e <= j)
    {
        return tree[node];
    }

    long long left = 2*node;
    long long right = 2*node + 1;
    long long mid = (b+e)/2, x, y;

    if(arr[x = query(left, b, mid, i, j)] <= arr[y = query(right, mid + 1, e, i, j)])
        return x;
    else return y;
}

long long solve(long long i, long long j)
{
    if (i > n || j < 1 || j < i)
        return 0;

    long long mn = query(1, 1, n, i, j);

    if (i == j)
    {
        return (j-i+1)*arr[mn];
    }

    return max(arr[mn]*(j-i+1), max(solve(i, mn-1), solve(mn+1, j)));

}

int main ()
{
    long long cs, i, t;

  //  freopen("inl.txt", "r", stdin);

    arr[30010] = 35000;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        cin >> n;

        for (i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        create(1, 1, n);

        mx = solve(1, n);

        printf("Case %lld: %lld\n", cs, mx);
    }

    return 0;
}
