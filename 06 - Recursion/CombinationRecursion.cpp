/* Combination Recursion
		function: print combinations and combination function
	
	by Allyza Maureen Catura
*/

#include <stdio.h>
#include <conio.h>

void combinationFunction(int arr[],int data[], int startIndex, int endIndex, int index, int numCombination);
void printCombination(int arr[],int n, int numCombination);

int main() {
	int arr[] = {1,2,3,4,5};
	int numCombination = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe combinations are: \n");
	printCombination(arr,n,numCombination);
	getch();
	return 0;
}

// printCombination function 

void printCombination(int arr[],int n, int numCombination) {
	int data[numCombination];
	combinationFunction(arr, data, 0, n-1, 0, numCombination);
}

// combinationFunction 

void combinationFunction(int arr[], int data[], int startIndex, int endIndex, int index, int numCombination) {
	int i, j;
	if(index==numCombination) {
		printf("\t");
		for(j=0; j<numCombination;j++)
			printf("%d", data[j]);
		printf("\n");
		return;
	}
		
	for(i=startIndex; i<=endIndex && endIndex-i+1 >= numCombination-index; i++) {
		data[index] = arr[i];
		combinationFunction(arr, data, i+1, endIndex, index+1, numCombination);
	}
}
