#include <stdio.h>
#include <windows.h>

int linearSearch(int arr[], int target, int size);

int main() {
    int arr[] = { 1, 4, 7, 10, 15, 17, 19, 25, 27, 31, 34, 36, 37, 39, 44, 45, 50, 60, 66, 70 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    system("CLS");

    printf("Enter target number: ");
    scanf("%d", &target);
    int result = linearSearch(arr, target, size);

    (result == -1) ? printf("\nThe element is not present in the array\n")
        : printf("\nThe element is present at index %d\n", result);

    return 0;
}

int linearSearch(int arr[], int target, int size) {
    int i;
    printf("\nTARGET: %d\n", target);
    printf("SIZE: %d\n\n", size);

    for(i=0; i<size; i++) {
        printf("ARR[%d]: %d\n", i, arr[i]);

        if (target == arr[i]) 
            return i;
    }

    return -1;
}