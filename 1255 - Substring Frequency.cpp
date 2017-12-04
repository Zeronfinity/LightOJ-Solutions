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

char s[2000000], p[2000000];
ll pre[2000000];

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, plen, slen, c;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        scanf("%s", s);
        scanf("%s", p);

        c = 0;

        plen = strlen(p);
        slen = strlen(s);


        k = 0;
        pre[0] = 0;
        for (i = 1; i < plen; i++)
        {
            while (k > 0 && p[k] != p[i])
            {
                k = pre[k-1];
            }

            if (p[k] == p[i])
            {
                k++;
            }

            pre[i] = k;
        }

  //      for (i = 0; i < plen; i++)
    //        cout << i << " " << p[i] << " " << pre[i] << endl;

      //  cout << endl;

        j = 0;

        for (i = 0; i < slen; i++)
        {
            while (j > 0 && s[i] != p[j])
                j = pre[j-1];

            if (s[i] == p[j])
                j++;

            if (j == plen)
            {
                c++;
                j = pre[j-1];
            }
        }


        printf("Case %lld: %lld\n", cs, c);
    }

    return 0;
}
