#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper Function Declerations
void print_number_array(int *arr, int len);
void swap(int *xp, int *yp);

// Insertion Sort Function Declerations
int *sort_num_with_insertion_sort(int num_arr[], int size);
char *sort_name_with_insertion_sort(char name_arr[], int size);

// Selection Sort Function Declerations
int *sort_num_with_selection_sort(int num_arr[], int size);
char *sort_name_with_selection_sort(char name_arr[], int size);

// Buble Sort Function Declerations
int *sort_num_with_bubble_sort(int num_arr[], int size);
char *sort_name_with_bubble_sort(char name_arr[], int size);

// Merge Sort Function Declerations
void merge_num(int *arr, int l, int m, int r);
void sort_num_with_merge_sort(int *num_arr, int left, int right);
void merge_name(char *arr, int l, int m, int r);
void sort_name_with_merge_sort(char *name_arr	, int left, int right);

/*
 *				MAIN FUNCTION
 * */
int main(void)
{
	int stdnum[] = {2,0,1,5,5,5,5,0,3,7};	// Student Number
	char stdname[] = "Ahmet Ilhan";    // Student Name

	int numsize = sizeof(stdnum) / sizeof(stdnum[0]);     // Length of the student number
	int namesize = sizeof(stdname) / sizeof(stdname[0]);  // Length of the student name

	printf("Student Name: %s, \tStudent Number: ", stdname);     // Print student name and number
	int i;
	for(i=0; i<numsize; i++)
		printf("%d ", stdnum[i]);
	printf("\n");

	int  *arr_num;	 // Temporary array to hold sorted number array
	char *arr_name;  // Temporary array to hold sorted name array
	clock_t timer;   // Timer variable for performance test

	/* Insertion Sort */
	printf("\nInsertion Sort (Number):\n");
	timer = clock();	        // initial value of the timer
	arr_num = sort_num_with_insertion_sort(stdnum, numsize);
	timer = clock() - timer;	// Get the time interval between previous and current timer values
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);//CLOCKS_PER_SEC);
	printf(">> Sorted: ");
	print_number_array(arr_num, numsize);
	printf("\n");
	
	printf("\nInsertion Sort (Name):\n");
	timer = clock();
	arr_name = sort_name_with_insertion_sort(stdname, namesize);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: %s\n", arr_name);

	/* Selection Sort */
	printf("\nSelection Sort (Number):\n");
	timer = clock();		// Start time of the soting
	arr_num = sort_num_with_selection_sort(stdnum, numsize);
	timer = clock() - timer;        // Time interval
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: ");
	print_number_array(arr_num, numsize);
	printf("\n");

	printf("\nSelection Sort (Name):\n");
	timer = clock();
	arr_name = sort_name_with_selection_sort(stdname, namesize);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: %s\n", arr_name);

	/* Bubble Sort */
	printf("\nBubble Sort (Number):\n");
	timer = clock();
	arr_num = sort_num_with_bubble_sort(stdnum, numsize);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: ");
	print_number_array(arr_num, numsize);
	printf("\n");

	printf("\nBubble Sort (Name):\n");
	timer = clock();
	arr_name = sort_name_with_bubble_sort(stdname, namesize);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: %s\n", arr_name);

	/* Merge Sort */
	int *temp_num = stdnum;
	char *temp_name = stdname;
	
	printf("\nMerge Sort (Number):\n");
	timer = clock();
	sort_num_with_merge_sort(stdnum, 0, numsize-1);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: ");
	print_number_array(temp_num, numsize);
	printf("\n");

	printf("\nMerge Sort (Name):\n");
	timer = clock();
	sort_name_with_merge_sort(stdname, 0, namesize-1);
	timer = clock() - timer;
	printf(">> Time passed: %f\n", ((double)timer) / CLOCKS_PER_SEC);
	printf(">> Sorted: %s\n", temp_name);

	return EXIT_SUCCESS;
}


/*          Helper Functions          */
void print_number_array(int *arr, int len)
{
	int i;
	for(i=0; i<len; i++)
		printf("%d ", arr[i]);
	
	return;
}

void swap_num(int *xp, int *yp)
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void swap_name(char *xp, char *yp)
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

/*      Insertion Sort Functions       */

int *sort_num_with_insertion_sort(int num_arr[], int size)
{
	int *temp; // Temporary array to preserve original array
	temp = num_arr;
	
	int i, key, j; 
    	for (i = 1; i < size; i++) { 
        	key = temp[i]; 
        	j = i - 1; 
        	while (j >= 0 && temp[j] > key) { 
            		temp[j + 1] = temp[j]; 
            		j = j - 1; 
        	} 
        	temp[j + 1] = key; 
    	}
    	return temp;
}

char *sort_name_with_insertion_sort(char name_arr[], int size)
{
	char *temp; // Temporary array to preserve original array
	temp = name_arr;

	int i, key, j; 
    for (i = 1; i < size; i++) { 
    	key = temp[i];
    	j = i - 1; 
    	while (j >= 0 && temp[j] > key) { 
        		temp[j + 1] = temp[j]; 
        		j = j - 1;
    	}
    	temp[j + 1] = key;
    }
    return temp;


	return temp;
}

/*    Selection Sort Functions     */

int *sort_num_with_selection_sort(int num_arr[], int size)
{
	int *temp;
	temp = num_arr;
	
	int i, j, min_idx; 
  
    	// One by one move boundary of unsorted subarray 
    	for (i = 0; i < size-1; i++) 
    	{ 
        	// Find the minimum element in unsorted array 
        	min_idx = i; 
        	for (j = i+1; j < size; j++) 
          		if (temp[j] < temp[min_idx]) 
            	min_idx = j; 
  
        	// Swap the found minimum element with the first element 
        	swap_num(&temp[min_idx], &temp[i]); 
    	}
    	
    	return temp;
}

char *sort_name_with_selection_sort(char name_arr[], int size)
{
	char *temp;
	temp = name_arr;
	
	int i, j, min_idx; 
  
    	// One by one move boundary of unsorted subarray 
    	for (i = 0; i < size-1; i++) 
    	{ 
        	// Find the minimum element in unsorted array 
        	min_idx = i; 
        	for (j = i+1; j < size; j++) 
          		if (temp[j] < temp[min_idx]) 
            	min_idx = j; 
  
        	// Swap the found minimum element with the first element 
        	swap_name(&temp[min_idx], &temp[i]); 
    	}
    	
    	return temp;
}

/*     Bubble Sort Functions      */

int *sort_num_with_bubble_sort(int num_arr[], int size)
{
	int *temp = num_arr;
	int i, j; 
   	for (i = 0; i < size-1; i++)       
       		for (j = 0; j < size-i-1; j++)  
           		if (temp[j] > temp[j+1]) 
              	swap_num(&temp[j], &temp[j+1]); 
	return temp;
}

char *sort_name_with_bubble_sort(char name_arr[], int size)
{
	char *temp = name_arr;
	int i, j; 
   	for (i = 0; i < size-1; i++)       
       		for (j = 0; j < size-i-1; j++)  
           		if (temp[j] > temp[j+1]) 
              	swap_name(&temp[j], &temp[j+1]); 
	return temp;
}

/*     Merge Sort Functions     */

void merge_num(int *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
 
    /* create temp arrays */
    int L[n1], R[n2]; 
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
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

void sort_num_with_merge_sort(int *num_arr, int left, int right)
{
	if (left < right) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = left + (right - left) / 2; 
 
        // Sort first and second halves 
        sort_num_with_merge_sort(num_arr, left, mid); 
        sort_num_with_merge_sort(num_arr, mid + 1, right); 
 
        merge_num(num_arr, left, mid, right); 
    } 
}

void merge_name(char *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
 
    /* create temp arrays */
    int L[n1], R[n2]; 
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
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

void sort_name_with_merge_sort(char *name_arr, int left, int right)
{
	if (left < right) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = left + (right - left) / 2; 
 
        // Sort first and second halves 
        sort_name_with_merge_sort(name_arr, left, mid); 
        sort_name_with_merge_sort(name_arr, mid + 1, right); 
 
        merge_name(name_arr, left, mid, right); 
    } 
}
