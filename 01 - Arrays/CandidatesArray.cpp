#include<stdio.h>
#include<string.h>

int main() {

	int arr[4][5];
	int i, j;
	float candiA, candiB, candiC, candiD, totalVotes;
	float ratioA, ratioB, ratioC, ratioD, highest=0, secHighest=0;
	char candidate = 'A';
	char first[20], sec[20];
	
	// ===== INSERT VOTES =======
	
	for(i=0; i<4; i++){
		printf("Insert number of votes for candidate %c \n", candidate);

		for(j=0; j<5; j++){
			printf("Precinct %d: ", j+1);
			scanf("%d", &arr[i][j]);
		}
		candidate++;
	}
	
	candiA = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3] + arr[0][4];  
	candiB = arr[1][0] + arr[1][1] + arr[1][2] + arr[1][3] + arr[1][4];  
	candiC = arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3] + arr[2][4];
	candiD = arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3] + arr[3][4];  
	
	totalVotes = candiA + candiB + candiC + candiD;
	
	ratioA = candiA / totalVotes;
	ratioB = candiB / totalVotes;
	ratioC = candiC / totalVotes;
	ratioD = candiD / totalVotes;
	
	printf("\n======================================\n\n");
	
	// =========== TABLE of VOTES =============
	
	
	printf("Precincts\tCandidate A\tCandidate B\tCandidate C\tCandidate D");
	printf("\n1\t\t%d\t\t%d\t\t%d\t\t%d", arr[0][0], arr[1][0], arr[2][0], arr[3][0]);
	printf("\n2\t\t%d\t\t%d\t\t%d\t\t%d", arr[0][1], arr[1][1], arr[2][1], arr[3][1]);
	printf("\n3\t\t%d\t\t%d\t\t%d\t\t%d", arr[0][2], arr[1][2], arr[2][2], arr[3][2]);
	printf("\n4\t\t%d\t\t%d\t\t%d\t\t%d", arr[0][3], arr[1][3], arr[2][3], arr[3][3]);
	printf("\n5\t\t%d\t\t%d\t\t%d\t\t%d", arr[0][4], arr[1][4], arr[2][4], arr[3][4]);
	
	
	
	printf("\n\n========== TOTAL VOTES ==========\n");
	printf("\nCandidate A : %0.0f", candiA);
	printf("\nCandidate B : %0.0f", candiB);
	printf("\nCandidate C : %0.0f", candiC);
	printf("\nCandidate D : %0.0f", candiD);
	printf("\nTotal Votes : %0.0f", totalVotes);
	printf("\n\n");
	
	
	
	// ========== CHECK if someone had 50% of total votes ===========
	if(ratioA >= 0.50) {
		printf("\nCandidate A is the winner!");
	} else if (ratioB >= 0.50){
		printf("\nCandidate B is the winner!");
	} else if (ratioC >= 0.50){
		printf("\nCandidate C is the winner!");
	} else if (ratioD >= 0.50){
		printf("\nCandidate D is the winner!");
	} else {
		printf("\nNo candidate exceeds 50 percent of the total votes.");
		
		// ==== BATTLE for the FIRST ======
		
		if(ratioA > highest) {
			highest = ratioA;
			strcpy(first, "Candidate A");
		}
		
		if(ratioB > highest) {
			highest = ratioB;
			strcpy(first, "Candidate B");
		}
	
		if(ratioC > highest) {
			highest = ratioC;
			strcpy(first, "Candidate C");
		}
		
		if (ratioD > highest) {
			highest = ratioD;
			strcpy(first, "Candidate D");
		}
		
			
		 // ==== BATTLE for the SECOND ======
		
		if((ratioA > secHighest) && (ratioA < highest)) {
			secHighest = ratioA;
			strcpy(sec, "Candidate A");
		}
			
		if((ratioB > secHighest) && (ratioB < highest)) {
			secHighest = ratioB;
			strcpy(sec, "Candidate B");
		} 
		
		if((ratioC > secHighest) && (ratioC < highest)) {
			secHighest = ratioC;
			strcpy(sec, "Candidate C");
		} 
		
		if ((ratioD > secHighest) && (ratioD < highest)) {
			secHighest = ratioD;
			strcpy(sec, "Candidate D");
		} 
		
		printf("\n\n\nFIRST : %s", first);
		printf("\nSECOND : %s", sec);
	}
	
	
	return 0;
}
