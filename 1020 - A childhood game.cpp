#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n); getchar();

int al[3000000];
int bo[3000000];

int alice(ll n)
{
    if (n == 1)
        return -1;

    if (al[n] == 0)
    {
        if (alice(n-1) == -1 || alice(n-2) == -1)
        {
            al[n] = 1;
        }
    }
    al[n] = -1;
    return al[n];
}

int bob(ll n)
{
    if (n == 1)
        return -1;

    if (bo[n] == 0)
    {
        if (bob(n-1) == -1 || bob(n-2) == -1)
        {
            bo[n] = 1;
        }
    }
    bo[n] = -1;
    return bo[n];
}

int main ()
{
    freopen("outl.txt", "w", stdout);
    ll cs, t, i, j, k, n, x, y, ans, q;

    string s;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        cin >> n >> s;

        printf("Case %lld: ", cs);

        if (s == "Alice")
        {
            if (alice(n) == 1)
                cout << "Alice" << endl;
            else cout << "Bob" << endl;
        }
        else
        {
            if (bob(n) == 1)
                cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }

    return 0;
}
