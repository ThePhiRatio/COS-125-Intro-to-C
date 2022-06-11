#include<stdio.h>
int main()
{
	int i_number = 12;
	float f_number = 3.125;
	double d_number = 7.5345345;
        char character = 'T';	
	char text[] = "COS 135";

	printf("%i\n%1.3f\n%1.7f\n%c\n%s\n",i_number,f_number,d_number,character,text);

	return 0;
}

