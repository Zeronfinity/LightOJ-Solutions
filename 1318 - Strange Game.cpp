#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n); getchar();


int pf[100005][10], f[100005][10], in[100005], res[100005];
bool p[100005];

ll pwr(ll b, ll p, ll m)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2, m);

    x = (x*x)%m;

    if (p%2 == 0)
        return x;
    else return (b%m*x)%m;
}

ll ncr(ll n, ll r, ll m)
{
    ll ans = 1, j, temp, i, sq, cn, k;

    for (i = 2; i <= 100004; i+=2)
    {
        res[i] = 0;
        if (i == 2)
            i = 1;
    }

    if (r > n-r)
        return ncr(n, n-r, m);

    //cout << n << " " << r << " " << n-r << endl;

    for (i = n; i > n-r; i--)
    {
        for (j = 0; j < in[i]; j++)
            res[pf[i][j]] += f[i][j];
    }

    for (i = 1; i <= r; i++)
    {
        for (j = 0; j < in[i]; j++)
            res[pf[i][j]] -= f[i][j];
    }

    for (i = 2; i <= 100004; i+=2)
    {
//        if (i < 30)
  //          cout << i << " " << res[i] << " " << ans << endl;
        ans = (ans*pwr(i, res[i], m))%m;
        if (i == 2)
            i = 1;
    }

    return ans;
}

int main ()
{
    ll cs, t, i, j, k = 0, n, x, y, ans, q, a, b, c, d, l, m, gaba, cn, temp;


    for (i = 2; i <= 100004; i += 2)
    {
        if (p[i] == 0)
        {
            for (j = i; j <= 100004; j += i)
            {
                cn = 0;

                temp = j;

                while(temp%i == 0)
                {
                    temp /= i;
                    cn++;
                }

                p[j] = 1;
                pf[j][in[j]] = i;
                f[j][in[j]++] = cn;
            }
        }
        if (i == 2)
            i = 1;
    }

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);
        sl(l);
        sl(m);

        a = (k*(k-1))/2;

        b = pwr(k, l-1, n);

        c = ncr(l, m, n);

        d = pwr(k-1, m-1, n);

      //  cout << a << " " << b << " " << c << " " << d << endl;

        if (m != 0)
            ans = ( ( (a%n * b)%n * c )%n * d)%n;
        else ans = pwr(k, l, n);


        printf("Case %lld: %lld\n", cs, ans + 1);
    }

    return 0;
}
