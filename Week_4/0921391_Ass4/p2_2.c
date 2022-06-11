#include <stdio.h>

void swap(int *x, int *y);
double average(int n, int m, int o);

int main()
{
	char name[50];
	int grade1 = 0;
	int grade2 = 0;
	int grade3 = 0;
	double aver = 0;

	printf("Enter student's name = ");
	gets(name);
	printf("Enter student's first grade = ");
	scanf("%d", &grade1);
	printf("Enter student's second grade = ");
	scanf("%d", &grade2);
	printf("Enter student's thrid grade = ");
	scanf("%d", &grade3);

	aver = average(grade1, grade2, grade3);

	if (grade3 > grade2)
		swap(&grade3, &grade2);
	if (grade2 > grade1)
		swap(&grade2, &grade1);
	if (grade3 > grade2)
		swap(&grade3, &grade2);

	printf("\n%s   %d    %d    %d    %3.2f\n",name,grade1,grade2,grade3,aver);

	return 0;	
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

	return;
}

double average(int n, int m, int o)
{
	return ((double)(n+m+o)/3);
}

