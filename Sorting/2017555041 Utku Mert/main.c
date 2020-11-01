#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void swapId(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;

}

void swapName(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSortId(int arr[], int size) {
    int i, j, k;
    for (i = 0; i < size - 1; ++i) {
        k = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[k])
                k = j;
        }
        swapId(&arr[k], &arr[i]);
    }

}

void selectionSortName(char arr[], int size) {
    int i, j, k;
    for (i = 0; i < size - 1; ++i) {
        k = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[k])
                k = j;
        }
        swapName(&arr[k], &arr[i]);
    }

}

void insertionSortId(int arr[], int size) {
    int i, j, k;
    for (i = 1; i < size; i++) {
        k = arr[i];
        for (j = i - 1; j >= 0 && arr[j] >= k; j--) {
            arr[j + 1] = arr[j];
        }
        k = arr[j + 1];
    }

}

void insertionSortName(char arr[], int size) {
    int i, j, k;
    for (i = 1; i < size; i++) {
        k = arr[i];
        for (j = i - 1; j >= 0 && arr[j] >= k; j--) {
            arr[j + 1] = arr[j];
        }
        k = arr[j + 1];

    }
}

void bubbleSortId(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapId(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortName(char arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapName(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void mergeId(int arr[], int left, int mid, int right)
{
    int i, j, l = 0;
    int array[15];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        }
        else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }
    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }
    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }

}

void mergeName(char arr[], int left, int mid, int right)
{
    int i, j, l = 0;
    char array[20];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        }
        else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }
    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }
    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }

}

void  mergeSortId(int arr[], int left, int right) {
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        mergeSortId(arr, left, mid);
        mergeSortId(arr, mid + 1, right);

        mergeId(arr, left, mid, right);

    }
}

void mergeSortName(char arr[], int left, int right) {
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        mergeSortName(arr, left, mid);
        mergeSortName(arr, mid + 1, right);
        mergeName(arr, left, mid, right);

    }
}

void printSortId(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printSortName(char arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void heap(int num[], int len, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < len && num[l] > num[largest])
    largest = l;

  if (r < len && num[r] > num[largest])
    largest = r;

  if (largest != i)
  {
    swapId(&num[i], &num[largest]);
    heap(num, len, largest);
  }
}

void heapNumber(int num[], int len)
{
  int i, j;
  for (i = len / 2 - 1; i >= 0; i--)
  {
    heap(num, len, i);
  }

  for (j = len - 1; j > 0; j--)
  {
    swapId(&num[0], &num[j]);
    heap(num, j, 0);
  }
}

void heapSName(char name[], int len, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < len && name[l] > name[largest])
    largest = l;

  if (r < len && name[r] > name[largest])
    largest = r;

  if (largest != i)
  {
      swapName(&name[i], &name[largest]);
      heapSName(name, len, largest);
  }
}

void heapName(char name[], int len)
{
  int i, j;
  for (i = len / 2 - 1; i >= 0; i--)
  {
      heapSName(name, len, i);
  }

  for (j = len - 1; j > 0; j--)
  {
      swapName(&name[0], &name[j]);
      heapSName(name, j, 0);
  }
}


int partNumber(int num[], int low, int high)
{	
    int i = (low- 1);
	int j;
	int key = num[high];
	
	for(j=low; j <= high-1; j++)
	{
		if(num[j]< key)
		{
			i++;
			swapId(&num[i], &num[j]);
		}
	}
	swapId(&num[i+1], &num[high]);
	return (i+1);
}
void quickNumber(int arr[], int low, int high)
{
	if(low<high)
	{
		int index = partNumber(arr, low, high);
		quickNumber(arr, low, index-1);
		quickNumber(arr,index+1,high);
	}
}

char partName(char name[], char low, char high)
{	
    int i = (low- 1);
	int j;
	char key = name[high];
	
	for(j=low; j <= high-1; j++)
	{
		if(name[j]< key)
		{
			i++;
			swapName(&name[i], &name[j]);
		}
	}
	swapName(&name[i+1], &name[high]);
	return (i+1);
}
void quickName(char name[], char low, char high)
{
	if(low<high)
	{
		char index = partName(name, low, high);
		quickName(name, low, index-1);
		quickName(name,index+1,high);
	}
}




int main()
{
    int Id[] = { 2,0,1,7,5,5,5,0,4,1 };
    char Name[] = "utku mert";

    int size1 = sizeof(Id) / sizeof(Id[2]);
    int size2 = strlen(Name);

    clock_t t;
    t = clock();

    //Selection Sort
    selectionSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of selection sort Id: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    selectionSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of selection sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Insertion Sort
    insertionSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of insertion sort Id: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    insertionSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of insertion sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Bubble Sort
    bubbleSortId(Id, size1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of bubble sort Id:: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    bubbleSortName(Name, size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of bubble sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Merge Sort
    mergeSortId(Id, 0, size1 - 1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of merge sort Id: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    mergeSortName(Name, 0, size2 - 1);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of merge sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    //Heap Sort
    heapNumber(Id,size2);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of heap sort Id: %f\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    heapName(Name,size2);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of heap sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    //Quick Sort
    quickNumber(Id, 0 ,size1-1);
    t = clock() - t;
    printSortId(Id, size1);
    printf("Time of quick sort Id: %f\n", ((double)(t)) / CLOCKS_PER_SEC);
 
    
    quickName(Name, 0 ,size2-1);
    t = clock() - t;
    printSortName(Name, size2);
    printf("Time of quick sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);


    return 0;
}
