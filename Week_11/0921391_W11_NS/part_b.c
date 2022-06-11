#include<stdio.h>

//Program by: Nicholas Soucy

//Program takes a parking lot and allows the user to see what spaces in the
//parking lot are available and can reserve parking spots 

//Language C

void readfile(FILE *fptr,char data[][12]);

void stat(char data[][12]);

void writefile(FILE *fptr, char data[][12]); 

void print(char data[][12]);

void reserve(FILE *fptr,char data[][12]);

int main()
{

	//file stream creation
	FILE *fptr;
	fptr = fopen("carpark.txt","r+");

	char data [10][12];	//create 2-d array for data

	readfile(fptr, data);	//read file into 2-d array

	char select_c;		//char for user selection

	//get input from user
	do
	{	printf("Select your display choice from the menu:\n");
		printf("D to display current status of the carpark\n");
		printf("R to reserve an empty slot in the carpark\n");
		printf("S to display %% occupancy of the carpark\n");
		printf("Q to quit.\n\n");
		scanf(" %c",&select_c);
		printf("\n");

	
	//quit or order array by user specification
		switch(select_c)
		{
			case 'Q' :
				fclose(fptr);
				return 0;
			case 'D' :
				print(data);
				break;
			case 'R' :
				reserve(fptr,data);
				break;
			case 'S' :
				stat(data);
				break;	
		}	
	} while(1);	
}


void readfile (FILE *fptr,char data[][12])	//PRE: Must have file formatted, and with chars
{//POST: populates 2-d data array with elements read by file

	char buff; //buffer to hold data in string from file 

	//scan char by char into data array
	for (int r = 0; r < 10; r++)
	{
		for(int c = 0; c < 12; c++)
		{
			buff = fgetc(fptr);
			data[r][c] = buff;
		}
	}
}


void writefile(FILE *fptr, char data[][12])
{//POST: writes data array to fptr
	for(int r = 0; r < 10; r++)
	{
		for(int c = 0; c < 12; c++)
		{
			fprintf(fptr,"%c",data[r][c]);
		}
		fputc('\n',fptr);
	}
}

void print(char data[][12])
{//POST: displays parking lot in given format

	//print header
	printf("  AB CD EF GH\n");

	for (int r = 0; r < 10; r++)
	{
		//print row header
		if((r+1) == 10)
			printf("%d",(r+1));
		else
			printf("%d ",(r+1));

		//print data
		for(int c = 0; c < 12; c++)
		{
			printf("%c",data[r][c]);
		}
		printf("\n");
	}
}

void stat(char data[][12])
{//POST: prints the percent of occupancy in lot
	float MAX = 80;		//total number of lots 
	float ct = 0;		//count for amount of '.'
	for(int r = 0; r < 10; r++)
	{
		for(int c = 0; c < 12; c++)
		{
			if(data[r][c] == 'X')
				ct++;
		}
	}
	float occ = (ct/MAX)*100;
	printf("Current occupancy is %.1f%%\n\n",occ);
}

void reserve(FILE *fptr,char data[][12])
{//POST: reserves a reccomened or user defined spot in parking lot, then updates file
	int rf = 0;
	int cf = 0;

	//search through grids to find nearest open spot
	for (int grid = 1; grid < 12; grid++)
	{
		for (int r = 0; r < grid; r++)
		{
			for(int c = 0; c < grid; c++)
			{
				if (r > 9)
					grid = c = r = 12;
				else if(data[r][c] == '.')
				{
					rf = r; cf = c;
					grid = c = r = 12;
				}
			}
		}	
	}

	//map the column number to a letter
	char col;
	switch(cf)
	{
		case 0 :
			col = 'A';
			break;
		case 1 :
			col = 'B';
			break;
		case 3 : 
			col = 'C';
			break;
		case 4 : 
			col = 'D';
			break;
		case 6 :
			col = 'E';
			break;
		case 7: 
			col = 'F';
			break;
		case 9:
			col = 'G';
			break;
		case 10:
			col = 'H';
			break;
	}

	//get user input
	printf("Closest available slot is %d%c, do you want to reserve it (y/n)?",(rf+1),col);
	char select;
	scanf(" %c",&select);

	//if y, reserve spot and rewrite carlot
	if(select == 'y')
	{
		printf("Your selection %d%c is reserved!\n\n",(rf+1),col);
		data[rf][cf] = 'X';
		writefile(fptr,data);
	}

	//if n, ask what spot they wish to park in
	else if(select == 'n')
	{
		int ri; int ci;  //row and column input 
		printf("Please enter your preferred empty slot: ");
		scanf(" %d%c",&ri,&col);
		ri = ri-1;

		//check to see if its in the bound of the lot
		if((ri < 0) || (ri > 9) || (col < 65) || (col > 72))
		       printf("Row and/or column value is out of range, please try again!\n\n");
		else	
		{
			//map letter col to number col
			switch(col)
			{
				case 'A' :
					ci = 0;
					break;
				case 'B' :
					ci = 1;
					break;
				case 'C' : 
					ci = 3;
					break;
				case 'D' : 
					ci = 4;
					break;
				case 'E' :
					ci = 6;
					break;
				case 'F': 
					ci = 7;
					break;
				case 'G':
					ci = 9;
					break;
				case 'H':
					ci = 10;
					break;
			}
			//check to see if spot is taken	
			if(data[ri][ci] != '.')
				printf("Spot taken! Please try again.\n\n");

			//if input is valid, reserve spot
			else
			{
				printf("Your selection %d%c is reserved!\n\n",ri,col);
				data[ri][ci] = 'X';
				writefile(fptr,data);
			}
		}
	}
}
