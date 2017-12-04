#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long t, f[22], ans, j, mark[21][21], k, s, n, m;
    deque <int> q;
    bool nm;
    cin >> t;

    for (long long i = 1; i <= t; i++)
    {
        cin >> n >> m;
        ans = 0;
        nm = false;
        for (j = 1; j <= m; j++)
            f[j] = 0;

        for (j = 1; j <= n; j++)
            q.push_back(j);


        for (j = 1; j <= m; j++)
            for (k = 1; k <= n; k++)
                mark[j][k] = 0;
        while(nm == false)
        {
            nm = true;
            for (j = 1; j < m; j++)
            {
                s = q.size();

                for (k = 0; k < s && mark[j][q[k]] != 0; k++) {}

                if (k != s)
                {
                    mark[j][q[k]] = 1;
                    if (f[j] == 0)
                    {
                        f[j] = q[k];
                        q.erase(q.begin()+k);
                    }
                    else
                    {
                        q.push_back(f[j]);
                        f[j] = q[k];
                    }
                    nm = false;
                }
                ans += 5;
                cout << "hi " << j << " " << k << " " << ans << endl;
            }
        }
        cout << "Case " << i << ": " << ans << endl;
        q.clear();
    }

    return 0;
}
