#include<stdio.h>
#include<string.h>
#include<time.h>
#include<assert.h>

// insertion sort for int
void insertionsort_int(int arr[],int size){
	int i,k,key;
	for(i=1;i<size;i++){
		key=arr[i];
		for(k=i-1;k>=0&&key<=arr[k];k--){
			arr[k+1]=arr[k];
		}
		arr[k+1]=key;
	}
}
// insertion sort for char
void insertionsort_char(char arr[],int size){
	int i,k;
	char key;
	for(i=0;i<size;i++){
		key=arr[i];
		for(k=i-1;k>=0&&key<=arr[k];k--){
			arr[k+1]=arr[k];
		}
		arr[k+1]=key;
	}
}

// selection sort for int

void selectionsort_int(int arr[],int size){
    int i,k,min,temp;
	for(i=0;i<size;i++){
		min=i;
		for(k=i;k<size;k++){
			if(arr[k]<arr[min]){
				min=k;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
// selection sort for int
void selectionsort_char(char arr[],int size){
	int i,k,temp;
	char min;
	for(i=0;i<size;i++){
		min=i;
		for(k=i;k<size;k++){
			if(arr[k]<arr[min]){
				min=k;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

// bubble sort for int

void bubblesort_int(int arr[],int size){
	int i,move,temp;
	for(move=0;move<size-1;move++){
		for(i=0;i<(size-1-move);i++){
			if(arr[i]>arr[i+1]){
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
	
}
// bubble sort for char
void bubblesort_char(char arr[],int size){
int i,move,temp;
	for(move=0;move<size-1;move++){
		for(i=0;i<(size-1-move);i++){
			if(arr[i]>arr[i+1]){
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}	
}

// merge sort for int
void merge_int(int arr[],int left,int m,int right){
	int i,j,k,num1,num2;
	num1=m-left+1;
	num2=right-m;
	int L[num1],R[num2];
	
	for(i=0;i<num1;i++){
		L[i]=arr[left+i];
	}
	for(j=0;j<num2;j++){
		R[j]=arr[m+1+j];
	}
	
	i=0;
	j=0;
	k=left;
	
	while(i<num1&&j<num2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<num1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<num2){
		arr[k]=R[j];
		j++;
		k++;
	}
	
}
void mergesort_int(int arr[],int left,int right){
	if(left<right){
		int m=left+(right-left)/2;
		mergesort_int(arr,left,m);
		mergesort_int(arr,m+1,right);
		merge_int(arr,left,m,right);
	}
}


// merge sort for char
void merge_char(char arr[],int left,int m,int right){
	int i,j,k,num1,num2;
	num1=m-left+1;
	num2=right-m;
	int L[num1],R[num2];
	
	for(i=0;i<num1;i++){
		L[i]=arr[left+i];
	}
	for(j=0;j<num2;j++){
		R[j]=arr[m+1+j];
	}
	
	i=0;
	j=0;
	k=left;
	
	while(i<num1&&j<num2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<num1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<num2){
		arr[k]=R[j];
		j++;
		k++;
	}
	
}
void mergesort_char(char arr[],int left,int right){
	if(left<right){
		int m=left+(right-left)/2;
		mergesort_char(arr,left,m);
		mergesort_char(arr,m+1,right);
		merge_char(arr,left,m,right);
	}
}

#include<stdio.h>
#include<time.h>
#include<assert.h>
#include<string.h>

// quick sort for int
void quicksort_int(int arr[], int left, int right) {
int k, j, q, temp;
k = left;
j = right;
q = arr[(left+right)/2]; 

do{
	while((arr[k]<q)&&(k<right) )
	k++;
	while((arr[j]>q)&&(j>left))
	j--;
	if(k<=j){
		temp=arr[k];
		arr[k]=arr[j];
		arr[j]=temp;
		k++;
		j--;
	}
} while(k<=j);

if(left<j)
   quicksort_int(arr,left,j);
if(k<right)
   quicksort_int(arr,k,right);   
}

// quick sort for char
void quicksort_char(char arr[], int left, int right) {
int k, j, q, temp;
k = left;
j = right;
q = arr[(left+right)/2]; 

do{
	while((arr[k]<q)&&(k<right) )
	k++;
	while((arr[j]>q)&&(j>left))
	j--;
	if(k<=j){
		temp=arr[k];
		arr[k]=arr[j];
		arr[j]=temp;
		k++;
		j--;
	}
} while(k<=j);

if(left<j)
   quicksort_char(arr,left,j);
if(k<right)
   quicksort_char(arr,k,right);   
}

// heap sort

int left(int i){
	return(2*i+1);
}
int right(int i){
	return(2*i+2);
}

int heap_size;

//heap sort functions for int
void heapify_int(int arr[],int i){
	int left_child,right_child,max,temp;
	left_child=left(i);
	right_child=right(i);
	
	if((left_child<=heap_size)&&(arr[left_child]>arr[i]))
	max=left_child;
	else
	max=i;
	
	if((right_child<=heap_size)&&(arr[right_child]>arr[max]))
	max=right_child;
	
	if(max!=i){
		temp=arr[max];
		arr[max]=arr[i];
		arr[i]=temp;
		heapify_int(arr,max);
	}
}

void build_heap_int(int arr[],int n){
	heap_size=n-1;
	for(int i=(n-1)/2;i>=0;i--){
		heapify_int(arr,i);
	}
}

void heapsort_int(int arr[],int n){
int i,temp;
build_heap_int(arr,n);
for(i=n-1;i>=1;i--){
	temp=arr[i];
	arr[i]=arr[0];
	arr[0]=temp;
	heap_size--;
	heapify_int(arr,0);
 }
}

// heap sort functions for char
void heapify_char(char arr[],int i){
	int left_child,right_child,max,temp;
	left_child=left(i);
	right_child=right(i);
	
	if((left_child<=heap_size)&&(arr[left_child]>arr[i]))
	max=left_child;
	else
	max=i;
	
	if((right_child<=heap_size)&&(arr[right_child]>arr[max]))
	max=right_child;
	
	if(max!=i){
		temp=arr[max];
		arr[max]=arr[i];
		arr[i]=temp;
		heapify_char(arr,max);
	}
}

void build_heap_char(char arr[],int n){
	heap_size=n-1;
	for(int i=(n-1)/2;i>=0;i--){
		heapify_char(arr,i);
	}
}

void heapsort_char(char arr[],int n){
int i,temp;
build_heap_char(arr,n);
for(i=n-1;i>=1;i--){
	temp=arr[i];
	arr[i]=arr[0];
	arr[0]=temp;
	heap_size--;
	heapify_char(arr,0);
 }
}
	
	// printing int array
	void printarray_int(int arr[],int size){
		for(int i=0;i<size;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	// printing char array
	void printarray_char(char arr[],int size){
		for(int i=0;i<size;i++){
			printf("%c ",arr[i]);
		}
		printf("\n");
	}
	
	
	
	int main(){
		
		// insertion sort
		clock_t time;
		int number[]={2,0,1,8,5,5,5,0,1,4};  
	    char name[]="yusuf demir";
	    int intsize=sizeof(number)/sizeof(number[0]);
	    int charsize=strlen(name);
		
		time=clock();
		insertionsort_int(number,intsize);
		time=clock()-time;
		printf("numaranin insertion sort ile siralanmis hali:\n");
		printarray_int(number,intsize);
		printf("insertion sort time for int array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		insertionsort_char(name,charsize);
		time=clock()-time;
		printf("\nadin insertion sort ile siralanmis hali:\n");
		printarray_char(name,charsize);
		printf("insertion sort time for char array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		printf("\n");
		
		// selection sort
		int number1[]={2,0,1,8,5,5,5,0,1,4};  
	    char name1[]="yusuf demir";
	    int intsize1=sizeof(number1)/sizeof(number1[0]);
	    int charsize1=strlen(name1);
	    
	    selectionsort_int(number1,intsize1);
	    time=clock()-time;
	    printf("numaranin selection sort ile siralanmis hali:\n");
		printarray_int(number1,intsize1);
		printf("selection sort time for int array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		selectionsort_char(name1,charsize1);
		time=clock()-time;
		printf("\nadin selection sort ile siralanmis hali:\n");
		printarray_char(name1,charsize1);
		printf("selection sort time for char array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		printf("\n");
		
		// bubble sort
		int number2[]={2,0,1,8,5,5,5,0,1,4};  
	    char name2[]="yusuf demir";
	    int intsize2=sizeof(number2)/sizeof(number2[0]);
	    int charsize2=strlen(name2);
	    
	    bubblesort_int(number2,intsize2);
	    time=clock()-time;
	    printf("numaranin bubble sort ile siralanmis hali:\n");
		printarray_int(number2,intsize2);
		printf("bubble sort time for int array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		bubblesort_char(name2,charsize2);
		time=clock()-time;
		printf("\nadin bubble sort ile siralanmis hali:\n");
		printarray_char(name2,charsize2);
		printf("\nbubble sort time for char array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		printf("\n");
		
		// merge sort
		int number3[]={2,0,1,8,5,5,5,0,1,4};  
	    char name3[]="yusuf demir";
	    int intsize3=sizeof(number3)/sizeof(number3[0]);
	    int charsize3=strlen(name3);
	    
	   mergesort_int(number3,0,intsize3-1);
	    time=clock()-time;
	    printf("numaranin merge sort ile siralanmis hali:\n");
		printarray_int(number3,intsize3);
		printf("merge sort time for int array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		mergesort_char(name3,0,charsize3-1);
		time=clock()-time;
		printf("\nadin merge sort ile siralanmis hali:\n");
		printarray_char(name3,charsize3);
		printf("merge sort time for char array:  %f\n",((double)time)/CLOCKS_PER_SEC);
		printf("\n");  
		
		// quick sort
	int num4[]={2,0,1,8,5,5,5,0,1,4};
	char name4[]="yusuf demir";
	int intsize4=sizeof(num4)/sizeof(num4[0]);
	int charsize4=strlen(name4);
	time=clock();
	quicksort_int(num4,0,intsize4-1);
	time=clock()-time;
	printf("numaranin quicksort ile siralanmis hali:\n");
	printarray_int(num4,intsize4);
	printf("quicksort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	
	quicksort_char(name4,0,charsize4-1);
	time=clock()-time;
	printf("adin quicksort ile siralanmis hali:\n");
	printarray_char(name4,charsize4);
	printf("quicksort time for name=  %f\n",((double)time)/CLOCKS_PER_SEC);
// heap sort
    int num5[]={2,0,1,8,5,5,5,0,1,4};
	char name5[]="yusuf demir";
	int intsize5=sizeof(num5)/sizeof(num5[0]);
	int charsize5=strlen(name5);

	heapsort_int(num5,intsize5);
	time=clock()-time;
	printf("\nnumaranin heapsort ile siralanmis hali:\n");
	printarray_int(num5,intsize5);
	printf("heapsort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	
	heapsort_char(name5,charsize5);
	time=clock()-time;
	printf("\nadin heapsort ile siralanmis hali:\n");
	printarray_char(name5,charsize5);
	printf("heapsort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	return 0;	
	}
