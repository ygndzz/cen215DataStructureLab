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

// print array
void printarray_int(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printarray_char(char arr[],int size){
	for(int i=0;i<size;i++){
		printf("%c ",arr[i]);
	}
	printf("\n");
}


int main(){
	clock_t time;
	// quick sort
	int num[]={2,0,1,8,5,5,5,0,1,4};
	char name[]="yusuf demir";
	int intsize=sizeof(num)/sizeof(num[0]);
	int charsize=strlen(name);
	time=clock();
	quicksort_int(num,0,intsize-1);
	time=clock()-time;
	printf("numaranin quicksort ile siralanmis hali:\n");
	printarray_int(num,intsize);
	printf("quicksort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	
	quicksort_char(name,0,charsize-1);
	time=clock()-time;
	printf("adin quicksort ile siralanmis hali:\n");
	printarray_char(name,charsize);
	printf("quicksort time for name=  %f\n",((double)time)/CLOCKS_PER_SEC);
// heap sort
    int num1[]={2,0,1,8,5,5,5,0,1,4};
	char name1[]="yusuf demir";
	int intsize1=sizeof(num1)/sizeof(num1[0]);
	int charsize1=strlen(name1);

	heapsort_int(num1,intsize1);
	time=clock()-time;
	printf("\nnumaranin heapsort ile siralanmis hali:\n");
	printarray_int(num1,intsize1);
	printf("heapsort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	
	heapsort_char(name1,charsize1);
	time=clock()-time;
	printf("\nadin heapsort ile siralanmis hali:\n");
	printarray_char(name1,charsize1);
	printf("heapsort time for num=  %f\n",((double)time)/CLOCKS_PER_SEC);
	
  return 0;
}

