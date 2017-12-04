#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf(" %s", n);

ll c, arr[55], avail;

struct node
{
    int endm;
    int p[55];

    node()
    {
        endm = 0;
        for (ll i = 0; i < 55; i++)
            p[i] = 0;
    }
} trie[100010];

void ins(char *s)
{
    ll n, i;
    int cur = 0;
    for (i = 0; s[i] != 0; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            n = s[i] - 'a';
        else n = s[i] - 'A' + 26;

//        cout << i << " " << (char) (n + 'a') << " " << avail << " " << cur.p[n] << endl;

        if (trie[cur].p[n] == 0)
        {
            trie[cur].p[n] = avail;
  //      cout << i << " " << (char) (n + 'a') << " " << avail << " " << cur.p[n] << " " << n << endl;

            avail++;
        }

        //    cout << i << " " << s[i] << " " << cur << " " << cur.p[n] << endl;

        cur = trie[cur].p[n];

    }

    trie[cur].endm++;

    //    cout << cur << " " << cur.endm << endl;
}

void srch(char *s, ll i, int cur, ll len, ll *ar)
{
    ll n;

    if ('a' <= s[i] && s[i] <= 'z')
        n = s[i] - 'a';
    else n = s[i] - 'A' + 26;


  //  cout << i << " " << s[i] << " " << s << endl;

//   for (ll j = 0; j < 5; j++)
//   cout << i << " " << s << " " << (char) (j + 'a') << " " << ar[j] << endl;


    if (s[i] == 0)
    {
        // cout << "1if " << i << " " << s[i] << " " << n << endl;

//           cout << i << " " << s << " " << cur.endm << endl;
        c += trie[cur].endm;
    }
    else if ( (i == 0 || i == len - 1) && trie[cur].p[n] != 0)
    {
    //         cout << "2if " << i << " " << s[i] << " " << endl;

        srch(s, i+1, trie[cur].p[n], len, ar);
    }
    else
    {
//              cout << "3if " << i << " " << s[i] << endl;

        for (ll j = 0; j < 52; j++)
        {
  //          cout << cur.p[j] << " " << ar[j] << endl;
            if (trie[cur].p[j] != 0 && ar[j] > 0)
            {
//    for (ll pk = 0; pk < 25; pk++)
                //      if (pk == 4 || pk == 7 || pk == 17 || pk == 19)
                //    cout << i << " " << s << " " << (char) (pk + 'a') << " " << ar[pk] << endl;

                //                  cout << "3if " << i << " " << (char) (j + 'a') << " " << ar[j] << endl;
                ar[j]--;
                srch(s, i+1, trie[cur].p[j], len, ar);
                ar[j]++;
            }
        }
    }

}

void reset(int cur)
{
    for(int i=0; i<52; i++)
        if(trie[cur].p[i])
        {
            reset(trie[cur].p[i]);
            trie[cur].p[i] = 0;
        }
    trie[cur].endm = 0;
}

int main ()
{
   //  freopen("inl.txt", "r", stdin);
    //  freopen("outl.txt", "w", stdout);
    char s[110], ln[100010];
    ll cs, t, i, j, k, n, x, y, ans, q, id, pk, pg;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        avail = 1;

        for (j = 0; j < 53; j++)
            arr[j] = 0;

        printf("Case %lld:\n", cs);

        sl(n);

        while(n--)
        {
            ss(s);
            ins(s);
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
                        c = 0;
                        s[k] = 0;

                        pg = strlen(s);
                        for (pk = 0; s[pk] != 0; pk++)
                        {
                            if ('a' <= s[pk] && s[pk] <= 'z')
                                id = s[pk] - 'a';
                            else id = s[pk] - 'A' + 26;

                            if (pk != 0 && pk != pg - 1)
                                arr[id]++;
                        }

                        srch(s, 0, 0, strlen(s), arr);
                        ans *= c;
                        //        cout << s << " " << c << " " << ans << endl;
                        for (j = 0; j < 53; j++)
                            arr[j] = 0;
                    }
                    k = 0;
                }
            }

            if (k != 0)
            {
                c = 0;
                s[k] = 0;

                //  cout << s << endl;

                pg = strlen(s);
                for (pk = 0; s[pk] != 0; pk++)
                {
                    if ('a' <= s[pk] && s[pk] <= 'z')
                        id = s[pk] - 'a';
                    else id = s[pk] - 'A' + 26;

                    if (pk != 0 && pk != pg - 1)
                        arr[id]++;
                }

                //   for (j = 0; j < 53; j++)
                //     cout << s << " " << (char) (j + 'a') << " " << arr[j] << endl;

                srch(s, 0, 0, strlen(s), arr);
                ans *= c;
                //         cout << s << " " << c << " " << ans << endl;
                for (j = 0; j < 53; j++)
                    arr[j] = 0;
            }

            printf("%lld\n", ans);
        }
        reset(0);
    }

    return 0;
}
