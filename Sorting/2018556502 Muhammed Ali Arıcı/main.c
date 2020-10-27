#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

//Insertion Sort
void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Insertion Sort for Char
void InsertionSortChar(char arr[], int n)
{
    int i, j;
    char key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Swaps
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Selection Sort 
void SelectionSort(int arr[], int n)
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

// Selection Sort for Char
void SelectionSortChar(char arr[], int n)
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

// Bubble Sort
void BubbleSort(int arr[], int size)
{
    int temp;
    int i, j;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort for Char
void BubbleSortChar(char arr[], int size)
{
    char temp;
    int i, j;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort
void Merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
        
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }
        
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeForChar(char arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

void MergeSortChar(char arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSortChar(arr, l, m);
        MergeSortChar(arr, m + 1, r);
        MergeForChar(arr, l, m, r);
    }
}

int main() {
    
    clock_t time;
    printf("Unsorted No: 2018556502\n");
    printf("Unsorted Name: muhammed ali arici\n\n");

    // Insertion Sorts
    int No[] = {2, 0, 1, 8, 5, 5, 6, 5, 0, 2};
    int No_size = sizeof(No) / sizeof(No[0]);
    char Name[] = "muhammed ali arici";
    int charSize = strlen(Name);

    time = clock();
    InsertionSort(No, No_size);
    time = clock() - time;
    printf("Sorted No: ");
    printArray(No, No_size);
    printf("\n");
    printf("Insertion sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    InsertionSortChar(Name, charSize);
    time = clock() - time;
    printf("Sorted Name:");
    printf("%s\n", Name);
    printf("Insertion char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("\n\n");
    
    // Selection Sorts
    int No_2[] = {2, 0, 1, 8, 5, 5, 6, 5, 0, 2};
    int No_size_2 = sizeof(No) / sizeof(No[0]);
    char Name_2[] = "muhammed ali arici";
    int charSize_2 = strlen(Name);

    time = clock();
    SelectionSort(No_2, No_size_2);
    time = clock() - time;
    printf("Sorted No: ");
    printArray(No_2, No_size_2);
    printf("\n");
    printf("Selection sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    SelectionSortChar(Name_2, charSize_2);
    time = clock() - time;
    printf("Sorted Name:");
    printf("%s\n", Name_2);
    printf("Selection char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("\n\n");

    // Bubble Sorts
    int No_3[] = {2, 0, 1, 8, 5, 5, 6, 5, 0, 2};
    int No_size_3 = sizeof(No) / sizeof(No[0]);
    char Name_3[] = "muhammed ali arici";
    int charSize_3 = strlen(Name);

    time = clock();
    BubbleSort(No_3, No_size_3);
    time = clock() - time;
    printf("Sorted No: ");
    printArray(No_3, No_size_3);
    printf("\n");
    printf("Bubble sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    BubbleSortChar(Name_3, charSize_3);
    time = clock() - time;
    printf("Sorted Name:");
    printf("%s\n", Name_3);
    printf("Bubble char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    printf("\n\n");

    // Merge Sorts
    int No_4[] = {2, 0, 1, 8, 5, 5, 6, 5, 0, 2};
    int No_size_4 = sizeof(No) / sizeof(No[0]);
    char Name_4[] = "muhammed ali arici";
    int charSize_4 = strlen(Name);

    time = clock();
    MergeSort(No_4, 0, No_size_4 - 1);
    time = clock() - time;
    printf("Sorted No: ");
    printArray(No_4, No_size_4);
    printf("\n");
    printf("Merge sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);
    MergeSortChar(Name_4, 0, charSize_4 - 1);
    time = clock() - time;
    printf("Sorted Name:");
    printf("%s\n", Name_4);
    printf("Merge char sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

    return 0;
}