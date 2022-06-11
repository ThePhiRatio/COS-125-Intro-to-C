//Code by: Nicholas Soucy
//Code checks if password is valid then encrypts the password

#include <stdio.h>

//function declaration
int is_long(char p [], int size);	//function to test if password is at least eight characters
int is_uplo(char p [], int size);	//function to test if password has at least one uppercase and lowercase
int is_digit(char p [], int size);	//function to test if password has at least one digit
int is_character(char p [], int size);	//function to test if password has at least one of these character '! @ # $'

void encrypt(char p [], int size);	//function to encrypt password	

int main()
{
	//variable declaration
	const int SIZE = 100;	//max size of password
	char password [SIZE];	//password from user

	//user input
	printf("Please enter your preferred password: ");
	fgets(password, 100, stdin);

	//testing if password is valid
	if ((is_character(password, SIZE)) && (is_digit(password, SIZE)) && (is_long(password, SIZE)) && (is_uplo(password, SIZE)))
	{	
		printf("Valid\n");
		encrypt(password, SIZE);	//send password to be encrypted
	}
	//testing to see why password isn't valid
	else
	{
		printf("Invalid\n");

		if (!is_long(password, SIZE))
			printf("Reason: Your password should contain at least eight chracters.\n");
		if (!is_digit(password, SIZE))
			printf("Reason: Your password should contain at least one digit.\n");
		if (!is_character(password, SIZE))
	       		printf("Reason: Your password should contain at least one of the four special characters \"! @ # $\"\n");
		if(!is_uplo(password,SIZE))
			printf("Reason: Your password should contain at least one uppercase letter and one lower case letter.\n");
	}	

	return 0;
}

//checks to see if password is at least eight characters long
int is_long(char p [], int size)
{
	int counter = 0;	//counter to see how long the password is
	for (int i = 0; i < size; i++)
	{
		if (counter < 8 && p[i] == 10)
			return 0;
		counter++;
	}
	return 1;
}

//checks for uppercase and lowercase letter
int is_uplo(char p [], int size)
{
	int is_upper = 0;	//set to 1 if uppercase letter is found
	int is_lower = 0;	//set to 1 if lowercase letter is found
	for (int i = 0; i < size; i++)
	{
		if((p[i] > 64) && (p[i] < 91))
		{	is_upper = 1;		}
		if((p[i] > 96) && (p[i] < 123))
		{	is_lower = 1;		}
	}
	if(is_upper && is_lower)
	{	return 1;	}
	return 0;	
}

//checks to see if password contains at least one digit
int is_digit(char p [], int size)
{
	for (int i = 0; i < size; i++)
	{
		if ((p[i] < 58) && (p[i] > 47))
			return 1;
	}
	return 0;
}

//checks to see if password contains one of the special characters
int is_character(char p [], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (p[i] == 33 || p[i] == 64 || p[i] == 35 || p[i] == 36)
			return 1;
	}
	return 0;
}

//encrypts password
void encrypt(char p [], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (p[i] == 33 || p[i] == 64 || p[i] == 35 || p[i] == 36)
			p[i] -= 1;
		if ((p[i] > 47 && p[i] < 58) || (p[i] > 64 && p[i] < 91) || (p[i] > 96 && p[i] < 123))
			p[i] += 1;
	}
}
