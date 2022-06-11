#include<stdio.h>

//Code by: Nicholas Soucy
//code sums all even numbers between one and a number by user, then prints

int main()
{
	//variable decloration
	int i = 1;
	float end = 0; 
	float ans = 0;

	//get input from user
	printf("Input a number larger than 1: ");
	scanf("%f",&end);

	//calculate sum
	for(i; i <= end; i++)
	{
		if (i%2 == 0)
			ans = ans + i;
	}

	//print results
	printf("Sum of even numbers between 1 and %.0f: %.0f\n",end,ans);
	
	return 0;
}
