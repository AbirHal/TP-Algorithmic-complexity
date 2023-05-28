


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
	void inter_class(int T[], int debut, int milieu, int fin);	 
    void triFusion(int T[], int debut, int fin);	 

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

triFusion(T, 0, size - 1);
   	printf("********************* tri fusion *************************  \n");

	for(int i = 0; i<size;i++){
	printf("T[%d]=%d\n",i ,T[i]);	
	}
		 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);
		 //printf("Nbr de Compairisons:%d \n",(size*(size-1))/2);
		//  printf("Changes:%d \n",size-1);

	free(T);
	return 0;
	
}

// Fill  the table at randomly
void fill_random(int T[], int size,int max,int min){
	for(int i = 0; i<size;i++){
		T[i]=(rand() % max)-min;
		
	}
	

}  void inter_class(int arr[], int debut, int milieu, int fin)
    {
        int n1 = milieu - debut + 1;
        int n2 = fin - milieu;
     
        int G[n1], D[n2];
     
        for (int i = 0; i < n1; i++)
            G[i] = arr[debut + i];
        for (int j = 0; j < n2; j++)
            D[j] = arr[milieu + 1 + j];
     
        // maintient trois pointeurs, un pour chacun des deux tableaux et un pour
        // maintenir l'index actuel du tableau trié final
        int i, j, k;
        i = 0;
        j = 0;
        k = debut;
     
        while (i < n1 && j < n2)
        {
            if (G[i] <= D[j])
            {
                arr[k] = G[i];
                i++;
            }
            else
            {
                arr[k] = D[j];
                j++;
            }
            k++;
        }
     
        // Copiez tous les éléments restants du tableau non vide
        while (i < n1)
        {
            arr[k] = G[i];
            i++;
            k++;
        }
     
        while (j < n2)
        {
            arr[k] = D[j];
            j++;
            k++;
        }
    }
    
    
    
    
    void triFusion(int arr[], int debut, int fin)
    {
        if (debut < fin)
        {
     
            // Trouvez le point milieu pour diviser le tableau en deux moitiés
            int m = (debut + fin) / 2;
     
            triFusion(arr, debut, m);
            triFusion(arr, m + 1, fin);
     
            // Fusionnez les deux moitiés triées
            inter_class(arr, debut, m, fin);
        }
    }
     
   
