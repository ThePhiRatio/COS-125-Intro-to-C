#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Code by: Nicholas Soucy

//Code gets string from user then uses a stack to reverse the input string, then prints to user

//Language: C

void reverse(char arr[],char input[],int size)
{//POST: takes input string and pushes all elements into the output array in stack format
	for(int i = 0; i < size; i++)
		arr[size-1-i] = input[i];
}

void print(char arr[], int SIZE)
{//POST: prints the reversed string
	printf("Reversed output is: \"");
	for(int i = 0; i < SIZE; i++)
	{
		if(arr[i] != '\n')	
			printf("%c",arr[i]);
	}
	printf("\"\n");
}

int main()
{
	char arr[100];	//reversed input string

	int size = 0; //amount of things in array

	char input[100];	//entire input string
	
	printf("$./stack_reverse\n");

	printf("Enter a phrase: ");
	fgets(input, 100, stdin);	//get user input
	
	size = strlen(input);		//find size of input

	reverse(arr,input,size);	//reverse all elements

	print(arr,size);		//print reversed string

	return 0;
}
