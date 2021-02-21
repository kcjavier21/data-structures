#include <stdio.h>
#include <windows.h>

int binarySearch(int arr[], int low, int high, int target);

int main() {
    int arr[] = { 1, 4, 7, 10, 15 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    system("CLS");

    printf("Enter target number: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, size - 1, target);

    (result == -1) ? printf("\nElement is not present in array\n")
    : printf("\nElement is present at index %d\n", result);

    return 0;
}

int binarySearch(int arr[], int low, int high, int target) {
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        printf("\nLOWEST: %d", low);
        printf("\nMIDDLE: %d", mid);
        printf("\nHIGHEST: %d\n", high);

        if (arr[mid] == target) {
            printf("\n >>> %d is equal to %d\n\n", arr[mid], target);
            return mid;
        } else if (arr[mid] < target) {
            printf("\n >>> %d is less than %d\n\n", arr[mid], target);
            low = mid + 1;
        } else {
            printf("\n >>> %d is greater than %d\n\n", arr[mid], target);
            high = mid - 1; 
        }
    }

return -1;
}
