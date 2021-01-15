#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

struct Candidates {
	char name[10];
	float precincts[5];
	float totalVotes;
	float percentage;
};


int main() {
    FILE *CandidateFile;
	struct Candidates president[4], tempRec;
	
	float allVotes = 0, tempTotalVotes = 0, highest=0, secHighest=0;
	int i=0, j=0;
	float tempPercentage;
	char temp, FName[15];
	char first[10], sec[10];
	
    system("CLS");
	printf("Enter candidates's details!\n\n");
	
	for(i=0; i<4; i++) {
		printf("Enter Name: ");
		gets(president[i].name);
		
		printf("Enter votes per precinct: \n\n");
			
			for(j=0; j<5; j++) {
				printf("Precinct %d : ", j+1);
				scanf("%f", &president[i].precincts[j]);
				
				tempTotalVotes += president[i].precincts[j];
				president[i].totalVotes = tempTotalVotes;
				
				allVotes += president[i].precincts[j];
			}
		
		tempTotalVotes = 0;
		
		printf("\n\nPress any key to continue...");
		scanf("%c", &temp);
		getch();
	
		system("CLS");
	}
	
	for(i=0; i<4; i++) {	
		tempPercentage = (president[i].totalVotes / allVotes) * 100;
		president[i].percentage = tempPercentage;	

	}
    printf("\n\nEnter Filename where records will be saved => ");
	gets(FName);
	printf("\n\nSaving of Records being process...");

    CandidateFile = fopen(FName, "w");

    for(i=0; i<4; i++) {
        tempRec = president[i];
        fwrite(&tempRec, sizeof(tempRec), 1, CandidateFile);
    }

    fclose(CandidateFile);

    printf("Saving of Records Completed!!!\n\n");
	printf("Press Any Key To Exit...");
	getch();
	return (0);

}


