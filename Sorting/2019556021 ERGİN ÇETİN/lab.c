#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Integer array with insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Char array with insertion sort

void insertionSortChar(char arr[], int n)
{
    int i, j;
    char key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//integer type array with selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

//Char array with selection sort
void selectionSortChar(char arr[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swapChar(&arr[min], &arr[i]);
    }
}

//bubble sort for integers
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//bubble sort for chars
void bubbleSortChar(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}

// Merge sort algorithm
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortChar(char arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);

        mergeChar(arr, l, m, r);
    }
}

int main()
{
    
    printf("NAME: ERGİN CETİN, SCHOOL ID: 2019556021\n\n");
    int schoolid[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name[] = "Ergin Cetin";
    int numSize = sizeof(schoolid) / sizeof(schoolid[0]);
    int nameSize = strlen(name);
    clock_t start, end;
    double totaltime;

    //time computations for insertion sort. 

    start = clock();
    insertionSort(schoolid, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion sort for number array : ");
    printArray(schoolid, numSize);
    printf("Time for insertion sort integer array => %f", totaltime);
    
    start = clock();
    insertionSortChar(name, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion sort for name array : ");
    printf("%s", name);
    printf("\nTime for insertion sort char array => %f\n", totaltime);
    printf("............................................");
    //time computations for selection sort

    int schoolid2[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name2[] = "Ergin Cetin";

    start = clock();
    selectionSort(schoolid2, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort for number array : ");
    printArray(schoolid2, numSize);
    printf("Time for selection sort with int array => %f", totaltime);

    start = clock();
    selectionSortChar(name2, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort for name array : ");
    printf("%s", name2);
    printf("\nTime for selection sort with char array => %f\n", totaltime);

    printf(".........................................");
    //time computations for bubble sort
    int schoolid3[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name3[] = "Ergin Cetin";

    start = clock();
    bubbleSort(schoolid3, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble sort for number array : ");
    printArray(schoolid3, numSize);
    printf("Time for bubble sort with int array => %f\n", totaltime);

    start = clock();
    bubbleSortChar(name3, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble sort for name array : ");
    printf("%s\n", name3);
    printf("Time for bubble sort with char array => %f\n", totaltime);
    printf(".......................................");
    //time computations for merge sort
    int schoolid4[] = { 2,0,1,9,5,5,6,0,2,1};
    char name4[] = "Ergin Cetin";

    start = clock();
    mergeSort(schoolid4, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort for int array : ");
    printArray(schoolid4, numSize);
    printf("Time for merge sort with int array => %f", totaltime);

    start = clock();
    mergeSortChar(name4, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort for name array : ");
    printf("%s", name4);
    printf("\nTime for merge sort with char array => %f", totaltime);

    return 0;
}