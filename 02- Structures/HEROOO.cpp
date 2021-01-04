#include<stdio.h>
#include<conio.h>
#include<windows.h>


struct Group{
	
	char Sup_Group[20];
	char Sup_Name[40];
};

struct SuperHero{
	
	struct Group HeroGroup;
	
	char Sup_RealName[40];
	int Sup_Age;
	char Sup_Origin[30];
	char Sup_Abilities[50];
};

int main()
{
	
	struct SuperHero Herooo[5];
	int i, edad=0;
	char temp;
	
for(i=0; i<5; i++)
{
	
	printf("INSERT THE FOLLOWING INFORMATION:\n\n");
	printf("Hero Group: ");
	gets(Herooo[i].HeroGroup.Sup_Group);
	printf("Hero Name: ");
	gets(Herooo[i].HeroGroup.Sup_Name);
	printf("Real Name: ");
	gets(Herooo[i].Sup_RealName);
	printf("Origin: ");
	gets(Herooo[i].Sup_Origin);
	printf("Abilities: ");
	gets(Herooo[i].Sup_Abilities);	
	printf("Age: ");
	scanf("%d", &edad);
	
	Herooo[i].Sup_Age = edad;
	
	printf("\n\nPress any key to continue...");
	scanf("%c", &temp);
	getch();
	
	system("CLS");
}

printf("\t\t\t\tSUPERHERO INFORMATION\n\n\n");
for(i=0; i<5; i++)
{
	
	printf("HERO GROUP              : %s\n", Herooo[i].HeroGroup.Sup_Group);
	printf("HERO NAME               : %s\n", Herooo[i].HeroGroup.Sup_Name);
	printf("REAL NAME               : %s\n", Herooo[i].Sup_RealName);
	printf("AGE                     : %d\n", Herooo[i].Sup_Age);
	printf("ORIGIN                  : %s\n", Herooo[i].Sup_Origin);
	printf("ABILITIES               : %s\n", Herooo[i].Sup_Abilities);
	
	printf("\n\n");
}

	getch();

	return 0;		

}
