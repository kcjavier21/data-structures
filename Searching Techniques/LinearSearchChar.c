#include <stdio.h>
#include <windows.h>

int linearSearch(char str[], int target, int size);

int main() {
    char str[10] = "SCRIPT";
    int size = strlen(str);
    char target;

    system("CLS");

    printf("Enter target character: ");
    scanf("%c", &target);
    int result = linearSearch(str, target, size);

    (result == -1) ? printf("\nThe element is not present in the array\n")
        : printf("\nThe element is present at index %d\n", result);

    return 0;
}

int linearSearch(char str[], int target, int size) {
    int i;
    printf("\nTARGET: %c\n", target);
    printf("SIZE: %d\n\n", size);

    for(i=0; i<size; i++) {
        printf("ARR[%d]: %c\n", i, str[i]);

        if (target == str[i]) 
            return i;
    }

    return -1;
}