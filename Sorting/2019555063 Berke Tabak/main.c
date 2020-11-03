#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void swap(int *p1, int *p2) 
{ 
    int gecici = *p1; 
    *p1 = *p2; 
    *p2 = gecici; 
} 

void swapCh(char *p1, char *p2) 
{ 
    char gecici = *p1; 
    *p1 = *p2; 
    *p2 = gecici; 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k, a1, a2; 
    a1 = m - l + 1; 
    a2 = r - m; 

    int L[a1], R[a2]; 

    for (i = 0; i < a1; i++) 
        L[i] = arr[l + i]; 
        
        
    for (j = 0; j < a2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0 ; j = 0 ; k = l;
   

    while (i < a1 && j < a2) { 
    
        if (L[i] <= R[j]) 
		{ 
            arr[k] = L[i]; 
            i++; 
        } 
        
		else 
		{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < a1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < a2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergesorting(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergesorting(arr, l, m); 
        mergesorting(arr, m + 1, r); 

        merge(arr, l, m, r); 
    } 
} 

void mergechar(char arr[], int l, int m, int r) 
{ 
    int i, j, k, x1, x2; 
    x1 = m - l + 1; 
    x2 = r - m; 

    int L[x1], R[x2]; 

    for (i = 0; i < x1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < x2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < x1 && j < x2) { 
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

    while (i < x1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < x2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergesortingchar(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergesortingchar(arr, l, m); 
        mergesortingchar(arr, m + 1, r); 

        mergechar(arr, l, m, r); 
    } 
}

void selectionsorting(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionsortingchar(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapCh(&arr[min], &arr[i]); 
    } 
}

void insertionsorting(int arr[], int a) 
{ 
    int i, x, j; 
    
    for (i = 1; i < a; i++) 
	{ 
        x = arr[i]; 
        j = i - 1;
		 
        while (j >= 0 && arr[j] > x) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = x; 
    } 
} 

void insertionsortingchar(char arr[], int n) 
{
	char x;
    int i, j;
    for(i = 1; i < n; i++) {
        x = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}

void bubblesorting(int arr[], int n) 
{ 
   int i, j,gecici; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) {
		    /*    gecici = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = gecici;   */
              swap(&arr[j], &arr[j+1]); 
         }
} 

void bubblesortingchar(char arr[], int n) 
{ 
   int i, j,gecici; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              {
              swapCh(&arr[j] , &arr[j+1]); 
         } 
}

//quick sort 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);

        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

char partitionChar(char arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swapCh(&arr[i], &arr[j]);
        }
    }
    swapCh(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int part = partitionChar(arr, low, high);

        quickSortChar(arr, low, part - 1);
        quickSortChar(arr, part + 1, high);
    }
}

//heap sort

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swap(&arr[0], &arr[j]);
        heapify(arr, j, 0);
    }
}

void heapifyChar(char arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swapCh(&arr[i], &arr[largest]);
        heapifyChar(arr, n, largest);
    }
}

void heapSortChar(char arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifyChar(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swapCh(&arr[0], &arr[j]);
        heapifyChar(arr, j, 0);
    }
}



void printArray(int arr[], int n) 
{ 
    int i; 
    printf("Sorted number:");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); } 


int main() {
    
	clock_t t;
	
    printf("Berke Tabak-2019555063\n\n");
    
    int idnumber[] = {2,0,1,9,5,5,5,0,6,3}; 
    char stname[] = "berke tabak"; 
    int a = sizeof(idnumber) / sizeof(idnumber[0]); 
    int charsize = strlen(stname);

    t = clock();
    
    // Insertion sorting part
    
    insertionsorting(idnumber, a);
    t = clock() - t;
    printArray(idnumber, a); 
    printf("insertion sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");
    
    insertionsortingchar(stname, charsize);
    t = clock() - t;
    printf("Sorted name:%s\n", stname);
    printf("insertion char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    // Selection sorting part

    int idnumber1[] = {2,0,1,9,5,5,5,0,6,3};
    char stname1[] = "berke tabak";
    int b = sizeof(idnumber1) / sizeof(idnumber1[0]); 
    int charsize1 = strlen(stname1);
    
    selectionsorting(idnumber1,b);
    t = clock() - t;
    printArray(idnumber1,b); 
    printf("selection sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    selectionsortingchar(stname1, charsize1);
    t = clock() - t;
    printf("Sorted name:%s\n", stname1);
    printf("selection char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    // Bubble sorting part
    

    int idnumber2[] = {2,0,1,9,5,5,5,0,6,3};
    char stname2[] = "berke tabak"; 
    int c = sizeof(idnumber2) / sizeof(idnumber2[0]); 
    int charsize2 = strlen(stname2);

    bubblesorting(idnumber2,c);
    t = clock() - t;
    printArray(idnumber2,c); 
    printf("bubble sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    bubblesortingchar(stname2, charsize2);
    t = clock() - t;
    printf("Sorted name:%s\n", stname2);
    printf("bubble char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");


    // Merge sorting part
    
    
    int idnumber3[] = {2,0,1,9,5,5,5,0,6,3}; 
    char stname3[] = "berke tabak"; 
    int d = sizeof(idnumber3) / sizeof(idnumber3[0]); 
    int charsize3 = strlen(stname3);

    mergesorting(idnumber3, 0, d - 1);
    t = clock() - t;
    printArray(idnumber3, d); 
    printf("merge sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");
    
    mergesortingchar(stname3, 0, charsize3 - 1);
    t = clock() - t;
    printf("Sorted name:%s\n", stname3);
    printf("merge char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    // Quick sorting part


    int idnumber4[] = {2,0,1,9,5,5,5,0,6,3}; 

    char stname4[] = "berke tabak"; 
    int e = sizeof(idnumber4) / sizeof(idnumber4[0]);
    int charsize4 = strlen(stname4);

    quickSort(idnumber4, 0, e - 1);
    t = clock() - t;
    printArray(idnumber4, e);
    printf("quick sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");
    quickSortChar(stname4, 0, charsize4 - 1);
    t = clock() - t;
    printf("%s\n", stname4);
    printf("quick char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");


    //Heap sorting part


    int idnumber5[] = {2,0,1,9,5,5,5,0,6,3}; 

    char stname5[] = "berke tabak"; 
    int f = sizeof(idnumber5) / sizeof(idnumber5[0]);
    int charsize5 = strlen(stname5);

    heapSort(idnumber5, f);
    t = clock() - t;
    printArray(idnumber5, f);
    printf("heap sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");
    heapSortChar(stname5, charsize5);
    t = clock() - t;
    printf("%s\n", stname5);
    printf("heap char sorting time: %.4lf\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\n");

    return 0;
} 
