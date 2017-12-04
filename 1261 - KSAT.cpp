#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long i, t, n, m, p, no, flag, k, j, l, a[35][35], b[35], f;

    cin >> t;

    for (i = 1; i<=t; i++)
    {
        flag = 1;
        cin >> n >> m >> k;

        for (j = 0; j < n; j++)
        {
            a[j][k] = 0;
            for (l = 0; l < k; l++)
            {
                cin >> a[j][l];
            }
        }
        cin >> p;
        for (j = 0; j < p; j++)
        {
            cin >> b[j];
        }
        for (j = 0; j < n; j++)
            for (l = 0; l < k; l++)
            {
                f = 0;
                for (no = 0; no < p; no++)
                {
                    if (a[j][l] > 0 && a[j][l] == b[no])
                        a[j][k] = 1;
                    if (a[j][l] < 0 && a[j][l]*(-1) == b[no])
                        f = 1;
                }
                if (a[j][l] < 0 && f == 0)
                    a[j][k] = 1;
            }

        printf("Case %lld: ", i);

        for (j = 0; j < n; j++)
        {
            if (a[j][k] == 0)
            {
                flag = 0;
            }
        }

        if (flag == 1)
            printf("Yes\n");
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
