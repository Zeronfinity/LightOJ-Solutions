#include <bits/stdc++.h>
using namespace std;

#define m 1000003

int main ()
{
  //  freopen("in.txt", "r", stdin);
    unsigned long long i, j, t, n, k;

    unsigned long long ans;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cin >> n >> k;

        ans = 1;

        for (j = 1; j <= k; j++)
        {
            if (n == 0)
            {
                ans = 0;
                break;
            }
            ans = (ans*n*n)/j;
            n--;
        }

        printf("Case %lld: %llu\n", i, ans);
    }

    return 0;
}
