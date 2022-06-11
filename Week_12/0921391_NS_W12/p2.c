#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

//Program by: Nicholas Soucy

//Program creates a different kernal shell interface for user

//Language: C

int getsize(char argument[])
{//POST: returns size of array before \n character
	int size =0;
	for (int i = 0; i < 100; i++)
	{
        
        if (argument[i] != '\n')
			size++;
		else 
			return size;	
	}
    return -1;
}

void trim(char argument[], char args[], int size)
{//POST: fills array with content before \n character
	for(int i = 0; i < size; i++)
	{
		args[i]=argument[i];
	}
}

void help()
{//POST: Prints the help screen to user
	printf("Valid commands are:\n'show.path' - shows path to current directory.\n");
	printf("'create' - creates a new file or directory.\n");
	printf("'show.files' - show only files in the current directory.\n");
	printf("'show.directories' - show only the folders in the current directory.\n");
	printf("'go.back' - go back a certian number of directories.\n");
	printf("'go.inside' - go inside the specific folder name.\n");
	printf("'exit' - quit the Maine Shell.\n");
}

int main()
{
	int count = 0;	//count for parsing
	char *token;	//token for parsing input
	int ct = 0; //amount of things in array

    	char input[100];    //entire input string
    	char command[100];    //commmand string
    	char argument[100];    //argument after command

	printf("./maineshell\n");

	//do-while true for input and processing
	do
	{
        
		printf("COS135@UMaine>>");
		fgets(input, 100, stdin);	//get command or command and number from user

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
				strcpy(argument,token);
			token = strtok(NULL, " ");
		}
		count = 0;
        
		//if user wants to exit, quit shell
		if(strcmp(command,"exit\n") == 0)
			return 0;
		//if user wants to help, print help screen
		else if(strcmp(command,"help\n") == 0)
			help();
		//if user wants to go inside directory
		else if(strcmp(command,"go.inside") == 0)
		{

			int size = getsize(argument);
			char arg [size+1];
			trim(argument, arg, size);
            		arg [size] = '\0';
//			char a [1] = " ";
//			strcat(a,arg);
			chdir(arg);
		}
        	//if user wants to go back a number of times
		else if ( (strcmp(command,"go.back") == 0) || (strcmp(command,"go.back\n") == 0) )
		{
            
			int num = atoi(argument);
			for (int i = 0; i < num; i ++)
			{
				chdir("..");
			}
		} 
		//if user wants to show directories
		else if(strcmp(command,"show.directories\n") == 0)
		{
			strcpy( command, "ls -d */" );
			system(command);
		}
		//if user wants to show files in current directory
		else if(strcmp(command,"show.files\n") == 0)
		{
			strcpy( command, "ls -p | grep -v /" );
			system(command);
		}
		//if user wants to create a file or directory
		else if(strcmp(command,"create") == 0)
		{
			int a = 0;	//boolean for checking if dir or file
			int size = getsize(argument);
			char args [size-1];
			trim(argument, args, size);
			for (int i = 0; i < size; i++)
			{
				if(args[i] == '.')
					a = 1;
			}
           		args[size] = '\0';
            
			if (a)
			{
				char a [100] = "touch ";
				strcat(a,args);
				system(a);
			}
			else
			{
				char a [100] = "mkdir ";
				strcat(a,args);
				system(a);
			}
		}
		//if user wants to see current path
		else if(strcmp(command,"show.path\n") == 0)
		{
			strcpy( command, "pwd" );
			system(command);
		}
		//else if user input is invalid
		else
		{
			printf("Invalid command! Please try again, or enter 'help' for a list of valid commands\n");
            
		}
		command[0] = '\0'; //reset command
		argument[0] = '\0'; //reset argument

	}while(1); //loop forever
}
