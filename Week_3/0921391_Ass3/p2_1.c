#include<stdio.h>
int main()
{
	int F;
	float C;
	printf("Enter temperature in Fahrenheit = ");
	scanf("%i", &F);
	C = (F-32)/1.8;
	printf("Temperature in Celsius = %3.3f C\n",C);
	return 0;
}
