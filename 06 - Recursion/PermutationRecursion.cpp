/* permutation recursion
		function: permute, swap
	
	by Allyza Maureen Catura
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void swap(char *x, char *y);
void permute(char *string, int startIndex, int endIndex);

int main() {
	char string[] = "ABC";
	system("cls");
	int length = strlen(string);
	printf("The permutations for ABC are:\n");
	permute(string, 0, length-1);
	return 0;
}

// swap function

void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// permute function

void permute(char *string, int startIndex, int endIndex) {
	int i;
	if(startIndex==endIndex)
		printf("%s\n", string);
	else {
		for(i = startIndex; i<=endIndex; i++) {
			swap((string+startIndex),(string+i));
			permute(string, startIndex+1, endIndex);
			swap((string+startIndex),(string+i)); // backtracking
		}
	}
}

