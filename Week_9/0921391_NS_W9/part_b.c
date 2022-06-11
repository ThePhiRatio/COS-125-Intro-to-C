#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 

//Code by: Nicholas Soucy
//Program reads data set into array then deliniates them by 10 years and 100 years, then prints 
//results and statistical data into certian files 

void readfile (FILE *fptrm, double data[][3]); //reads initial file into array

void sum (double data[][3], double output[][2],int sep); //breaks the data into 10 year and 100 year data sets

void write (FILE *fptr, double output [][2],int type,int row); //writes the 10 year and 100 year data sets into files

void order_year (double output[][3], int row); //orders the amount of sunspots in ascending order for the original data

void order (double output[][2], int row); //orders the 10 year and 100 year data sets 

void stats_year (double data [][3],double stat []); //computes the stats for the original data set

void stats (double data [][2],double stat [],int row);	//computes the stats for the 10 year and 100 year data sets

void write_stat (FILE *fptr, double output [],int num);	//writes the stats for all data sets into individual files

int main()
{
	//file stream creation
	FILE *fptr;
	fptr = fopen("sunspots_dataset.csv","r");

	double data [289][3];	//create 2-d array for data

	readfile(fptr, data);	//read file into 2-d array
	fclose(fptr);		//close scanner

	double out_10 [29][2];	//create both arrays of 10 year and 100 year
	double out_100 [3][2];

	sum(data, out_10, 10);		//populate those arrrays
        sum(data, out_100, 100);	

	//print into sunspots_dataset_10.csv & sunspots_dataset_100.csv
	FILE *fptr1;
	fptr1 = fopen("sunspots_dataset_10.csv","w+");
	FILE *fptr2;
	fptr2 = fopen("sunspots_dataset_100.csv","w+");
	write(fptr1,out_10,10,29);
	write(fptr2,out_100,100,3);
	fclose(fptr1);
	fclose(fptr2);

	//order the arrays for statistical analysis
	order_year(data,289);
        order(out_10,29);
	order(out_100,3);

	//create the arrays to hold the min, max, mean, median and st-dev of each data set
	double stat_y [5];
	double stat_10 [5];
	double stat_100 [5];

	//calculate stats
	stats_year (data,stat_y);
	stats(out_10,stat_10,29);
	stats(out_100,stat_100,3);

	//print stats into sunspots_summary_yearly,decennially and centennially as a text file
	FILE *fptr3,*fptr4,*fptr5;
	fptr3 = fopen("sunspots_summary_yearly","w+");
	fptr4 = fopen("sunspots_summary_decennially","w+");
	fptr5 = fopen("sunspots_summary_centennially","w+");
	write_stat(fptr3,stat_y,1);
	write_stat(fptr4,stat_10,2);
	write_stat(fptr5,stat_100,3);
	fclose(fptr3);
	fclose(fptr4);
	fclose(fptr5);

	return 0;
}

void readfile (FILE *fptr,double data[][3])	//PRE: Must have file formatted, and with integers
{//POST: populates 2-d data array with elements read by file
	char buff [100]; //buffer to hold data in string from file

	fscanf(fptr, "%s",buff);	//scan first line 

	//scan each line and put into output array
	for (int i = 0; i < 289; i++)
	{
		fscanf(fptr, "%[^,]s",buff);
		data[i][0] = atof(buff);
		
		fgetc(fptr);

		fscanf(fptr, "%[^,]s",buff);
		data[i][1] = atof(buff);

		fgetc(fptr);

		fscanf(fptr, "%[^\n]s",buff);
		data[i][2] = atof(buff);
		
		fgetc(fptr);
	}
}

void sum (double data[][3], double output[][2],int sep)
{//POST: Calculates average of a col for a given 2d data set by year, sep is a variable to tell how
	//the data is being deliniated.
	
	double sum = 0;	//sum for average
	double year = 1700;
 
	for(int i = 0; i < (289/sep)+1; i++)
	{	for(int j = (i*sep); j < ((i*sep)+sep); j++)
		{
			if(sep == 100 && j > 288)
				break;	
			sum += data[j][2];
		}
		if(i != 0)
			year += sep;
		output [i][0] = year;
		output [i][1] = sum;
		sum = 0;
	}
}

void write (FILE *fptr, double output [][2],int type,int row)
{//POST: Populates the given file with the data given
	char buff [100]; //data buffer
	if(type == 10)
		fprintf(fptr, "%s,%s\n","decennially","sunspots");
	else 
		fprintf(fptr, "%s,%s\n","centennially","sunspots");
	for (int r = 0; r < row; r++)
	{	
		fprintf(fptr, "%.0f,",output[r][0]);
		fprintf(fptr, "%.1f\n",output[r][1]);
	}
}

void stats_year (double data [][3],double stat [])
{//POST: Gives the min, max, mean, median and st-dev into an array for a given 2-d array with 3 columns
	//min
	stat[0] = data[0][2];
	//max
	stat[1] = data[288][2]; 
	//mean,not calculated yet
	double mean = 0;
	//median
	stat[3] = data[289/2][2];
	//st-dev, not calculated yet
	double st_dev = 0;

	//mean
	for(int r = 0; r < 289; r++)
	{	
		mean += data[r][2];
	}
	mean = mean/289;
	stat[2] = mean;

	//st-div
	for(int i = 0; i < 289; i++)
	{
		st_dev += pow(data[i][2] - mean, 2);
	}
	stat[4] = sqrt(st_dev/289); 

}


void stats (double data [][2],double stat [],int row)
{//POST: Gives the min, max, mean, median and st-dev into an array for a given 2-d array with 2 columns
	//min
	stat[0] = data[0][1];
	//max
	stat[1] = data[row-1][1]; 
	//mean,not calculated yet
	double mean = 0;
	//median
	stat[3] = data[row/2][1];
	//st-dev, not calculated yet
	double st_dev = 0;

	//mean
	for(int r = 0; r < row; r++)
	{	
		mean += data[r][1];
	}
	mean = mean/row;
	stat[2] = mean;

	//st-div
	for(int i = 0; i < row; i++)
	{
		st_dev += pow((data[i][1] - mean),2);
	}
	stat[4] = sqrt(st_dev/row); 

}


void order_year (double output[][3], int row)
{//POST: orders the array in asending order by a specific column
	double temp = 0;	//temp double to hold array element for swaping
	for (int i = 0; i < row; i++)
	{	for (int j = i+1; j < row; j++)
	       	{
			if(output[i][2] > output[j][2])
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


void order (double output[][2], int row)
{//POST: orders the array in asending order by a specific column
	double temp = 0;	//temp double to hold array element for swaping
	for (int i = 0; i < row; i++)
	{	for (int j = i+1; j < row; j++)
	       	{
			if(output[i][1] > output[j][1])
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

void write_stat (FILE *fptr, double output [],int num)
{//POST: populates the given file with the statistical information
	switch (num)
	{
		case 1: 
			fprintf(fptr,"%s %s %s\n","Year","Summary","Statistics");
			break;
		case 2: 
			fprintf(fptr,"%s %s %s\n","Decade","Summary","Statistics");
			break;
		case 3:
			fprintf(fptr,"%s %s %s\n","Century","Summary","Statistics");
			break;
	}
	fprintf(fptr,"   Min:  %.2f\n",output[0]);
	fprintf(fptr,"   Max:  %.2f\n",output[1]);
	fprintf(fptr,"  Mean:  %.2f\n",output[2]);
	fprintf(fptr,"Median:  %.2f\n",output[3]);
	fprintf(fptr,"St-Dev:  %.2f\n",output[4]);
}
