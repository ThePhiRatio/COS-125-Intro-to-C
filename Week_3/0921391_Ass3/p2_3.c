#include<stdio.h>
int main()
{
	char name[20];
	float i1,i2,i3,i4,i5;
	float sum;
	float tax;
	float tot;

	printf("Enter store name = ");
	gets(name);
	printf("Enter price for item 1 = $");
	scanf("%f", &i1);
	printf("Enter price for item 2 = $");
	scanf("%f", &i2);
	printf("Enter price for item 3 = $");
	scanf("%f", &i3);
	printf("Enter price for item 4 = $");
	scanf("%f", &i4);
	printf("Enter price for item 5 = $");
	scanf("%f", &i5);
	printf("\n     Welcome to\n      ");
	puts(name);
	printf("\nItem 1        $%3.2f\nItem 2        $%3.2f\nItem 3        $%3.2f\nItem 4        $%3.2f\nItem 5        $%3.2f\n\n",i1,i2,i3,i4,i5);
	sum = i1+i2+i3+i4+i5;
	printf("Item total:   $%3.2f\n\n",sum);
	tax = (sum*0.1);
	printf("GST:          $%3.2f\n",tax);
	tot = sum+tax;
	printf("Total:        $%3.2f\n\n",tot);
	return 0;
}
