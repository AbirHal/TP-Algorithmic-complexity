

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
  void tri_bulle(int arr[], int size);
  void tri_par_selection(int arr[], int size);
	
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
	
tri_bulle(T, size);
printf("********************* tri bulle ************************* \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
		 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 printf("Nbr de Compairisons:%d \n",(size*(size-1))/2);
		  printf("Changes:%d \n",(size*(size-1))/4);


tri_par_selection(T,size);
   	printf("********************* tri par selection *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
		 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		  printf("Nbr de Compairisons:%d \n",(size*(size-1))/2);
		  printf("Changes:%d \n",size-1);

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
int tri_par_selection(int arr[], int size) {
	int i,j,j_max;
		clock_t startTime;
    clock_t endTime;
   	for(i=0;i<size-1;i++){
   		j_max=0;
		for(j=1;j<size-1-i;j++){
			startTime = clock();
			if(arr[j]>arr[j_max])
		
				j_max=j;
				swap(arr,size-1-i,j_max);
					endTime = clock();
			
		}
	}
    }

// tri bulle
 int tri_bulle(int arr[], int size) {
	int i,k; 
	clock_t startTime;
    clock_t endTime;
	for(i=(size-1);i>0;i--){
		for(k=0;k<i;k++){
			startTime = clock();
			if(arr[k]>arr[k+1])
			{
				
				swap(arr,k,k+1);
			}
			endTime = clock();
		}
		

	}
}
 



