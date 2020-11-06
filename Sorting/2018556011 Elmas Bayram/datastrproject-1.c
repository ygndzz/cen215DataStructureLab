#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*ELMAS BAYRAM

 2018556011*/
 
 void printArray(int arr[], int size)
 {
      int i;
      for(i = 0; i < size ; i++)
      printf("%d ",arr[i]);
}
 void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void swapchar(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
 
//Insertion Sort 

void InsertionSort(int arr[], int n) //n:araay's size
{ 
	int i,j,key; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j=i-1; 
		while (j >= 0 && arr[j] > key)
		 { 
			arr[j + 1] = arr[j]; 
			j--; 
		} 
		arr[j + 1] = key; 
	} 
} 

void Insertionchar(char arr[], int n)
{
	int a,b;
	char key;
	for (a=1; a<n; a++)
	{
		key = arr[a];
		b = a-1;
		while(b >= 0 && arr[b] > key)
		{
			arr[b+1] = arr[b];
			b--;
		}
		arr[b+1] = key;
	}
}

//Selection Sort

void SelectionSort(int *p, int size)
{
   int i, j, temp;
   int minIndex;
 
   for (i = 0; i < size - 1; i++) 
   {
     minIndex = i;
      for (j = i + 1; j < size; j++)
         if (p[minIndex] > p[j])
           minIndex = j;
      temp = p[minIndex];
      p[minIndex] = p[i];
      p[i] = temp;
   }
}

void Selectionchar(char arr[], int n) 
{
      int  i, j,minIndex ;
      char temp;
 
 
   for (i = 0; i < n - 1; i++) {
     minIndex= i;
      for (j = i + 1; j < n; j++)
         if (arr[minIndex] > arr[j])
           minIndex = j;
      temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
}
}

//Merge Sort

void merge(int *Arr, int start, int mid, int end)
 {
	
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) 
	{
		if(Arr[i] <= Arr[j])
		 {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid)
	 {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end)
	 {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) 
	{
		Arr[i] = temp[i - start];
	}
}
void mergeSort(int *Arr, int start, int end) 
{

	if(start < end) 
	{
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

 void mergesort(char *Arr, int start, int mid, int end)
  {
	
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) 
	{
		if(Arr[i] <= Arr[j]) 
		{
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid) 
	{
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end)
	 {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) 
	{
		Arr[i] = temp[i - start];
	}
}
void mergesortchar(char *Arr, int start, int end)
 {

	if(start < end) {
		int mid = (start + end) / 2;
		mergesortchar(Arr, start, mid);
		mergesortchar(Arr, mid+1, end);
		mergesort(Arr, start, mid, end);
	}
}

//Bubble sort

void bubbleSort(int arr[], int size)
{
     int temp;
     int i, j;
     for (i=1; i<size; i++)
     {
        for (j=0; j<size-i; j++)
         {
            if(arr[j] > arr[j+1])
             {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
             }
         }
    }
}

void bubblechar(char arr[], int size)
{
     char temp;
     int i, j;
     for (i=1; i<size; i++)
     {
       for (j=0; j<size-i; j++)
       {
          if(arr[j] > arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j+1];
             arr[j+1] = temp;
             }
         }
    }
}

//Quick Sort
void quickSort(int arr[], int left, int right)
{
   int i = left, j = right;
   int tmp;
   int pivot = arr[(left + right) / 2];

   while (i <= j) {
     while (arr[i] < pivot)
       i++;
     while (arr[j] > pivot)
       j--;
     if (i <= j) {
       tmp = arr[i];
       arr[i] = arr[j];
       arr[j] = tmp;
       i++;
       j--;
     }
   };

   if (left < j)
     quickSort(arr, left, j);
   if (i < right)
     quickSort(arr, i, right);
}

void quickchar(char arr[], int left, int right)
{
   int i = left, j = right;
   char tmp;
   int pivot = arr[(left + right) / 2];

   while (i <= j) {
     while (arr[i] < pivot)
       i++;
     while (arr[j] > pivot)
       j--;
     if (i <= j) {
       tmp = arr[i];
       arr[i] = arr[j];
       arr[j] = tmp;
       i++;
       j--;
     }
   };

   if (left < j)
     quickchar(arr, left, j);
   if (i < right)
     quickchar(arr, i, right);
}


//Heap Sort
void heapify(int arr[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

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
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    for (j=n-1; j>0; j--) { 
        swap(&arr[0], &arr[j]); 
        heapify(arr, j, 0); 
    } 
} 

void heapifychar(char arr[], int n, int i) { 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    if (largest != i) { 
        swapchar(&arr[i], &arr[largest]); 
        heapifychar(arr, n, largest); 
    } 
} 

void heapchar(char arr[], int n) { 
    int i,j;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapifychar(arr, n, i); 

    for (j=n-1; j>0; j--) { 
        swapchar(&arr[0], &arr[j]); 
        heapifychar(arr, j, 0); 
    } 
} 
    int main(){
   	printf("cen-215 Data Dtructures Lab Project-1 \n");
     printf("\n Unsorted number:2018556011");
     printf("\n Unsorted name:ELMAS BAYRAM\n");
    
     
 	  //InsertionSort
 	    clock_t t;
 	  int arr[] = {2,0,1,8,5,5,6,0,1,1};
 	  char name[] = "ELMAS BAYRAM";	  
      int n = sizeof(arr)/sizeof(arr[0]);
      int charS = strlen(name);
      
       t = clock();
       InsertionSort(arr, n);
       t = clock() - t;
       printf("\nSorted numbers in InsertionSort:");
         printArray(arr,n);


      printf("\nRunning time of Insertion Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
     
      Insertionchar(name,charS);
      t = clock()-t;
      printf("Sorted name in Insertion Sort : %s\n",name);
      printf("Running time of Insertion Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //SelectionSort
      
      int arr1[] = {2,0,1,8,5,5,6,0,1,1};
      int n1 = sizeof(arr1)/sizeof(arr1[0]);
      char name1[] = "ELMAS BAYRAM";
      int charS1 = strlen(name1);
      
      SelectionSort(arr1, n1);
      t =clock()-t;
      printf("\nSorted numbers in Selection Sort:");
      printArray(arr1,n1);
      printf("\nRunning time of Selection Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      Selectionchar(name1,charS1);
      t =clock()-t;
      printf("Sorted name in Selection Sort : %s\n",name1);
      printf("Running time of Selection Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //MergeSort
      
      int arr2[] = {2,0,1,8,5,5,6,0,1,1};
      int n2 = sizeof(arr2)/sizeof(arr2[0]);
      char name2[] = "ELMAS BAYRAM";
      int charS2 = strlen(name2);
    
      mergeSort(arr2,0, n2-1);
      t = clock()-t;
      printf("\nSorted numbers in Merge Sort:");
      printArray(arr2,n2);
      printf("\nRunning time of Merge Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      mergesortchar(name2,0,charS2-1);
      t = clock()-t;
      printf("Sorted name in Merge Sort : %s\n",name2);
      printf("Running time of Merge Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //BubbleSort
      
      int arr3[] = {2,0,1,8,5,5,6,0,1,1};
      int n3 = sizeof(arr3)/sizeof(arr3[0]);
      char name3[] = "ELMAS BAYRAM";
      int charS3 = strlen(name3);
    
      bubbleSort(arr3, n3);
      t = clock()-t;
      printf("\nSorted numbers in Bubble Sort:");
      printArray(arr3,n3);
      printf("\nRunning time of Bubble Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      bubblechar(name3,charS3);
      t = clock()-t;
      printf("Sorted name in Bubble Sort : %s\n",name3);
      printf("Running time of Bubble Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
        //Quick Sort
      int arr4[] = {2,0,1,8,5,5,6,0,1,1};
      int n4 = sizeof(arr4)/sizeof(arr4[0]);
      char name4[] = "ELMAS BAYRAM";
      int charS4 = strlen(name4);
    
      quickSort(arr4,0, n4-1);
      t = clock()-t;
      printf("\nSorted numbers in Quick Sort:");
      printArray(arr4,n4);
      printf("\nRunning time of Quick Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      quickchar(name4,0,charS4-1);
      t = clock()-t;
      printf("Sorted name in Quick Sort : %s\n",name4);
      printf("Running time of Quick Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //Heap Sort
       int arr5[] = {2,0,1,8,5,5,6,0,1,1};
      int n5 = sizeof(arr5)/sizeof(arr5[0]);
      char name5[] = "ELMAS BAYRAM";
      int charS5 = strlen(name5);
    
      heapSort(arr5, n5);
      t = clock()-t;
      printf("\nSorted numbers in Heap Sort:");
      printArray(arr5,n5);
      printf("\nRunning time of Heap Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      heapchar(name5,charS5);
      t = clock()-t;
      printf("Sorted name in Heap Sort : %s\n",name5);
      printf("Running time of Heap Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      
      
      
      
      return 0;
 }
