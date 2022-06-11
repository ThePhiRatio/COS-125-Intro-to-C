#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Program by: Nicholas Soucy

//Code impliments a stack type of data container for a given letter from user

//Language: C

void pop(char arr[], int ct)
{//POST: function pops the top most element from the array and prints element for user
	if(ct == 0)
		printf("WARNING: Stack is empty!\n");
	else
	{	
		printf("Popped: %c\n",arr[ct-1]);
		arr[ct-1] = '\0';
		
	}
}

void push(char arr[],char input[],int ct)
{//POST: pushes the letter from user onto the top most element in array
	if(ct == 20)
		printf("WARNING: Stack is full!\n");
	else
		arr[ct-1] = input[0];
}

void print(char arr[], int SIZE)
{//POST: prints the elements of the array from the top to bottom verticlly
	for (int i = SIZE-1; i >= 0; i--)
		printf("%c\n",arr[i]);
}

int main()
{
	char arr[20]; //final char array of characters

	int count = 0;	//count for parsing
	char *token;	//token for parsing input
	int ct = 0; //amount of things in array

	char input[100];	//entire input string
	char command[100];	//commmand string
	char letter[100];	//letter to push
	
	printf("$./stack\n");

	//do-while true for input and processing
	do
	{
		printf("Enter command (push, pop, print or quit): ");
		fgets(input, 50, stdin); //get input from user

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
				strcpy(letter,token);
			token = strtok(NULL, input);
		}
		count = 0;
		//if user wants to quit, quit
		if(strcmp(command,"quit\n") == 0)
			return 0;
		//if user wants to print, call print
		else if(strcmp(command,"print\n") == 0)
			print(arr, ct);
		//if user wants to push, call push
		else if(strcmp(command,"push") == 0)
		{
			if(ct != 20)
				ct++;	//increase ct
			push(arr,letter,ct);	
		}
		//if user wants to pop, call pop
		else if(strcmp(command,"pop\n") ==0)
		{
			pop(arr,ct);
			if(ct > 0)	//decrement ct
				ct--;
		}

		command[0] = '\0'; //reset command
		letter[0] = '\0'; //reset letter

	}while(1);
}
