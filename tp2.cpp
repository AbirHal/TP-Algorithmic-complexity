


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int size ,x,count=0;
    int*T;
    clock_t startTime;
    clock_t endTime;
	//Calling  FUNCTIONS
    void fill_random(int T[], int size,int max,int min);	 
    void swap(int t[],int i, int j);
    int binarySearch_itrative(int arr[], int size, int x);
    int binarySearch_Recursive(int arr[], int l, int r, int x);
	
	
	printf(" Please enter Size\n ");

	scanf("%d",&size);
	if(size>10){
		
     T=(int*)malloc(size * sizeof(int));
	}
	else{
		
	 printf(" Please enter value greater than 10000\n ");
	 	scanf("%d",&size);
	 	     T=(int*)malloc(size * sizeof(int));
	}
	 
 	
fill_random(T,size,20,10);
		
	int k;
	for(int i = (size-1); i>0;i--){
       
		for(int k= 0; k<i;k++){
          if (T[k] >T[k+1]){
          	swap(T,k,k+1);
		  }
		
	    }
	}
	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
	printf("enter valeur pour recherch: \n");
	scanf("%d",&x);
	printf("version itrative \n");
	
	
	int result_itrative = binarySearch_itrative(T, size, x);
	startTime = clock();
    if (result_itrative == -1){

        printf("Value not found in array. \n");
        
        printf("nbr comparisson %d.\n", size-1);}
    else{
	
        printf("Value found \n");
        printf("nbr comparisson %d.\n", result_itrative+1);}
        endTime = clock();
        printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);

        printf("*********************************************** \n");
        
        
        
       	printf("version Recursive  \n");
       

	
	int result_Recursive = binarySearch_Recursive(T, 0, size- 1, x);
		startTime = clock();
    if (result_Recursive == -1){

        printf("Value not found in array. \n");
        
        printf("nbr comparisson %d.", size-1);}
    else{
	
        printf("Value found \n");
        printf("nbr comparisson %d.\n", result_Recursive+1);
		}
		
		
		   endTime = clock();

            printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);

   
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
//FONCTION RECURCIVE
int binarySearch_Recursive(int arr[], int l, int r, int x) {
    if (l> r) {
    	return -1;
		}
        int mid = l + (r - l) / 2;

        if (arr[mid] == x){
        	 return mid;
		}else if (arr[mid] > x){
		
            return binarySearch_Recursive(arr, l, mid - 1, x);
		}else{
			 return binarySearch_Recursive(arr, mid + 1, r, x);
		}

       
    }

// FONCTION ITRATIVE
 int binarySearch_itrative(int arr[], int size, int x) {
	int l=0;
 	int r= size-1;
 	int mid;
 	
 	while(l<r){
 	 mid=l+(r-l)/ 2;
 	   if (x==arr[mid])
		 {
 	  	return mid;
 		}else if (x<arr[mid]){
 			r= mid-1;	
		 }else{
		 	l=mid+1;
		 }
		  
	}return -1;
}
 


