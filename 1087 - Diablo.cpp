#include <bits/stdc++.h>
using namespace std;
#define ll long long

deque <int> dq;

int main ()
{
    char ch;
    ll cs, t, i, j, k, n, x, y, ans, q;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ":" << endl;
        cin >> n >> q;
        while(n--)
        {
            scanf("%lld", &x);
            dq.push_back(x);
        }
        while(q--)
        {
            scanf(" %c %lld", &ch, &x);
            if (ch == 'c')
            {
                if (x > dq.size())
                    printf("none\n");
                else
                {
                    printf("%d\n", dq[x-1]);
                    dq.erase(dq.begin() + x - 1);
                }
            }
            else
            {
                dq.push_back(x);
            }
        }
        dq.clear();
    }

    return 0;
}
