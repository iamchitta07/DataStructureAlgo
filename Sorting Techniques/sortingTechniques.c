#include "functions.h"
#include "stdio.h"
#include "stdlib.h"


int main() {
    int n;
    printf("Enter Size of The Array: ");
    scanf("%d", &n);
    int* arr = input(n);
    display(arr, n);
    radixSort(arr, n);
    display(arr, n);


    free(arr);
    arr = NULL;
    return 0;
}
