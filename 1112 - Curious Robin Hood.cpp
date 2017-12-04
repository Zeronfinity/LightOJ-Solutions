#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll arr[100010], tree[300010];

void create(ll node, ll b, ll e)
{
	if (b == e)
	{
		tree[node] = arr[b];
		return ;
	}

	ll left = 2*node + 1;
	ll right = 2*node + 2;

	ll mid = (b+e)/2;

//	cout << node << " " << b << " " << e << " " << tree[node] << " " << left << " "	<< right << endl;


	create(left, b, mid);
	create(right, mid+1, e);


	tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll b, ll e, ll sb, ll se)
{
	if (sb > e || se < b)
		return 0;

	if (b >= sb && e <= se)
		return tree[node];

	ll left = 2*node + 1;
	ll right = 2*node + 2;
	ll mid = (b+e)/2;

	return ( query(left, b, mid, sb, se) + query(right, mid+1, e, sb, se) );
}

void add(ll node, ll b, ll e, ll y, ll z)
{
	if (y > e || y < b)
		return ;

	if (b >= y && e <= y)
	{
		tree[node] += z;
		return ;
	}

	ll left = 2*node + 1;
	ll right = 2*node + 2;
	ll mid = (b+e)/2;

	add(left, b, mid, y, z);
	add(right, mid+1, e, y, z);

	tree[node] = tree[left] + tree[right];
}

void zero(ll node, ll b, ll e, ll y)
{
//	cout << node << " " << b << " " << e << " " << tree[node] << " " << left << " "	<< right << endl;


	if (y > e || y < b)
		return ;

	if (b >= y && e <= y)
	{
		printf("%lld\n", tree[node]);
		tree[node] = 0;
		return ;
	}
	ll left = 2*node + 1;
	ll right = 2*node + 2;
	ll mid = (b+e)/2;
	//cout << node << " " << b << " " << e << " " << tree[node] << " " << left << " "	<< right << endl;
	zero(left, b, mid, y);
	zero(right, mid+1, e, y);

	tree[node] = tree[left] + tree[right];
}

int main()
{
	ll t, cs, i, j, k, n, q, x, y, z;

	cin >> t;

	for (cs = 1; cs <= t; cs++)
	{
		printf("Case %lld:\n", cs);

		scanf("%lld %lld", &n, &q);

		for (i = 0; i < n; i++)
			scanf("%lld", &arr[i]);

		create(0, 0, n-1);

//		cout << "t";

		for (i = 1; i <= q; i++)
		{
			scanf("%lld", &x);

	//	cout << "t";

			if (x == 1)
			{
				scanf("%lld", &y);
				zero(0, 0, n-1, y);
			}
			else if (x == 2)
			{
				scanf("%lld %lld", &y, &z);
				add(0, 0, n-1, y, z);
			}
			else
			{
				scanf("%lld %lld", &y, &z);

				printf("%lld\n", query(0, 0, n-1, y, z));
			}
		}
	}

	return 0;
}
