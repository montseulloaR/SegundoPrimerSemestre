//Montserrat Alejandra Ulloa Rivera
//Fecha de entrega: 11/03/2019
//Promedio de un numero con un vector

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int vec[10];
    int x,i,prom,suma;
    int *puntero;
	
	for(int i=0; i<10; i++){
		printf("Ingrese el valor %d:\n ",i+1);
		scanf("%d", &x);
		puntero=&x;
		suma=suma+*puntero;		
	}
	
	prom=suma/10;
	printf ("el promedio es:\n %d ",prom);
	system ("pause");
	return 0;
}
