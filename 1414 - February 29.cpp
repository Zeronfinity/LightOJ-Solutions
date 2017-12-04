#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main ()
{
 //   freopen("inl.txt", "r", stdin);
  //  freopen("outl.txt", "w", stdout);

    ll ans, t, x, cs, d, y1, y2;
    string s;

    cin >> t;

    for (cs = 1; cs <= t; cs++)
    {
 //       cout << endl << cs << ":" << endl;
        getchar();
        cin >> s;
        scanf("%lld, %lld", &d, &y1);

   //     cout << s << " " << d << " " << y1 << endl;

        if (y1%4 == 0)
        {
            if (s == "January" || s == "February")
            {

            }
            else
            {
                if (s == "February" && d == 29)
                {

                }
                else y1+=4;
            }

//            cout << "y1 " << y1 << endl;
        }
        else
        {
            y1 = (long long) ceil((double) y1/4)*4;
        }

        getchar();
        cin >> s;
        scanf("%lld, %lld", &d, &y2);

     //   cout << s << " " << d << " " << y2 << endl;


        if (y2%4 == 0)
        {
            if (s == "January" || s == "February")
            {
                if (s == "February" && d == 29)
                {

                }
                else y2 -= 4;
            }
        }
        else
        {
            y2 = (y2/4)*4;
        }

        if (y2 >= y1)
            ans = (y2-y1)/4 + 1;
        else ans = 0;

       // cout << ans << endl;

       // cout << y2 << " " << y1 << endl;

        x = (((y2/100)*100 - ( (long long) ceil((double) y1/100)*100) )/100 + 1);

//        cout << "ans x " << ans << " " << x << endl;

        if (x > 0)
            ans -= x;

  //      cout << x << " " << ans << endl;

  //      cout << y2 << " " << y1 << " " << ans << endl;

//        cout <<  ceil( (double) y1/400) << endl;

        x = ( ( ((y2/400)*400) - (((long long) ceil((double) y1/400))*400) )/400 + 1);

    //    cout << "x = " << x << endl;

        if (x > 0)
            ans += x;

      //  cout << x << " " << ans << endl;

        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}

