#include <stdio.h>
#include <string.h>

int pre[2000000];

int main()
{
	char s[2000000];

	long long i, j, t, cs = 1, l, c;

	scanf("%lld", &t);

	while(t--)
	{
		scanf("%s", s);
	//	printf("%s\n", s);

		i = 0, l = strlen(s);
		j = l - 1, c = 1;

		while(1)
		{
			if (s[i] == s[j])
			{
				j--;
				pre[i++] = c++;
			}
			else
			{
				j = l - 1;
                c = 1;
				if (s[j] == s[i])
                {
                    pre[i++] = 1;
                    j--;
                    c++;
                }
                else pre[i++] = 0;
			}
//		printf("%lld %lld %lld\n", i, j, c);
			if (i == l)
			    break;
		}

		for (i=0; i<l; i++)
		   printf("%lld %lld\n", i, pre[i]);

		for (i = l - 1; i>=0; i--)
		    {
	//	    	printf("%lld %lld\n", i, c);
		    	if (pre[i] == 1)
		    	     break;
		    }
		    printf("Case %lld: %lld\n", cs++, l + i);
	}

	return 0;
}
