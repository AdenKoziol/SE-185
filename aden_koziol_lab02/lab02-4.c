#include<stdio.h>
#include<math.h>
 
void main(void)
{
	int a, b, e, f, j;
	double c, d, g, h, i, k, area, meters, celcius;
	a = 6427 + 1725;
	b = 6971 * 3925 - 95;
	c = 79 + 12 / 5;
	d = 3640.0 / 107.9;
	e = (22 / 3) * 3;
	f = 22 / (3 * 3);
	g = 22 / (3 * 3);
	h = 22 /  3* 3;
	i = (22.0 / 3) * 3.0;
	j = 22.0 / (3 * 3.0);
	k = 22.0 / 3.0 * 3.0;
	printf("%d\n %d\n %lf\n %lf\n %d\n %d\n %lf\n %lf\n %lf\n %d\n %lf\n", a, b, c, d, e, f, g, h, i, j, k);
	area = pow(23.567, 2) / (4 * 3.14); //circumference squared divided by 4 pi
	meters = 14 * .3048; //1 ft is .3048 m
	celcius = (76 - 32) / 1.8; //Farenheit - 32 divided by 1.8
	printf("%lf\n %lf\n %lf\n", area, meters, celcius);
}