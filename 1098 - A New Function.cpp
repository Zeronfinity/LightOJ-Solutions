#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long n, i, j, t, x, c = 0, temp, k, sq, u, l;

    long long ans;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        scanf("%lld", &n);

        ans = 0;

        sq = sqrt(n);

        for (j = 2; j <= sq; j++)
        {
            l = j*j;
            u = (n/j)*j;
            ans += ((u-l)/j + 1)*j;

        //    cout << ans << endl;

            l = j;
            u = u/j;

            ans += (u*(u+1))/2 - (l*(l+1))/2;

          //  cout << ans << endl;
        }


        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
