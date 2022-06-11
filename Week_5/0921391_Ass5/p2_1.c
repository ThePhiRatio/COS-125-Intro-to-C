#include<stdio.h>

//Code by: Nicholas Soucy
//Code takes input from user and check if it is a vowel or consonant, code checks for valid input.

int main()
{	
	//variable decloration
	char input = 0;
	char done = 0;
	
	//get input from user
	printf("Enter a letter or -1 to quit: ");
	scanf("%c%c",&input,&done);

	//sentinal while loop, quits when -1
	while((input != 45) && (done != 49)) 
	{	
		//check if input is a vowel
		if ((input == 65) || (input == 69) || (input == 73) || (input == 79) || (input == 85) || (input == 97) || (input == 101) || (input == 105) || (input == 111) || (input == 117))
			printf("%c is a vowel.\n",input);
	
		//check if input is valid
		else if ((input < 65) || (input > 122))
			printf("%c is not a letter in the English alphabet.\n",input);

			//else input is a consonant
			else 
				printf("%c is a consonant.\n",input);
	
		//get input again
		printf("Enter a letter or -1 to quit: ");
		scanf("%c%c", &input, &done);
	}
	return 0;

}
