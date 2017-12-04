#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf(" %s", n);

map <string, ll> mp;

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    //  freopen("outl.txt", "w", stdout);
    char s[110], ln[100010];
    ll cs, t, i, j, k, n, x, y, ans, q, id, pk, pg;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        printf("Case %lld:\n", cs);

        sl(n);

        while(n--)
        {
            ss(s);
            string str(s);
            if (str.size() > 2)
                sort(str.begin() + 1, str.end() - 1);
            mp[str]++;
        }

        sl(n);
        getchar();
        while(n--)
        {
            ans = 1;
            ln[0] = 0;
            scanf("%[^\n]s", ln);
            getchar();
            //  printf("line %s\n", ln);
            if (ln[0] == 0)
            {
                printf("1\n");
                continue;
            }

            k = 0;

            for (i = 0; ln[i] != 0; i++)
            {
                if ( ('a' <= ln[i] && ln[i] <= 'z') || ('A' <= ln[i] && ln[i] <= 'Z') )
                {
                    s[k++] = ln[i];

                    //         cout << "test " << i << " " << ln[i] << endl;
                }
                else
                {
                    if (k != 0)
                    {
                        s[k] = 0;
                        string str(s);
                        if (str.size() > 2)
                            sort(str.begin() + 1, str.end() - 1);
                        ans *= mp[str];
//                        cout << str << " "<< mp[str] << " " << ans << endl;
                    }
                    k = 0;
                }
            }

            if (k != 0)
            {
                s[k] = 0;
                string str(s);
                if (str.size() > 2)
                    sort(str.begin() + 1, str.end() - 1);
                ans *= mp[str];
  //              cout << str << " "<< mp[str] << " " << ans << endl;

            }

            printf("%lld\n", ans);
        }
        mp.clear();
    }

    return 0;
}
