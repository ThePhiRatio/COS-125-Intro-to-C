#include<stdio.h>
#include<ctype.h>

//Code by: Nicholas Soucy
//Code gets amount of each food item sold over the weekend, multiples the matricies of price and amount
//then shows the user the amount of money made.
//Language C

int main()
{
	//variables to check for input, create sentenal and to check if user entered a character

	int input = 0;
	int s = 0;
	char error = 0;
	
	//array for the price of the food items and initializing the array to store amount of food
	int price[3] = {3,4,1};
	int amount[3][2];

	//print and get input from user for bagels on saturday
	do
	{	
		printf("\nNumber of Bagel sales on Saturday: ");
		if(scanf("%d", &input) == 1)
		{
			amount[0][0] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);

	s = 0;
	
	//print and get input from user for flatbreads on saturday
	do	
	{
		printf("Number of Flatbread sales on Saturday: ");
		
		if(scanf("%d", &input) == 1)
		{
			amount[1][0] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);
	
	s = 0;
	
	//print and get input from user for muffins on saturday
	do
	{
		printf("Number of Muffin sales on Saturday: ");
		
		if(scanf("%d", &input) == 1)
		{
			amount[2][0] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);

	s = 0;
	
	//print and get input from user for bagels on sunday
	do
	{
		printf("Number of Bagel sales on Sunday: ");
		
		if(scanf("%d", &input) == 1)
		{
			amount[0][1] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);

	s = 0;
	
	//print and get input from user for flatbreads on sunday
	do
	{
		printf("Number of Flatbread sales on Sunday: ");
		
		if(scanf("%d", &input) == 1)
		{
			amount[1][1] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);

	s = 0;
	
	//print and get input from user for muffins on Sunday
	do
	{
		printf("Number of Muffin sales on Sunday: ");
		
		if(scanf("%d", &input) == 1)
		{
			amount[2][1] = input;
			s = 1;
		}
		else if (scanf("%c", &error) == 1)
		{	
			printf("Error: Sales figures must be numbers.\nPlease try again.\n\n");
		}
	}while (s == 0);

	printf("\n");

	//initialize sum and product array
	int sum = 0;
	int product[2];
	
	//calculate product of price * amount matricies
	for (int col = 0; col < 2; col++)
	{	for (int ct = 0; ct < 3; ct++)
		{
			sum += price[ct] * amount[ct][col];
		}
		product[col] = sum;
		sum = 0;
	}


	//print results to the user
	printf("%d %d %d . %d %d = %d %d\n",3,4,1,amount[0][0],amount[0][1],product[0],product[1]);
	printf("        %d %d\n",amount[1][0],amount[1][1]);
	printf("        %d %d\n\n",amount[2][0],amount[2][1]);
	
	printf("Total sale on Saturday: $ %d\n",product[0]);
	printf("Total sale on Sunday: $ %d\n",product[1]);
	printf("Total sale on weekend: $ %d\n\n",(product[0] + product[1]));


	return 0;	
}
