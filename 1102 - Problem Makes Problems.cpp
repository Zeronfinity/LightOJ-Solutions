#include <bits/stdc++.h>
using namespace std;
long long m = 1000000007;
unsigned long long fact[3000000];
long long pwr(long long b, long long p)
{
    long long ans, x;

    if (p == 0)
        return 1;

    x = (pwr(b, p/2))%m;
    if (p%2 == 0)
        ans = (x*x)%m;
    else ans = ((x*x)%m*b%m)%m;

//   cout << p << " " << ans << endl;

    return ans%m;
}

int main()
{
    long long t, i, n, k, ans, j, fa;
    fact[1] = 1;
    for (i = 2; i <= 2000010; i++)
    {
        fact[i] = (i*fact[i-1])%m;
    }

    cin >> t;

    for (i=1; i<=t; i++)
    {
        cin >> n >> k;
        k--;
        if (k != 0 && n != 0)
        {
            fa = (fact[n]*fact[k])%m;
            ans = (fact[n+k]%m*(pwr(fa, m-2))%m)%m;
        }
        else ans = 1;
        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
