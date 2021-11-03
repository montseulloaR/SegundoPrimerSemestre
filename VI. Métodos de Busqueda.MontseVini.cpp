//Metodos de busqueda
//Autores: Montserrat Alejandra Ulloa Rivera, Paulo Vinicio Martinez Roque     2"A"  ICI
//Fecha: 04/06/2019
/*Objetivo: 
	1.	Generar un vector de 10,000 números aleatorios.
	2.	Mostrar vector
	3.	Pedir dato a buscar
	4.	Dar tiempo de búsqueda por Método Secuencial
	5.	Dar tiempo de búsqueda por Método Binario
	
	"	Por cada método, debe mostrar el tiempo que tarda en hacer la búsqueda y debe indicar en qué posición se encuentra el dato. Si el dato a buscar se repite, debe mostrar cada una de las posiciones en las que se repite dicho número.
	"	Debe mostrar la información de los dos métodos al mismo tiempo para que se puedan analizar los tiempos registrados.
	"	Recuerde que en el método binario debe ordenar primero el vector. También incluya este procedimiento en el tiempo registrado.
	
	6.	Realice un menú para facilitar la utilización de su programa.
	7.	Puede agregar las mejoras que desee.
	8.	No olvide comentar el programa.

*/
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime> 
#include <bits/stdc++.h>

#define limit 10000

using namespace std;

int vec[limit];

void Vector(){
	for(int i = 0; i<limit; i++){
		vec[i] = rand() % 1000 + 1;
	}	
}

void mostrar(){
	for(int i = 0; i<limit; i++){
		printf("[%d]", vec[i]);
	}	
	system("pause");
}

void Secuencial(int n){
	bool find = false;
	printf("\nMETODO SECUENCIAL\n");
	printf("[%d] Se encuentra en: \n", n );
	for(int i = 0; i<limit-1; i++)
    {	
        if(vec[i]==n)
        {
            printf("\t-Posicion: %d\n",i+1);
            find = true;
        }
   }
    if(!find){printf("\tNinguna parte del vector\n");}	
}

void quickSort(int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(vec[i]<=vec[pivot]&&i<last)
            i++;
         while(vec[j]>vec[pivot])
            j--;
         if(i<j){
            temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
         }
      }

      temp=vec[pivot];
      vec[pivot]=vec[j];
      vec[j]=temp;
      quickSort(first,j-1);
      quickSort(j+1,last);

   }
}

void Binaria (int n){
	bool find = false;
	int first = 0, last = limit-1, cen, bus; 
	int flag1=0, flag2=0;
	int x;
	printf("\nMETODO BINARIO\n");
	printf("[%d] Se encuentra en: \n", n );
 	
    while (first <= last) {
        cen = (first + last) / 2;
 		x=cen;
        if (n == vec[cen]) {
			
		//	printf("\t-Posicion: %d\n", cen + 1 ); 
			while(vec[x]==n){
				
			//	printf("\t-Posicion: %d\n", cen + 1 ); 
				x--;
			
			}
			x++;
			while(vec[x]==n){
				
				printf("\t-Posicion: %d\n", x + 1 ); 
				x++;
			
			}
			
			find = true;
			return;
			}
        else{
        	if (vec[cen] > n) {last = cen - 1;} 
			else {first = cen + 1;}
		}
        
    }
	if(!find){printf("\tNinguna parte del vector\n");}

} 


int main(){
	srand(time(NULL));
	int x, num;
	unsigned t0, t1;
	Vector();
	system("color F0");	
	printf("\n\tVector Creado\n\tElemento a buscar: ");
	scanf("%d", &num);
	system("CLS");
	
	bool out=false;
	do{
		system("color F0");		
		system("CLS");
		printf("\tMETODOS DE BUSQUEDA\n");
		printf("1. Busqueda Secuencial\n");
		printf("2. Busqueda Metodo Binaria\n");
		printf("3. Ambas\n");
		printf("4. Mostrar\n");
		printf("5. Numero nuevo\n");
		printf("6. Vector nuevo\n");
		printf("7. Salir\n");
		scanf("%d", &x);
	
		switch(x){
			case 1: {
				t0 = clock();	
				Secuencial(num);
				t1 = clock();
 
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("Tiempo de ejecucion: %lf\n", time);
				
				system("pause");
				
				break;
			}
			
			case 2: {
				t0 = clock();
				quickSort(0, limit-1);
				Binaria(num);
				t1 = clock();
				
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("Tiempo de ejecucion: %lf\n", time);
				system("pause");
				break;
			}
			
			case 3: {
				t0 = clock();	
				Secuencial(num);
				t1 = clock();
 
				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\nTiempo de ejecucion de la busqueda SECUENCIAL: %lf\n", time);
				
				t0 = clock();
				quickSort(0, limit-1);
				Binaria(num);
				t1 = clock();
				
				double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
				printf("\nTiempo de ejecucion de la busqueda BINARIA: %lf\n", tiempo);
				
				if(tiempo>time){
					printf("\nEl metodo Secuencial es mas rapido por %lf segundos\n", tiempo-time);
				}
				else{
					printf("\nEl metodo Binario es mas rapido por %lf segundos\n", time-tiempo);
				}
				
				system("pause");
				break;
			}
			
			case 4: {
				mostrar();
				break;
			}
			
			case 5: {
				printf("Elemento a buscar: \n");
				scanf("%d", &num);
			}
			
			case 6: {
				Vector();
				break;
			}
			
			case 7: {
				out = true;
				break;
			}
			
			default: {
				printf("La opcion ingresada es incorrecta\n");
				Sleep(1000);
				break;
			}
		}
	}while(out==false);

	return 0; 
}
