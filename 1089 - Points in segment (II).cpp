#include <bits/stdc++.h>
using namespace std;
#define ll int

int s1[50005];
map <int, int> mp;

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, l, u, cn;

    cin >> t;
    for (cs = 1; cs <= t; cs++)
    {
        cin >> n >> q;
        cout << "Case " << cs << ":\n";
        i = 0;
        while(n--)
        {
            scanf("%d %d", &x, &y);
            s1[i] = x;
            mp[i++] = y;
        }

        sort(s1, s1 + i);

        while(q--)
        {
            cn = 0;
            scanf("%lld", &x);

            u = (upper_bound(s1, s1 + i, x) - s1) - 1;

            for (j = 0; j <= u; j++)
            {
         //       cout << s1[j] << " " << mp[j] << endl;
                if (mp[j] >= x)
                    cn++;
            }

            printf("%d\n", cn);
        }
        mp.clear();
     }

    return 0;
}

