#include <stdio.h>
	#include <string.h>
	#include <time.h>

	void swap(int* xp, int* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	void swapname(char* xp, char* yp)
	{
		char temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	
	void insertionname(char name[], int len) { 
	

		int i, key, j;
		for (i = 1; i < len; i++) {
			key = name[i];
			j = i - 1;
	

			while (j >= 0 && name[j] > key) {
				name[j + 1] = name[j];
				j = j - 1;
			}
	

			name[j + 1] = key;
		}
	

	}
	void insertionnumber(int number[], int n)
	{
		int i, key, j;
		for (i = 1; i < n; i++) {
			key = number[i];
			j = i - 1;
	

		
			while (j >= 0 && number[j] > key) {
				number[j + 1] = number[j];
				j = j - 1;
			}
			number[j + 1] = key;
		}
	}
	

	void selectionnumber(int number[], int n)
	{
		int i, j, minIndex;
	

		for (i = 0; i < n - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < n; j++)
				if (number[j] < number[minIndex])
					minIndex = j;
	

			swap(&number[minIndex], &number[i]);
		}
	}
	

	void selectionname(char name[], int len) {
		int i, j, minIndex;
	

		for (i = 0; i < len - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < len; j++)
				if (name[j] < name[minIndex])
					minIndex = j;
	

			swapname(&name[minIndex], &name[i]);
		}
	

	}
	
	void bubblenumber(int arr[], int n)
	{
		int i, j;
		for (i = 0; i < n - 1; i++)
	

			for (j = 0; j < n - i - 1; j++)
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
	}
	void bubblename(char name[], int len)
	{
		int i, j;
		for (i = 0; i < len - 1; i++)
	

			for (j = 0; j < len - i - 1; j++)
				if (name[j] > name[j + 1])
					swapname(&name[j], &name[j + 1]);
	}
	

	void mergenumber(int arr[], int l, int m, int r) 
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
	

	

	void mergesortnumber(int arr[], int l, int r) 
	{ 
		if (l < r) { 
			
			int m = l + (r - l) / 2; 
	

			
			mergesortnumber(arr, l, m); 
			mergesortnumber(arr, m + 1, r); 
	

			mergenumber(arr, l, m, r); 
		} 
	} 
	

	void mergename(char arr[], int l, int m, int r) 
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
	

	void mergesortname(char arr[], int l, int r) 
	{ 
		if (l < r) { 
			
			int m = l + (r - l) / 2; 
	

			
			mergesortname(arr, l, m); 
			mergesortname(arr, m + 1, r); 
	

			mergename(arr, l, m, r); 
		} 
	} 
	

	void printarrayname(char name[], int len)
	{
		int i;
		for (i = 0; i < len; i++)
			printf("%c ", name[i]);
		printf("\n");
	}
	void printarraynumber(int number[], int n)
	{
		int i;
		printf("  ");
		for (i = 0; i < n; i++)
			printf("%d ", number[i]);
		printf("\n");
	}
	

	int main()
	{
		clock_t t;
	

		char name[] = "Emine Nisa Citer";
		int number[] = { 2,0,1,6,5,5,6,0,1,8 };
	

		int len = strlen(name);
		int n = sizeof(number) / sizeof(number[0]);
	

		printf("Ogrencinin Adi: Emine Nisa Citer \n Numarasi: 2016556018\n\n");
		printf("Insertion sort\n");
		t = clock();
	    insertionname(name, len);
	    t = clock() - t;
	    printarrayname(name, len); 
	    printf("Insertion Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		insertionnumber(number, n);	
		t = clock() - t;
		printarraynumber(number, n);
	    printf("Insertion Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	    
		printf("Selection sort\n");
		t = clock();
		selectionname(name, len);
		t = clock() - t;
		printarrayname(name, len);
		printf("Selection Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		selectionnumber(number, n);
		t = clock() - t;
		printarraynumber(number, n);
	    printf("Selection Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	    
	    printf("Merge sort\n");
		t = clock();
		mergesortname(name, 0, len-1);
		t = clock() - t;
		printarrayname(name, len);
		printf("Merge Sort Suresi : %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		mergesortnumber(number, 0, n - 1); 
		t = clock() - t;
		printarraynumber(number, n);
		printf("Merge Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);	

		printf("Bubble sort\n");
		t = clock();
		bubblename(name, len);
		t = clock() - t;
		printarrayname(name, len);
		printf("Bubble Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		bubblenumber(number, n);
		t = clock() - t;
		printarraynumber(number, n);
		printf("Bubble Sort Suresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);


        printf("Quick sort\n");
		t = clock();
		quickName(name, 0, len-1);
		t = clock() - t;
		printArrayName(name, len);
		printf("Quick Sort Süresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		quickNumber(number, 0, n - 1); 
		t = clock() - t;
		printArrayNumber(number, n);
		printf("Quick Sort Süresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

		printf("Heap sort\n");
		t = clock();
		heapName(name, len);
		t = clock() - t;
		printArrayName(name, len);
		printf("Heap Sort Süresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		heapNumber(number, n);
		t = clock() - t;
		printArrayNumber(number, n);
	    printf("Heap Sort Süresi: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
		
	    
		
		return 0;
	    
	}

