#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool p[100000];
int prime[90000];

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;
    return gcd(b, a&b);
}

int main ()
{
    ll cs, t, i, j, k = 0, n, ans = 0, sq, c, f = 0;
    prime[k++] = 2;
    for (i = 3; i <= 90000; i+=2)
    {
        if (p[i] == 0)
        {
            prime[k++] = i;
            if (i <= 300)
            for (j = i*i; j <= 90000; j+=2*i)
            {
                p[j] = 1;
            }
        }
    }

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        ans = 0;
        f = 0;

        cin >> n;

        if (n < 0)
        {
            n *= -1;
            f = 1;
        }

        sq = sqrt((double) n);

        for (i = 0; ; i++)
        {
           // cout << prime[i] << " " << ans << endl;

            if (prime[i] > sq)
                break;

            c = 0;
            while (n%prime[i] == 0)
            {
                n /= prime[i];
                c++;
            }
          //  cout << prime[i] << " " << ans << " " << c << endl;

            while(f == 1 && c%2 == 0 && c != 0)
            {
                c /= 2;
            }

            if (c > 0)
            if (ans == 0)
                ans = c;
            else ans = gcd(ans, c);
          //  cout << prime[i] << " " << ans << endl;
        }
        if (n != 1)
            ans = 1;
        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
