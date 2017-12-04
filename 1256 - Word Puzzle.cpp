#include<bits/stdc++.h>
using namespace std;

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define LL long long
#define fr first
#define pb push_back
#define sc second
#define pls pair<long long,string>
#define inf 1000000000
#define POP 1ll<<40
#define SZ(a) (a.size())

#define nsize 26

vector <string> str[nsize];

vector <ll> ed[nsize];
vector <string> EulerTour;
ll indeg[nsize], outdeg[nsize];

void EulerDFS(ll u, string st = "")
{
    ll i,v;
    for(i = 0; i < ed[u].size(); i++)
    {
        v = ed[u][i];
        if(v != -1)
        {
            ed[u][i] = -1;
            EulerDFS(v, str[u][i]);
        }
    }

    if (st.size())
        EulerTour.pb(st);
}

bool Euler(ll edgeno = -1)
{
    ll i, Start, End, c = 0;
    Start = End = -1;
    for(i = 0; i < nsize; i++)
    {
        if(indeg[i] == outdeg[i]) continue;
        else if(indeg[i] - outdeg[i] == 1)
        {
            End = i;
            c++;
        }
        else if(outdeg[i] - indeg[i] == 1)
        {
            Start = i;
            c++;
        }
        else return false;
    }

    if(c > 2) return false;

    if(Start == -1)
    {
        for(i = 0; i < nsize; i++)
            if(outdeg[i])
            {
                Start = i;
                break;
            }
    }

    EulerTour.clear();
    EulerDFS(Start);
    reverse(EulerTour.begin(), EulerTour.end());

    if (edgeno != -1)
        if (EulerTour.size() != edgeno + 1) return false; //checking if graph is connected

    return true;
}
char s[25];

int main()
{
    ll cs, i, j, k, t, ans, n, x, y;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));

        for (i = 0; i < 26; i++)
        {
            ed[i].clear();
            str[i].clear();
        }

        for (i = 0; i < n; i++)
        {
            ss(s);

            y = strlen(s)-1;

            ed[s[0]-'a'].pb(s[y] - 'a');
            str[s[0]-'a'].pb(string(s));

            outdeg[s[0]-'a']++;
            indeg[s[y]-'a']++;
        }

        printf("Case %lld: ", cs);


        if (Euler(n-1))
        {
            printf("Yes\n");
            for (i = 0; i < EulerTour.size(); i++)
            {
                if (i)
                    printf(" ");
                for (j = 0; j < EulerTour[i].size(); j++)
                    printf("%c", EulerTour[i][j]);
            }
            printf("\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
