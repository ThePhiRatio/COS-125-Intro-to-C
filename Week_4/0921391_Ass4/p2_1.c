#include <stdio.h>

double add(double x, double y);
double sub(double x, double y);
double mult(double x, double y);
double div(double x, double y);

int main()
{
	double n1 = 0;
	double n2 = 0;
	double a = 0;
	double s = 0;
	double m = 0;
	double d = 0;

	printf("Enter two numbers, in the format 'x.zz y.ff'.\n");
	scanf("%lf%*c%lf", &n1, &n2);
	
	a = add(n1, n2);
	s = sub(n1, n2);
	m = mult(n1, n2);
	d = div(n1, n2);

	printf("%3.2f + %3.2f = %3.2f\n",n1,n2,a);
	printf("%3.2f - %3.2f = %3.2f\n",n1,n2,s);
	printf("%3.2f * %3.2f = %3.2f\n",n1,n2,m);
	printf("%3.2f / %3.2f = %3.2f\n",n1,n2,d);

	return 0;
	
}

double add(double x, double y)
{
	return x+y;
}
double sub(double x, double y)
{
	return x-y;
}
double mult(double x, double y)
{
	return x*y;
}
double div(double x, double y)
{
	return x/y;
}

