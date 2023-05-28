



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
n : nombre de disques utilisés
A : emplacement de départ
B : emplacement d'arrivée
C : emplacement intermédiaire
*/

int main(){
	
	int nDisques;
	clock_t startTime;
    clock_t endTime;
	void toursHanoi(int n, char A, char B, char C);
	printf(" Please enter nDisques\n ");

	scanf("%d",&nDisques);
	startTime;
	toursHanoi(nDisques, 'A', 'B', 'C');
	endTime;
	printf("le nombre total de mouvements: %.0lf \n ",pow(2, nDisques)-1);
			 printf("Execution Time in Seconds:%f \n",((double)endTime - startTime)/CLOCKS_PER_SEC);


   
}
void toursHanoi(int n, char A, char B, char C) {
    if (n == 1)
      printf("Disque 1 de %c a %c \n" , A , B);
    else {
      // A à B
      toursHanoi(n - 1, A, C, B);
      printf("Disque %d de %c a %c \n", n , A ,B);
      //C à B
      toursHanoi(n - 1, C, B, A);
    }
}


