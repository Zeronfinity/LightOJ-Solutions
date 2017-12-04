#include <stdio.h>
#include <math.h>
int main ()
{
	int i, t;
	double r;

	scanf("%d", &t);

	for (i = 1; i <= t; i++)
	{
		scanf("%lf", &r);
		printf("Case %d: %0.2lf\n", i, r*r*(4-2*acos(0)));
	}

	return 0;
}
