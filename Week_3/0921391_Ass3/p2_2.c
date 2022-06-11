#include<stdio.h>
int main()
{
	int w;
	int l;
	int a;
	printf("Enter width = ");
	scanf("%i", &w);
	printf("Enter length = ");
	scanf("%i", &l);
	a = (w*l);
	printf("Area of the rectangle = %i\n", a);
	return 0;
}
