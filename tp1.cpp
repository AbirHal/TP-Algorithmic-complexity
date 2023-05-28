


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
		
for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);
		
	}
	
	printf("enter valeur pour recherch: \n");
	scanf("%d",&x);
		for(int i = 0; i<size;i++){
					count++;
			startTime = clock();
			if(T[i]==x){
			
			printf("x exsist \n");
           	printf("nbr de coparisons:%d \n",i+1);
		 	break;
			}
		


	
	if(count==size){
				printf("x does not exsist \n");
	            printf("nbr de coparisons:%d \n",size);
	}	endTime = clock();}

			
printf("Execution Time in Seconds:%f",((double)endTime - startTime)/CLOCKS_PER_SEC);
	
	free(T);
	return 0;
	
}
// Fill  the table at randomly
void fill_random(int T[], int size,int max,int min){
	for(int i = 0; i<size;i++){
		T[i]=(rand() % max)-min;
		
	}
	

}
	




