#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>


void gotoxy(short x, short y) 
{ 
	COORD pos = {x, y}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}


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
	int i=0;
	float tempPercentage;
	char temp, FName[15];
	char first[10], sec[10];
	
    system("CLS");

    printf("\nEnter Filename where records will be retrieved => ");
    gets(FName);
    printf("\n\nRetrieving records from %s...",FName);

    CandidateFile = fopen(FName,"r");
	

    fread(&tempRec, sizeof(tempRec), 1, CandidateFile);

    while(!feof(CandidateFile)) {
        president[i]=tempRec;
        fread(&tempRec, sizeof(tempRec), 1, CandidateFile);
        i++;
    }

    fclose(CandidateFile);

    printf("%d records retrieved!!!", i);
    printf("\n\nPress Any Key To Continue...");
    getch();

	system("CLS");

	gotoxy(27, 1); printf("TALLY OF VOTE PER PRECINCT");
	
	gotoxy(19,5); printf(president[0].name);
	gotoxy(34,5); printf(president[1].name);
	gotoxy(48,5); printf(president[2].name);
	gotoxy(62,5); printf(president[3].name);
	
	gotoxy(5,5); printf("Precincts");

	gotoxy(19,4); printf("Candidate");
	gotoxy(34,4); printf("Candidate");
	gotoxy(48,4); printf("Candidate");
	gotoxy(62,4); printf("Candidate");
	
	gotoxy(5,7); printf("1");
	gotoxy(5,8); printf("2");
	gotoxy(5,9); printf("3");
	gotoxy(5,10); printf("4");
	gotoxy(5,11); printf("5");
	
	
	for(i=0; i<5; i++) {
			gotoxy(19, 7+i); printf("%0.0f", president[0].precincts[i]);
	}
	
	for(i=0; i<5; i++) {
			gotoxy(34, 7+i); printf("%0.0f", president[1].precincts[i]);
	}
	
	for(i=0; i<5; i++) {
			gotoxy(48, 7+i); printf("%0.0f", president[2].precincts[i]);
	}
	
	for(i=0; i<5; i++) {
			gotoxy(62, 7+i); printf("%0.0f", president[3].precincts[i]);
	}
	
	
	if(president[0].percentage >= 50) {
		printf("\n\n%s is the winner!", president[0].name);
	} else if (president[1].percentage >= 50){
		printf("\n\n%s is the winner!", president[1].name);
	} else if (president[2].percentage >= 50){
		printf("\n\n%s is the winner!", president[2].name);
	} else if (president[3].percentage >= 50){
		printf("\n\n%s is the winner!", president[3].name);
	} else {
		printf("\n\n\nNo candidate exceeds 50 percent of the total votes.");

		for(i=0; i < 4; i++) {
			if(president[i].percentage > highest) {
				highest = president[i].percentage;
				strcpy(first, president[i].name);
			}
		}
		
		for(i=0; i < 4; i++) {
			if((president[i].percentage > secHighest) && (president[i].percentage < highest)) {
				secHighest = president[i].percentage;
				strcpy(sec, president[i].name);
			}
		}
		
		printf("\n\nThere's a runoff between %s and %s!!!\n\n", first, sec);
	}
		
	return 0;

}


