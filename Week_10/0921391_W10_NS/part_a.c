#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Program by: Nicholas Soucy

//Code

//Language: C

void swap(int *x, int *y);	//method to swap two ints

void push(int arr[],int input,int ct);	//method to push element into queue

void print(int arr[], int SIZE);	//method to print queue

int main()
{
	int arr[10] = {0}; //array to store data
	int count = 0;	//count for parsing
	char *token;	//token for parsing input
	int ct = 0; //amount of things in array

	char input[100];	//entire input string
	char command[100];	//commmand string
	char num[100];		//number to push
	
	printf("$./fifo_queue\n");

	//do-while true for input and processing
	do
	{
		printf("Enter command (push, print or quit): ");
		fgets(input, 50, stdin);	//get command or command and number from user

		//parse the input
		token = strtok(input, " ");
		while(token != NULL)
		{
			if(count == 0)
			{	
				strcpy(command, token);
				count++;
			}
			else
				strcpy(num,token);
			token = strtok(NULL, input);
		}
		count = 0;
		//if user wants to quit, quit
		if(strcmp(command,"quit\n") == 0)
			return 0;
		//if user wants to print, call print
		else if(strcmp(command,"print\n") == 0)
			print(arr, ct);
		//if user wants to push, push element into queue
		else if(strcmp(command,"push") == 0)
		{
			if(ct != 10)
				ct++;
			push(arr,atoi(num),ct);	
		}

		command[0] = '\0'; //reset command
		num[0] = '\0'; //reset num

	}while(1);
}
void print(int arr[], int SIZE)
{//POST: prints elements of array in order
	for (int i = 0; i < SIZE; i++)
	{	if (i == SIZE-1)
			printf("%d\n",arr[i]);
		else
			printf("%d, ",arr[i]);
	}
//	printf("\n");
}

void push(int arr[],int input,int ct)
{//POST: shifts all elements up the array, then places input at the first element
	if (ct == 1)
		arr[0] = input;
	else	
	{	
		if (ct == 10 && arr[9] != '\0')
			printf("Overflow: %d\n",arr[9]);
		for (int j = ct-1; j > 0; j--)
		{
			swap(&arr[j-1],&arr[j]);
		}
		arr[0] = input;
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

