#include "functions.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"

// Max and Min Function
int minn(int a, int b) {
    return a<b ? a : b;
}

int maxx(int a, int b) {
    return a>b ? a : b;
}

// Swapping Function
void swap(int* a, int* b) {
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

// Bubble Sort
void bubbleSort(int* arr, int n) {
    for(int i=1;i<n;i++) {
        bool flag = true;
        for(int j=0;j<n-i;j++) {
            if(*(arr+j)>*(arr+j+1)) {
                swap(arr+j, arr+j+1);
                flag = false;
            }
        } if(flag) break;
    }
}

// Selection Sort
void selectionSort(int* arr, int n) {
    for(int i=0;i<n-1;i++) {
        int minEle = *(arr+i);
        int idx = i;
        for(int j=i+1;j<n;j++) {
            if(minEle>*(arr+j)) {
                minEle = *(arr+j);
                idx = j;
            }
        } if(idx!=i) swap(arr+i, arr+idx);
    }
}

// Insertion Sort
void insertionSort(int* arr, int n) {
    for(int i=1;i<n;i++) {
        int j = i;
        while(j>0 && *(arr+j)<*(arr+j-1)) {
            swap(arr+j, arr+j-1);
            j--;
        }
    }
}

// Merge Sort
void mergeTwoArrays(int* a, int n1, int* b, int n2, int* arr) {
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2)
        *(arr+k++) = *(a+i)<*(b+j) ? *(a+ i++) : *(b+ j++);
    while(i<n1)
        *(arr+k++) = *(a+ i++);
    while(j<n2)
        *(arr+k++) = *(b+ j++);
}

void mergeSort(int* arr, int n) {
    if(n<=1) return;
    int n1 = n/2, n2 = n - n1;
    int* a = (int*)malloc(n1*sizeof(int));
    int* b = (int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++)
        *(a+i) = *(arr+i);
    for(int i=0;i<n2;i++)
        *(b+i) = *(arr+i+n1);
    mergeSort(a, n1);
    mergeSort(b, n2);
    mergeTwoArrays(a, n1, b, n2, arr);
    free(a);
    free(b);
    a = NULL;
    b = NULL;
}

// Quick Sort
int partition(int* arr,int si,int ei){
    int pivot = *(arr + (si+ei)/2 );
    int count = 0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(*(arr+i)<=pivot) count++;
    }
    int pivotIdx = count + si;
    swap((arr+(si+ei)/2), (arr+pivotIdx));
    int i = si;
    int j = ei;
    while(i<pivotIdx && j>pivotIdx){
        if(*(arr+i)<=pivot) i++;
        if(*(arr+j)>pivot) j--;
        else if(*(arr+i)>pivot && pivot>=*(arr+j)){
            swap(arr+i,arr+j);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

void helper(int* arr,int si,int ei){
    if(si >= ei) return;
    int pivotIdx = partition(arr, si, ei);
    helper(arr, si, pivotIdx-1);
    helper(arr, pivotIdx+1, ei);
}

void quickSort(int* arr, int n) {
    helper(arr, 0, n-1);
}

// Counting Sort
void countSort(int* arr, int n) {
    int minEle = 0;
    int maxEle = *arr;
    for(int i=0;i<n;i++) {
        if((*(arr+i))<0)
            minEle = minn(minEle, *(arr+i));
        maxEle = maxx(maxEle, *(arr+i));
    }
    minEle = (-1)*minEle;
    maxEle+=minEle;

    for(int i=0;i<n;i++)
        *(arr+i)+=minEle;

    int* helper = (int*)calloc((maxEle+1), sizeof(int));

    for(int i=0;i<n;i++)
        (*(helper + *(arr+i)))+=1;

    for(int i=1;i<=maxEle;i++)
        (*(helper+i)) += (*(helper+i-1));

    int* brr = (int*)calloc(n, sizeof(int));

    for(int i=n-1;i>=0;i--) {
        (*(brr + (*(helper + (*(arr+i))))-1)) = *(arr+i);
        (*(helper + *(arr+i)))--;
    } for(int i=0;i<n;i++)
        *(brr+i) -= minEle;

    for(int i=0;i<n;i++)
        *(arr+i) = *(brr+i);
    free(brr);
    brr = NULL;
    free(helper);
    helper = NULL;
}

// Radix Sort
void radixSort(int* arr, int n) {
    int minEle = 0;
    int maxEle = *arr;
    for(int i=0;i<n;i++) {
        if((*(arr+i))<0)
            minEle = minn(minEle, *(arr+i));
        maxEle = maxx(maxEle, *(arr+i));
    }
    minEle = (-1)*minEle;
    maxEle+=minEle;

    for(int i=0;i<n;i++)
        *(arr+i)+=minEle;

    int itr = (int)(log10(maxEle)) + 1;

    int j=0;
    while(j<itr) {
        int* helper = (int*)calloc(10, sizeof(int));
        for(int i=0;i<n;i++) {
            int digit = (((int)(*(arr+i)) / (int)pow(10, j)) % 10);
            (*(helper+digit))++;
        } int* brr = (int*)calloc(n, sizeof(int));

        for(int i=1;i<=9;i++)
            (*(helper+i)) += (*(helper+i-1));

        for(int i=n-1;i>=0;i--) {
            int digit = (((int)(*(arr+i)) / (int)pow(10, j)) % 10);
            (*(brr + (*(helper + digit))-1)) = *(arr+i);
            (*(helper + digit))--;
        } for(int i=0;i<n;i++)
            *(arr+i) = *(brr+i);
        free(helper);
        helper = NULL;
        free(brr);
        brr = NULL;
        j++;
    } for(int i=0;i<n;i++)
        (*(arr+i)) -= minEle;
}

void display(int* arr, int n) {
    if(!n) {
        printf("Empty Array!!\n");
        return;
    } printf("Elements are: ");
    for(int i=0;i<n;i++) printf("%d ", *(arr+i));
    printf("\n");
}

void display2(int* arr, int n, int num) {
    if(!n) {
        printf("Empty Array!!\n");
        return;
    } printf("Elements are: ");
    for(int i=0;i<n;i++) printf("%d ", *(arr+i)-num);
    printf("\n");
}

int* input(int n) {
    printf("Enter Elements of The Array: ");
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", (arr+i));
    return arr;
}
