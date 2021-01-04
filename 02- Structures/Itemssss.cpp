#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct items{
	char ItmName[20];
	char SrlNo[10];
	float Price;
	float Qty;
	float Total;
};

int main()
{
	struct items Purchase[5];
	int ctr;
	float tempQTY, tempPRI, AllTotal=0;
	char temp;
	
	
	for(ctr=0; ctr<5; ctr++)
		{
			printf("Item Name        : ");
			gets(Purchase[ctr].ItmName);
			printf("Serial Number    : ");
			gets(Purchase[ctr].SrlNo);
			printf("Price            : PHP ");
			scanf("%f",&tempPRI);
			Purchase[ctr].Price = tempPRI;
			printf("Quantity         : ");
			scanf("%f", &tempQTY);
			Purchase[ctr].Qty = tempQTY;	
			
			Purchase[ctr].Total = Purchase[ctr].Price * Purchase[ctr].Qty;
			
			printf("Press any key to continue...");
			getch();
			scanf("%c", &temp);
			
			system("CLS");
		}
		
	for(ctr=0; ctr<5; ctr++)
		{
			AllTotal += Purchase[ctr].Total;
		} 	
		
		
	for(ctr=0; ctr<5; ctr++)
		{
			printf("\nITEM NAME:        %s", Purchase[ctr].ItmName);
			printf("\nSERIAL NUMBER:    %s", Purchase[ctr].SrlNo);
			printf("\nPRICE:            PHP %0.2f", Purchase[ctr].Price);
			printf("\nQUANTITY:         %0.0f",Purchase[ctr].Qty);
			printf("\nTOTAL:            PHP %0.2f", Purchase[ctr].Total);
		} 
		
		
	printf("\n\n\nTOTAL PURCHASED: PHP %0.2f", AllTotal);							
	
}


