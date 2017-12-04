#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

bool flag;
ll s2, t2, s1, t1, x, y;

ll egcd(ll a, ll b)
{
    ll temp;

    if (a%b == 0)
    {
        x = s1;
        y = t1;
    //    cout << a << " " << b << " " << x << " " << y << " " << s1 << " " << t1 << endl;
        return b;
    }

    temp = s2 - (a/b)*s1;
    s2 = s1;
    s1 = temp;

    temp = t2 - (a/b)*t1;
    t2 = t1;
    t1 = temp;

    return egcd(b, (a%b + b)%b);
}

int main ()
{
    freopen("inl.txt", "r", stdin);
    freopen("outl.txt", "w", stdout);
    ll cs, t, i, j, k, n, ans, q, a, b, c, x1, x2, y1, y2, g, k1, k2, ux, lx, uy, ly, fa, fb, tm1, tm2;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(a);
        sl(b);
        sl(c);
        sl(x1);
        sl(x2);
        sl(y1);
        sl(y2);

        s2 = t1 = 1;
        s1 = t2 = 0;

        flag = 0;

        if (a == 0 || b == 0)
        {
            if (b != 0)
            {
                if (c%b != 0)
                    ans = 0;
                else
                {
                    k = -c/b;
                    if (y1 <= k && k <= y2)
                        ans = (x2 - x1 + 1);
                    else ans = 0;
                }
                printf("Case %lld: %lld\n", cs, ans);
                continue;
            }
            else if (a != 0)
            {
                if (c%a != 0)
                    ans = 0;
                else
                {
                    k = -c/a;
                    if (x1 <= k && k <= x2)
                        ans = (y2 - y1 + 1);
                    else ans = 0;
                }
                printf("Case %lld: %lld\n", cs, ans);
                continue;
            }
            else
            {
                if (c == 0)
                    ans = (x2 - x1 + 1)*(y2 - y1 + 1);
                else
                    ans = 0;
                printf("Case %lld: %lld\n", cs, ans);
                continue;
            }
        }
        if (a >= 0)
            fa = 1;
        else fa = 0;

        if (b >= 0)
            fb = 1;
        else fb = 0;

        if (fa == 0)
            a *= -1;

        if (fb == 0)
            b *= -1;

        g = egcd(a, b);

        k1 = b/g;
        k2 = a/g;

        if (fa == 0)
        {
            a *= -1;
            x *= -1;
        }

        if (fb == 0)
        {
            b *= -1;
            y *= -1;
        }

        if (c%g != 0)
            flag = 1;

        x *= (-c)/g;
        y *= (-c)/g;

        k1 = b/g;
        k2 = a/g;

    //    cout << x << " " << y << " " << g << " " << k1 << " " << k2 << endl;

        fa = 0;

        if (k1 < 0)
        {
            k1 *= -1;
            fa = 1;
        }

        tm1 = (x%k1 + k1)%k1;

        k = (x2 - tm1)/k1;

        if (x2 - tm1 < 0 && (x2 - tm1)%k1 != 0)
            k--;

    //    cout << k << " " << k1 << " " << tm1 << endl;

        ux = k*k1 + tm1;

        if (fa == 1)
            k1 *= -1;


        fa = 0;

        if (k2 < 0)
        {
            k2 *= -1;
            fa = 1;
        }

        tm1 = (y%k2 + k2)%k2;

        k = (y2 - tm1)/k2;

       // cout << y2 << " " << tm1 << " k " << k << endl;

        if (y2 - tm1 < 0 && (y2 - tm1)%k2 != 0)
            k--;

//        cout << k << endl;

        uy = k*k2 + tm1;

        if (fa == 1)
            k2 *= -1;



        fa = 0;

        if (k1 < 0)
        {
            k1 *= -1;
            fa = 1;
        }

        tm1 = (x%k1 + k1)%k1;

        k = (x1 - tm1)/k1;

        if (x1 - tm1 > 0 && (x1 - tm1)%k1 != 0)
            k++;

        lx = k*k1 + tm1;

        if (fa == 1)
            k1 *= -1;


      //  cout << "lx " << lx << " " << k << " " << k1 << " " << tm1 << endl;

        fa = 0;

        if (k2 < 0)
        {
            k2 *= -1;
            fa = 1;
        }

        tm1 = (y%k2 + k2)%k2;

        k = (y1 - tm1)/k2;

        if (y1 - tm1 > 0 && (y1 - tm1)%k2 != 0)
            k++;

        ly = k*k2 + tm1;

        if (fa == 1)
            k2 *= -1;

    //    cout << k1 << " " << k2 << endl;

        if (k1*k2 < 0)
            swap(uy, ly);

      //  cout << ux << " " << lx << " " << uy << " " << ly << " " << (-c-b*ly)/a << " " << (-c-b*uy)/a << endl;

        ux = min(ux, (-c-b*ly)/a);
        lx = max(lx, (-c-b*uy)/a);

        if (k1 < 0)
            k1 *= -1;

        if (flag == 1)
            ans = 0;
        else ans = (ux - lx)/k1 + 1;

       // cout << ux << " " << lx << " " << k1 << " " << ans << endl;

        if (ans < 0)
            ans = 0;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
