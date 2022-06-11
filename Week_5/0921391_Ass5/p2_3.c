#include<stdio.h>

//Code by: Nicholas Soucy
//Code calculates price and prints reciept for candy store

int main()
{
	//constand variables
	const float choc = 15.5;
	const float toff = 6.9;

	//variable decloration
	char name [100];
	int n_choc = 0;
	int n_toff = 0;
	float choc_p = 0;
	float toff_p = 0;
	float choc_p_dis = 0;
	float toff_p_dis = 0;
	float total = 0;
	float total_dis = 0;
	int not_sale = 0;
	int sale = 0;
	
	//get input;
	printf("\nEnter store name: ");
	fgets(name, 100, stdin);
	printf("Enter number of chocolate bags: ");
	scanf("%d", &n_choc);
	printf("Enter number of toffee bags: ");
	scanf("%d", &n_toff);

	//calculate chocolate price
	not_sale = n_choc % 5;
	sale = n_choc - not_sale;
	choc_p_dis = (not_sale * choc) + ((sale*choc)*0.9);
	choc_p = n_choc * choc;

	//calculate toffee price
	if(n_toff > 2)
		toff_p_dis = n_toff * (toff * 0.95);
	else
		toff_p_dis = n_toff * toff;

	toff_p = n_toff * toff;

	//calculate total price
	total = toff_p_dis + choc_p_dis;

	//calculate sale price
	if (total > 100)
		total_dis = total * 0.9;

	//print reciept 
	printf("\n     Welcome to ");
	puts(name);
	printf("Chocolates     x%d     $ %.2f\n",n_choc,choc_p);
	printf("   after discount      $ %.2f\n\n",choc_p_dis);
	printf("Toffees        x%d      $ %.2f\n",n_toff,toff_p);
	printf("   after discount      $ %.2f\n\n",toff_p_dis);
	printf("Total after discount   $ %.2f\n",total);
	printf("after 10%% discount     $ %.2f\n\n",total_dis);
	printf("          You owe      $ %.2f\n",total_dis);
	printf("          Thank you!\n\n");

	return 0;
}
