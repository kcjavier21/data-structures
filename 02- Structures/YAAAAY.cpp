#include<stdio.h>
#include<windows.h>
#include<conio.h>

struct ArtistRecord{
	char Name[30];
	char Age[3];
	char Gender[15];
	char Genre[10];
	int Grammy; 
};

int main()
{
	struct ArtistRecord ARTIST;
	int tempgram;
	
	system("CLS");
	
	printf("\t\t\nTHIS PROGRAM RECORDS THE ARTISTS' INFORMATION\n\n");
	printf("NAME: ");
	gets(ARTIST.Name);
	printf("AGE: ");
	gets(ARTIST.Age);
	printf("GENDER: ");
	gets(ARTIST.Gender);
	printf("GENRE: ");
	gets(ARTIST.Genre);
	printf("No. of Grammy Awards received: ");
	scanf("%d", &tempgram);
	
	ARTIST.Grammy = tempgram;
	
	printf("Press any key to continue...");
	getch();
	system("CLS");
	
	printf("\nNAME:                    %s", ARTIST.Name);
	printf("\nAGE:                     %s", ARTIST.Age);
	printf("\nGENDER:                  %s", ARTIST.Gender);
	printf("\nGENRE:                   %s", ARTIST.Genre);
	printf("\nGRAMMY AWARDS RECEIVED:  %d", ARTIST.Grammy);
	
	if(ARTIST.Grammy >= 5)
			printf("\n\nTHIS ARTIST IS AMAZING!");			
		
	else
			printf("\n\nThis artist needs improvement.");
					
			
}

