#include <stdio.h>
#include <math.h>
int main ()
{
    double i, t, ox, oy, ax, ay, bx, by, mx, my, oa, am, s;

    scanf("%lf", &t);

    for (i = 1; i <= t; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by);
        mx = (ax+bx)/2;
        my = (ay+by)/2;

        am = sqrt((ax-mx)*(ax-mx) + (ay-my)*(ay-my));
        oa = sqrt((ax-ox)*(ax-ox) + (ay-oy)*(ay-oy));

        s = 2*oa*asin(am/oa);

        printf("Case %.0lf: %lf\n", i, s);
    }

    return 0;
}
