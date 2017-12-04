#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main ()
{
    ll cs, t, x;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
        cin >> x;

        for (ll i = 0; i <= 8; i++)
        {
            if ((x-i)%9 == 0)
            {
                if (i == 0)
                {
                    printf("Case %lld: %lld %lld\n", cs, (x+(x-9)/9), x+x/9);
                }
                else
                    printf("Case %lld: %lld\n", cs, (x+(x-i)/9));
            }
        }
    }


    return 0;
}
