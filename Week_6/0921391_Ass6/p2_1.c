#include <stdio.h>

//Code by: Nicholas Soucy
//Code takes an integer from the user and calculates the fibonacci sequence up to the given number.

int main ()
{
	//variable declartion 
	int a  = 0; //first number in fibonacci sequence
	int b  = 1; //second number in fibonacci sequence
	int c = 0; 
	int input = 0; //input from user

	//gets input from user 
	printf("Enter a number: ");
	scanf("%d", &input);

	//error checking: if input is a positive int
	if(input < 0)
		printf("Invalid input - please try a positive integer.\n");

	printf("Fibonacci Series: 0, 1");

	//calculating and printing fibonacci sequence
	for (int i = 2; c <= input; i++)
	{
		c = a + b;
		a = b;
		b = c;
		if (b <= input)
			printf(", %d",b);
	}
	printf("\n");

	return 0;
}
