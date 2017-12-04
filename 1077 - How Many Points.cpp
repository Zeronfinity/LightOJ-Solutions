#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b)
{
    if (a%b == 0)
        return b;
    return gcd(b, a%b);
}


int main ()
{
    //freopen("inl.txt", "r", stdin);
  //  freopen("outl.txt", "w", stdout);
    long long x1, y1, x2, y2, i, t, c, ans, l, u, m, n;
    double temp;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cin >>  x1 >> y1 >> x2 >> y2;


        if (x1 != x2)
        {
            m = y1-y2;
            n = x1-x2;

            if (m < 0)
                m *= -1;
            if (n < 0)
                n *= -1;

            c = (x1-x2)/gcd(m, n);

            cout << m << " " << n << " " << gcd(m, n) << " " << c << endl;

            if (c < 0)
                c *= -1;

            m = (x1+c)%c;

            cout << "m = " << m << endl;

            l = min(x1, x2);
            u = max(x1, x2);

            if (l >= 0)
            {
                temp = (l-m)/c;
                l = c*floor(temp) + m;
            }
            else
            {
                cout << "l = " << l << endl;
                l = -1*l;
                temp = ((double) l- (double) m)/((double) c);
                l = c*ceil(temp) + m;
                l = -1*l;
                cout << "l = " << l << ", temp = " << temp << endl;
            }

            if (u >= 0)
            {
                temp = (u-m)/c;
                u = c*floor(temp) + m;
            }
            else
            {
                u = -1*u;
                temp = ((double) u - (double) m)/((double) c);
                u = c*ceil(temp) + m;
                u = -1*u;
            }
            ans = fabs((u-l)/c) + 1;

            cout << l << " " << u << endl;
        }
        else
        {
            l = min(y1, y2);
            u = max(y1, y2);
            ans = u - l + 1;
        }
   //     if (i == 68 || i == 69)
     //       cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
