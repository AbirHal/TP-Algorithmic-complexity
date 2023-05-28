/*
Students: abir halouadji & abla bechoua
Group: 01 


Quick Sort
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int size ,x,count=0,r,l;
    int*T;
    clock_t startTime;
    clock_t endTime;
		//Calling  FUNCTIONS
    void fill_random(int T[], int size,int max,int min);
	void partition(int T[], int l, int r);	 
   void quickSort_middle_pivot(int T[], int l, int r);
    int partition_r(int T[], int l, int r);
    void quickSort_random_pivot(int T[], int l, int r);

    

	printf(" Please enter Size\n ");

	scanf("%d",&size);
	if(size>1000){
		
     T=(int*)malloc(size * sizeof(int));
	}
	else{
		
	 printf(" Please enter value greater than 10000\n ");
	 	scanf("%d",&size);
	 	     T=(int*)malloc(size * sizeof(int));
	}
	 
 	
fill_random(T,size,20,10);

quickSort_middle_pivot(T,0,size-1);
   	printf("********************* QUICK SORT WITH FIXED PIVOT *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
		 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 printf("Nbr de Compairisons:%d \n",(size-1));
		
		


quickSort_random_pivot(T,0,size-1);
   	printf("********************* QUICK SORT WITH random PIVOT *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
		 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 printf("Nbr de Compairisons:%d \n",((size*(size-1))/2));
				
		
		
		
		

	free(T);
	return 0;
	
}


// Fill  the table at randomly
void fill_random(int T[], int size,int max,int min){
	for(int i = 0; i<size;i++){
		T[i]=(rand() % max)-min;
		
	}
	

} 

int partition(int arr[], int left, int right)

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

     

      return i;

}



void quickSort_middle_pivot(int arr[], int left, int right) {

    clock_t startTime;
    clock_t endTime;
  
      int index = partition(arr, left, right);
     
startTime;
      if (left < index - 1)

            quickSort_middle_pivot(arr, left, index - 1);

      if (index < right)

            quickSort_middle_pivot(arr, index, right);
           
            endTime;
            

}


/****************** QUICK SORT WITH RONDOM PIVOT*****************************/

int partition_R(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (1) {
 
        do {
            i++;
        } while (arr[i] < pivot);
 
        do {
            j--;
        } while (arr[j] > pivot);
 
        if (i >= j)
            return j;
 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int partition_r(int arr[], int left, int right)
{
	srand(time(0));
	int random = left+ rand() % (right - left);

	int temp = arr[random];
	arr[random] = arr[left];
	arr[left] = temp;

	return partition_R(arr, left, right);
}

void quickSort_random_pivot(int arr[], int left, int right)
{
	
    clock_t startTime;
    clock_t endTime;
  startTime;
	if (left < right) {
		int pi = partition_r(arr, left, right);

		quickSort_random_pivot(arr, left, pi);
		quickSort_random_pivot(arr, pi + 1, right);
	}
	   
            endTime;
}








