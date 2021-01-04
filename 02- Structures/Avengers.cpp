#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct Avengers {
	char number[5];
	char name[20];
	char alias[20];
	int age;
	char occupation[20];
};

int main() {
	
	struct Avengers avenger[5];
	int tempAge, i;
	char temp;
	
	printf("Enter avenger's details!\n\n");
	
	for(i=0; i<5; i++){
		printf("Enter Hero number: ");
		gets(avenger[i].number);
		printf("Enter Real Name: ");
		gets(avenger[i].name);
		printf("Enter Alias: ");
		gets(avenger[i].alias);
		
		printf("Enter occupation: ");
		gets(avenger[i].occupation);
		
		printf("Enter age: ");
		scanf("%d", &tempAge);
		avenger[i].age = tempAge;
		
		
		printf("\n\nPress any key to continue...");
		scanf("%c", &temp);
		getch();
	
		system("CLS");
	}
	
	for(i=0; i<5; i++) {
		printf("\nNumber: %s", avenger[i].number);
		printf("\nName: %s", avenger[i].name);
		printf("\nAlias: %s", avenger[i].alias);
		printf("\nAge: %d", avenger[i].age);
		printf("\nOccupation: %s", avenger[i].occupation);
		printf("\n \n");
	}
	
	getch();
	return 0;
}
