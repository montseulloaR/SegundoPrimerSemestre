//Metodos de ordenamiento
//Autores: Montserrat Alejandra Ulloa Rivera, Paulo Vinicio Martinez Roque     2"A"  ICI
//Fecha: 04/06/2019
/*Objetivo: 
	1.	Generar un vector de 10,000 números aleatorios.
	2.	Mostrar vector desordenado.
	3.	Mostrar el vector ordenado por el Método de la Burbuja y dar el tiempo que se tardó en ordenarlo.
	4.	Mostrar el vector ordenado por el Método QuickSort y dar el tiempo que se tardó en ordenarlo.
	
	Recuerde que:
	"	Por cada método, debe mostrar el tiempo que tarda en ordenar la información.
	"	Debe mostrar los tiempos de los dos métodos al mismo tiempo para que se puedan analizar los tiempos registrados.
	"	Debe indicar cuál de los dos métodos de ordenamiento, es el más rápido 
	
	5.	Realice un menú para facilitar la utilización de su programa.
	6.	Puede agregar las mejoras que desee.
	7.	No olvide comentar el programa.


*/
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime> 

#define limit 20000

using namespace std;

int Burb[limit], Quick[limit];

void Vector(){
	for(int i = 0; i<limit; i++){
		Burb[i] = rand() % 1000 + 1;
		Quick[i] = Burb[i];
	}	
}

void mostrar(int v[limit]){
	for(int i = 0; i<limit; i++){
		printf("[%d]", v[i]);
	}	
}

void Burbuja(int v[]){
	int aux;
	for(int i=1; i<limit; i++)
	{
		for(int j=0; j<limit-1; j++)
		{
			if(v[j]>v[j+1])
			{
			    aux    = v[j+1];
				v[j+1] = v[j];
				v[j]   = aux;
			}
		}
	}
}

int quickSort(int v[limit], int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(v[i]<=v[pivot]&&i<last)
            i++;
         while(v[j]>v[pivot])
            j--;
         if(i<j){
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
         }
      }

      temp=v[pivot];
      v[pivot]=v[j];
      v[j]=temp;
      quickSort(v, first,j-1);
      quickSort(v, j+1,last);

   }
	
}


int main(){
	srand(time(NULL));
	int x, num;
	unsigned t0, t1;
	Vector();


	bool out=false;
	do{
		system("color F0");		
		system("CLS");
		printf("\tMETODOS DE ORDENACION\n");
		printf("1. Metodo de la burbuja\n");
		printf("2. QuickSort\n");
		printf("3. Comparar ambos metodos\n");
		printf("4. Mostrar vector\n");
		printf("5. Reinciar vector con valores nuevos\n");
		printf("6. Salir\n");
		scanf("%d", &x);
	
		switch(x){
			case 1: {
				t0 = clock();	
				Burbuja(Burb);
				t1 = clock();
				
				mostrar(Burb);
 				
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\n\tTiempo de ejecucion: %lf\n", time);
				
				system("pause");
				break;
			}
			
			case 2: {
				t0 = clock();
				quickSort(Quick, 0, limit-1);
				t1 = clock();
				
				mostrar(Quick);
				
				
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\n\tTiempo de ejecucion: %lf\n", time);
				system("pause");
				break;
			}
			
			case 3: {
				t0 = clock();	
				Burbuja(Burb);
				t1 = clock();
				
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\nTiempo de ejecucion de BURBUJA: %lf\n", time);
				
				t0 = clock();
				quickSort(Quick, 0, limit-1);
				t1 = clock();
				
				double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\nTiempo de ejecucion de QUICKSORT: %lf\n", tiempo);
				
				if(tiempo>time){
					printf("\nEl metodo Burbuja es mas rapido por %lf segundos\n", tiempo-time);
				}
				else{
					printf("\nEl metodo QuickSort es mas rapido por %lf segundos\n", time-tiempo);
				}
				
				system("pause");

				break;
			}
			
			case 4: {
				mostrar(Burb);
				system("pause");
				break;
			}
			
			
			case 5: {
				Vector();
				break;
			}
			
			case 6: {
				out = true;
				break;
			}
			
			default: {
				printf("\nLa opcion ingresada es incorrecta\n");
				Sleep(1000);
				break;
			}
		}
	}while(out==false);

	return 0; 
}
