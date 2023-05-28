


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int size ,x,count=0;
    int*T;
    clock_t startTime ,s;
    clock_t endTime,e;
	//Calling  FUNCTIONS
	   

    void fill_random(int T[], int size,int max,int min);
    void swap(int t[],int i, int j);
    
    void insertion1_sort(int arr[], int size);
    
   void insertion2_sort(int arr[], int size);


	printf(" Please enter Size\n ");

	scanf("%d",&size);
	if(size>100){
		
     T=(int*)malloc(size * sizeof(int));
	}
	else{
		
	 printf(" Please enter value greater than 10000\n ");
	 	scanf("%d",&size);
	 	     T=(int*)malloc(size * sizeof(int));
	}
	 
 	
fill_random(T,size,20,10);
	
startTime = clock();

insertion1_sort(T,size);
endTime = clock();
printf("********************* tri par Insertion 1 *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
	printf("Execution Time in Seconds for insertion sort 1: \t %f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);


	
s= clock();

insertion2_sort(T,size);
e = clock();
printf("********************* tri par Insertion 2 *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
	printf("Execution Time in Seconds for insertion sort 2: \t %f \n",((double)e - s)/CLOCKS_PER_SEC);


	free(T);
	
	
	 

	return 0;
	
}

// Fill  the table at randomly
void fill_random(int T[], int size,int max,int min){
	for(int i = 0; i<size;i++){
		T[i]=(rand() % max)-min;
		
	}
	

}
// swapping between elements	
void swap(int t[],int i, int j){
int q;	
	q=t[i];
	t[i]=t[j];
	t[j]=q;
}
// insertion sort

int insertion1_sort(int arr[], int size){
	int i,k;
   	for(i=1;i<size;i++){
   		k=i-1;
   		
   		while(k>=0 && arr[k+1]<arr[k]){   
   		 swap(arr,k,k+1);
   		  k=k-1;
		}
	

   	}

	}

int insertion2_sort(int arr[], int size){
	int i,k;
	double x;
   	for(i=1;i<size;i++){
   		k=i-1;
   		x=arr[i];
   		
   		while(k>=0 && arr[k]>x){   
   		 arr[k+1]=arr[k];
   		 arr[k]=x;
   		 x=arr[k+1];
   		  k=k-1;
		}
	

   	}

	}
    



