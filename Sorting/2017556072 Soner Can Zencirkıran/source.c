#include <stdio.h>
#include <string.h>
#include <time.h>
//Insertion of Id
void insertionId(int id[],int x){
int i,key,j; 
    for (i=1;i<x;i++){ 
        key=id[i]; 
        j=i-1; 
  
        while (j>=0&&id[j]>key){ 
            id[j+1]=id[j]; 
            j=j-1; 
        } 
        id[j+1]=key; 
    } 
}
//Insertion of Name and Surname
void insertionNameSurname(char name[],int x){
    int i, j;
    char y;
    for (i=1;i<x;i++)
    {
        y=name[i];

        for(j=i-1;j>=0&&name[j]>y;j--)
        {
            name[j+1]=name[j];
        }
        name[j+1] =y;
    }
}
//Classic swapping Function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Swapping Function for Characters
void swapChar(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
//Function to print sorted array
void printArray(int arr[],int x){
	int i;
    for (i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//Bubble sorter for Id
void bubbleId(int id[],int x){
    int flag=0,i=0,j;
    do
    {
        flag=0;
        for (j =0;j<x-i-1;j++)
        {
            if(id[j]>id[j+1])
            {
                swap(&id[j],&id[j+1]);
                flag=1;
            }
        }
        i++;
    } while(flag);
}
//Bubble sorter for Name and Surname
void bubbleNameSurname(char name[],int x){
    int flag=0,i=0,j;
    do
    {
        flag=0;
        for(j=0;j<x-i-1;j++)
        {
            if(name[j]>name[j+1])
            {
                swapChar(&name[j],&name[j+1]);
                flag=1;
            }
        }
        i++;
    } while (flag);
}
//Merge sorter for Id
void mergeIdSorter(int id[],int left,int middle,int right){
    int i,j,key;

    int leftSize=middle-left+1;
    int rightSize=right-middle;

    int leftx[leftSize],rightx[rightSize];

    for (i=0;i<leftSize;i++)
    {
        leftx[i] = id[left+i];
    }
    for (j=0;j<rightSize;j++)
    {
        rightx[j]=id[middle+1+j];
    }

    j=0,i=0,key=left;

    while(leftSize>i&&rightSize>j)
    {
        if (leftx[i]<=rightx[j])
        {
            id[key]=leftx[i];
            i++;
        }
        else
        {
            id[key]=rightx[j];
            j++;
        }
        key++;
    }

    while(leftSize>i)
    {
        id[key]=leftx[i];
        key++;
        i++;
    }
    while(rightSize>j)
    {
        id[key]=rightx[j];
        key++;
        j++;
    }
}
void mergeId(int id[],int left,int right){
    if(left<right)
    {
        int middle=left+(right-left)/2;

        mergeId(id,left,middle);
        mergeId(id,middle+1,right);

        mergeIdSorter(id,left,middle,right);
    }
}
//Merge sorter for Name and Surname
void mergeNameSurnameSorter(char id[],int left,int middle,int right){
    int i, j, key;

    int leftSize=middle-left+1;
    int rightSize =right-middle;

    int leftx[leftSize],rightx[rightSize];

    for(i=0;i<leftSize;i++)
    {
        leftx[i]=id[left+i];
    }
    for(j=0;j<rightSize;j++)
    {
        rightx[j]=id[middle+1+j];
    }

    j=0,i=0,key=left;

    while(leftSize>i&&rightSize>j)
    {
        if(leftx[i]<=rightx[j])
        {
            id[key]=leftx[i];
            i++;
        }
        else
        {
            id[key]=rightx[j];
            j++;
        }
        key++;
    }

    while(leftSize>i)
    {
        id[key]=leftx[i];
        key++;
        i++;
    }
    while(rightSize>j)
    {
        id[key]=rightx[j];
        key++;
        j++;
    }
}

void mergeNameSurname(char id[],int left,int right)
{
    if(left<right)
    {
        int middle=left+(right-left)/2;

        mergeNameSurname(id,left,middle);
        mergeNameSurname(id,middle+1,right);

        mergeNameSurnameSorter(id,left,middle,right);
    }
}
//Selection sorter for Id
void selectionId(int num[],int x){

    int i,j,temp,minIndex;

    for (i=0;i<x-1;i++)
    {
        minIndex=i;
        for (j=i+1;j<x;j++)
        {
            if (num[minIndex]>num[j])
            {
                minIndex=j;
            }
        }
        swap(&num[i], &num[minIndex]);
    }
}
//Selection sorter for Name and Surname
void selectionNameSurname(char name[],int x){

    int i,j,temp,minIndex;

    for(i=0;i<x-1;i++)
    {
        minIndex=i;
        for (j=i+1;j<x;j++)
        {
            if(name[minIndex]>name[j])
            {
                minIndex=j;
            }
        }
        swapChar(&name[i], &name[minIndex]);
    }
}
void quicksort(int id[],int first,int last){
  int i,j,pivot,temp;
  if (first<last) {
    pivot=first;
    i=first;
    j=last;
    while(i<j){

      while(id[i]<=id[pivot]&&i<last)
        i++;
        
      while(id[j]>id[pivot])
        j--;
        
      if(i<j){
        temp=id[i];
        id[i]=id[j];
        id[j]=temp;
      }
    }
    temp=id[pivot];
    id[pivot]=id[j];
    id[j]=temp;
    quicksort(id,first,j-1);
    quicksort(id,j+1,last);
  }
}
char partitionChar(char nameSurname[],int low,int high){
    int pivot=nameSurname[high];
    int i=(low-1);
    int j;
    
	j=low;
	while(j<=high-1){
	if(nameSurname[j]<pivot){
	    i++;
	    swapChar(&nameSurname[i],&nameSurname[j]);
	}
	    j++;
	}
    swapChar(&nameSurname[i+1],&nameSurname[high]);
    return(i+1);
}

void quickSortChar(char nameSurname[],int low,int high){
    if(low<high){
        int part=partitionChar(nameSurname,low,high);

        quickSortChar(nameSurname,low,part-1);
        quickSortChar(nameSurname,part+1,high);
    }
}
void heap(int nameSurname[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&nameSurname[left]>nameSurname[largest])
        largest=left;

    if(right<n&&nameSurname[right]>nameSurname[largest])
        largest=right;

    if(largest != i){
        swap(&nameSurname[i],&nameSurname[largest]);
        heap(nameSurname,n,largest);
    }
}
void heapSort(int nameSurname[],int n){
    int i, j;
    
	i=n/2-1;
	while(i>=0){
	heap(nameSurname,n,i);
	i--;
    }
    j=n-1;
    while(j>0){
	swap(&nameSurname[0],&nameSurname[j]);
	heap(nameSurname,j,0);
	j--;
	}
}
void heapChar(char nameSurname[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n&&nameSurname[left]>nameSurname[largest])
        largest=left;

    if (right<n&&nameSurname[right]>nameSurname[largest])
        largest=right;

    if (largest!=i){
        swapChar(&nameSurname[i],&nameSurname[largest]);
        heapChar(nameSurname,n,largest);
    }
}

void heapSortChar(char nameSurname[], int n) {
    int i, j;
    
	i=n/2-1;
	while(i>=0){
	heapChar(nameSurname,n,i);
	i--;
}
	j=n-1;
	while(j>0){
	swapChar(&nameSurname[0],&nameSurname[j]);
	heapChar(nameSurname,j,0);
	j--;
	}
	
	}
int main(int argc, char const *argv[])
{
    int id[] = {2,0,1,7,5,5,6,0,7,2};
    char nameSurname[] = "soner can zencirkiran";
    int sizeId = sizeof(id)/sizeof(id[0]);
    int sizeNameSurname=(sizeof(nameSurname)/sizeof(nameSurname[0]))-1;
    clock_t start,stop;
    double time;
//Timer for insertion(Id)
    start = clock();
    insertionId(id,sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Insertion sort for Id - ");
    insertionId(id,sizeId);
    printArray(id,sizeId);
    printf("passed time - %f\n",time);
//Timer for insertion(Name and Surname)
    start = clock();
    insertionNameSurname(nameSurname, sizeNameSurname);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Insertion sort for name and surname -");
    printf("%s\n", nameSurname);
    printf("passed time - %f\n",time);
    
    printf("-------------------------------------------------------------------------\n");
    
    int id2[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname2[]="soner can zencirkiran";
//Timer for Bubble(Id)
    start = clock();
    bubbleId(id2,sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Bubble sort for Id - ");
    printArray(id2,sizeId);
    printf("passed time - %f\n",time);
//Timer for Bubble(Name and Surname)
    start = clock();
    bubbleNameSurname(nameSurname2, sizeNameSurname);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Bubble sort for name and surname -");
    printf("%s\n", nameSurname2);
    printf("passed time - %f\n",time);

    printf("-------------------------------------------------------------------------\n");

    int id3[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname3[]="soner can zencirkiran";
//Timer for Merge(Id)
    start = clock();
    mergeId(id3,0,sizeId-1);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Merge sort for Id - ");
    printArray(id3,sizeId);
    printf("passed time - %f\n",time);
//Timer for Merge(Name and Surname)
    start = clock();
    mergeNameSurname(nameSurname3,0,sizeNameSurname-1);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Merge sort for name and surname -");
    printf("%s\n",nameSurname3);
    printf("passed time = %f\n",time);
    
    printf("-------------------------------------------------------------------------\n");
    
    int id4[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname4[] = "soner can zencirkiran";
//Timer for Selection(Id)
    start = clock();
    selectionId(id4, sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Selection sort for Id - ");
    printArray(id4, sizeId);
    printf("passed time - %f\n",time);
//Timer for Selection(Name and Surname)
    start=clock();
    selectionNameSurname(nameSurname4, sizeNameSurname);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Selection sort for name and surname -");
    printf("%s\n", nameSurname4);
    printf("passed time - %f\n",time);
    
    printf("-------------------------------------------------------------------------\n");
    
    start = clock();
    insertionId(id,sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
//Time for Quick(Id)
    int i,count;
    int id5[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname5[] = "soner can zencirkiran";
    quicksort(id,0,9);
    printf("Quick sort for Id - ");
    for(i=0;i<10;i++)
    printf(" %d",id[i]);
    printf("\npassed time - %f",time);
//Timer for Quick(Name and Surname)
    start = clock();
    quickSortChar(nameSurname5,0,sizeNameSurname-1);
    stop = clock();
    printf("\nQuick sort for name and surname -");
    printf("%s\n",nameSurname5);
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("passed time - %f",time);
    
    printf("\n-------------------------------------------------------------------------\n");

//Timer for Headp(Id)
    int id6[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname6[] = "soner can zencirkiran";
    start = clock();
    heapSort(id6,sizeId);
    stop = clock();
    printf("Heap sort for Id - ");
    for(i=0;i<10;i++)
    printf(" %d",id6[i]);
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\npassed time - %f",time);
    
    
//Timer for Heap(Name and Surname)
    start = clock();
    heapSortChar(nameSurname6,sizeNameSurname);
    stop = clock();
    printf("\nHeap sort for name and surname -");
    printf("%s\n",nameSurname6);
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("passed time - %f",time);

    return 0;
}
