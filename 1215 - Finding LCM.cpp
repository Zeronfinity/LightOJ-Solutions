#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool p[2000000];
int prime[900000];

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;
    return gcd(b, a%b);
}

int main ()
{
    ll cs, t, a, b, l, c, x, i, j, k = 1, sq, cl, cx, tl, tx;
    prime[0] = 2;
    for (i = 3; i <= 2000000; i += 2)
    {
        if (p[i] == 0)
        {
            prime[k++] = i;

            if (i <= 1500)
                for (j = i*i; j <= 2000000; j+=2*i)
                    p[j] = 1;
        }
    }

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        c = 1;
        cin >> a >> b >> l;

        tl = l;

        x = a*b/gcd(a, b);

        tx = x;

//        cout << x << endl;

        sq = sqrt(l);

        for (i = 0; prime[i] <= sq; i++)
        {
            cl = 0, cx = 0;

  //          cout << prime[i] << " " << l << " " << x << endl;

            if (l == 1)
                break;

            while (l%prime[i] == 0)
            {
                l /= prime[i];
                cl++;
            }

            if (cl > 0)
                while (x%prime[i] == 0)
                {
                    x /= prime[i];
                    cx++;
                }

//            cout << prime[i] << " " << cl << " " << cx << endl;

            if (cl > cx)
            {
                for (j = 1; j <= cl; j++)
                    c *= prime[i];
            }
        }
        if (l != 1)
        {
            if (x%l != 0)
            {
                c *= l;
            }
        }

        printf("Case %lld: ", cs);
        if (tl%tx != 0)
            printf("impossible\n");
        else printf("%lld\n", c);
    }


    return 0;
}
