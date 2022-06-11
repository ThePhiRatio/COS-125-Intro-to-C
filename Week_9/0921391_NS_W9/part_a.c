#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//Program by: Nicholas Soucy
/*Program loads data of month, arrivals and departures numbers into an array, computes the average
then averages the values in a new array. Then from user input the data is sorted and outputed. */

void readfile(FILE *fptr,int data[][4]);

void average(int data[][4],double output[][3],int col);

void order(double output[][3], int col);

void print(double output[][3]);

int main()
{
	//file stream creation
	FILE *fptr;
	fptr = fopen("aircraft_arrivals_departures.csv","r");

	int data [72][4];	//create 2-d array for data
	double output [6][3];	//create 2-d array for output

	readfile(fptr, data);	//read file into 2-d array
	fclose(fptr);		//close scanner

	//populate first column of the output with the years
	for (int i = 0; i < 6; i++)
	{
		output [i][0] = (2010 + i);
	}

	//compute averages of arrivals and departures, then enter them into ouput array
	average(data,output,2);
	average(data,output,3);

	char select_c;	//input char from user\


	//get input from user
	do
	{	printf("Select your display choice from the menu:\n");
		printf("Y to display average arrivals and departures - ordered by year.\n");
		printf("A to display average arrivals and departures - ordered by arrivals.\n");
		printf("D to display average arrivals and departures - ordered by departures.\n");
		printf("Q to quit.\n\n");
		scanf(" %c",&select_c);
		printf("\n");

	
	//quit or order array by user specification
		switch(select_c)
		{
			case 'Q' :
				return -1;
			case 'Y' :
				printf("Yearly average arrivals and departures (ordered by year):\n\n");
				order(output,0);
				print(output);
				break;
			case 'A' :
				printf("Yearly average arrivals and departures (ordered by arrivals):\n\n");
				order(output,1);
				print(output);
				break;
			case 'D' :
				printf("Yearly average arrivals and departures (ordered by departures):\n\n");
				order(output,2);
				print(output);
				break;	
		}	
	} while(select_c != 'Q');

	return 0;
}

void readfile (FILE *fptr,int data[][4])	//PRE: Must have file formatted, and with integers
{//POST: populates 2-d data array with elements read by file
	char buff [100]; //buffer to hold data in string from file

	fscanf(fptr, "%s",buff);	//scan first line 

	//scan each line and put into output array
	for (int i = 0; i < 72; i++)
	{
		fscanf(fptr, "%[^-]s",buff);
		data[i][0] = atoi(buff);
		
		fgetc(fptr);

		fscanf(fptr, "%[^,]s",buff);
		data[i][1] = atoi(buff);

		fgetc(fptr);

		fscanf(fptr, "%[^,]s",buff);
		data[i][2] = atoi(buff);

		fgetc(fptr);

		fscanf(fptr, "%[^\n]s",buff);
		data[i][3] = atoi(buff);
		
		fgetc(fptr);
	}
}

void average (int data[][4], double output[][3],int col)
{//POST: Calculates average of a col for a given 2d data set by year.
	double sum = 0;	//sum for average
	for(int i = 0; i < 6; i++)
	{	for(int j = (i*12); j < ((i*12)+12); j++)
		{	
			sum += data[j][col];
		}
		output [i][col-1] = (sum/12);
		sum = 0;
	}
}

void order (double output[][3], int col)
{//POST: orders the array in asending order by a specific column
	double temp = 0;	//temp double to hold array element for swaping
	for (int i = 0; i < 6; i++)
	{	for (int j = i+1; j < 6; j++)
	       	{
			if(output[i][col] > output[j][col])
			{
				for (int k = 0; k < 3; k++)
				{	temp = output[i][k];
					output[i][k] = output[j][k];
					output[j][k] = temp;
				}	
			}	
		}	
		
	}
}

void print (double output[][3])
{//POST: prints given array
	printf("Year    Arrivals    Departures\n");
	for (int r = 0; r < 6; r++)
	{
		printf("%.0f    ",output[r][0]);

		printf("%.2f    ",output[r][1]);

		printf("%.2f  ",output[r][2]);
		
		printf("\n");
	}
	printf("\n\n");
}
