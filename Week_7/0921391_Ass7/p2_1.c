#include<stdio.h>
#include<stdlib.h>

//Code by: Nicholas Soucy
//Code multiplies two matrices of random generated values between 0 and 9 with sizes given by user
//Language: C

int main()
{
	//Create row and column values for matrix 1 & 2
	int r1 = 1;
	int c1 = 1;

	int r2 = 1;
	int c2 = 1;

	//error check and get input from user for matrix 1
	do
	{
		printf("Enter number of rows and columns of first matrix (format: r x c): ");
		scanf("%d%*c%*c%*c%d",&r1,&c1);
		if( r1 == 0 || c1 == 0 )
			printf("Error: The number of rows or columns of a matrix can't be 0.\nPlease try again.\n\n");
	}while(r1 == 0 || c1 == 0);

	//error check and get input from user for matrix 2
	do
	{
		printf("Enter number of rows and columns of second  matrix (format: r x c): ");
		scanf("%d%*c%*c%*c%d",&r2,&c2);
		if( r2 == 0 || c2 == 0 )
			printf("Error: The number of rows or columns of a matrix can't be 0.\nPlease try again.\n\n");
	}while(r2 == 0 || c2 == 0);

	//check to see if you can multiply matrix 1 by 2
	if(c1 != r2)
	{
		printf("Error: The %d x %d matrix can't be multiplied by the %d x %d matrix.\nReason: The number of columns of the 1st matrix must be equal to the number of rows of the 2nd matrix.\n",r1,c1,r2,c2);
		return 0;
	}
	
	//instantiate both matrix 1 & 2
	int matrix1 [r1][c1];
	int matrix2 [r2][c2];

	//populate and print matrix 1 with random values between 0 - 9
	for (int row = 0; row < r1; row++)
	{	
		for (int col = 0; col < c1; col++)
		{
			matrix1[row][col] = rand() % 10;
			printf("%d ", matrix1[row][col]);
		}
		printf("\n");
	}

	printf(".\n");
	
	//populate and print matrix 2 with random values between 0 - 9
	for (int row2 = 0; row2 < r2; row2++)
	{	
		for (int col2 = 0; col2 < c2; col2++)
		{	
			matrix2[row2][col2] = rand() % 10;
			printf("%d ", matrix2[row2][col2]);
		}
		printf("\n");
	}

	printf("=\n");

	//create product matrix and sum
	int product [r1][c2];
	int sum = 0;
	
	//calculating product
	for (int row3 = 0; row3 < r1; row3++)
	{	
		for (int col3 = 0; col3 < c2; col3++)
		{	
			for (int ct = 0; ct < r2; ct++)
			{
				sum += matrix1[row3][ct] * matrix2[ct][col3];
			}
			product[row3][col3] = sum;
			sum =0;
			printf("%d ",product[row3][col3]);
		}
		printf("\n");
	}

	return 0;
}


