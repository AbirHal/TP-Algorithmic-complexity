


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	int p;
	double n ;
    clock_t startTime;
    clock_t endTime;
		//Calling  FUNCTIONS
    double ex(double n, int p);
   double ex_rapide(double n, int p);


	printf(" Please enter n \n ");

	scanf("%lf",&n);
	printf(" Please enter  P \n ");
	scanf("%d",&p);
	if(p<0){
		printf("Invalid value of p, please enter a positive integer: ");
		scanf("%d",&p);
	}
	 	
	
	 
 	



   	printf("********************* expentiation *************************  \n");
   	 startTime = clock(); // start measuring time
   double result = ex(n, p); // call the ex() function

    endTime = clock(); // stop measuring time
    printf("Result:%.2lf\n", result);
  

	printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 printf("Nbr de multiplications:%d \n",p);
	
		   	printf("********************* expentiation  rapide *************************  \n");

 startTime = clock(); // start measuring time
   double result1 = ex_rapide(n,p); // call the ex_rapide(() function

    endTime = clock(); // stop measuring time
    printf("Result: %.2lf\n", result1);
  

	printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 printf("Nbr de multiplications:%lf \n",log2((double)p)*n);
	
	return 0;
	
}

    
    
    
double ex(double n, int p)
    {
    	
          
          int power = 1 ;int i ;  
    for (i = 1;i<=p;i++){  
        power *=  n ;  
    }  
    return power ;  
}  
		    
double ex_rapide(double n, int p){
	if(p==1)return n;
	if(p%2==0){
		return ex_rapide(n*n,p/2);
	}else{
		return n*ex_rapide(n*n,(p-1)/2);
	}
	
	
}
     
   
