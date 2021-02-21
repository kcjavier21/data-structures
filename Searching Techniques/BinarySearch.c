#include <stdio.h>
#include <windows.h>

int binarySearch(int arr[], int low, int high, int target);

int main() {
    int arr[] = {1, 4, 7, 10, 15, 17, 19, 25, 27, 31, 34, 36, 37, 39, 44, 45, 50, 60, 66, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    system("CLS");

    printf("Enter target number: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, size - 1, target);

    (result == -1) ? printf("\nElement is not present in array!\n") 
    : printf("\nElement is present at index %d!\n", result);

    return 0;
}

int binarySearch(int arr[], int low, int high, int target) {

    if (high >= low) {
        int mid = low + (high - low) / 2;
        
        printf("\nLOWEST: %d", low);
        printf("\nMIDDLE: %d", mid);
        printf("\nHIGHEST: %d\n", high);
        
    
        if (arr[mid] == target) {
            printf("\n >>> %d is equal to %d\n\n", arr[mid], target);
            return mid;
        }
        
        if (arr[mid] > target) {
            printf("\n >>> %d is greater than %d\n\n", arr[mid], target);
            return binarySearch(arr, low, mid - 1, target);
        }

        if (arr[mid] < target) {
            printf("\n >>> %d is less than %d\n\n", arr[mid], target);
            return binarySearch(arr, mid + 1, high, target);
        }
}

return -1;
} 