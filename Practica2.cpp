#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int n, x, y;
	int co=0;
	printf("Dame un valor menor o igual a 10 para n: \n");
	//Se solicita el número con el que se van a trabajar las combinaciones 
	scanf("%d",&n);
	
	for (x=1; x<=n-1; x++) 
	//El ciclo for se realiza hasta 1 valor antes de n para evitar las repeticiones
	{
		for (y=x+1; y<=n; y++)
		//El ciclo for empieza 1 valor después de n para evitar las repeticiones
		{
		printf("%d     %d\n", x,y);
		//Se van imprimiendo las combinaciones conforme se evalúan
		co=co+1; //Se cuentan las combinaciones
		}
	}
	
	printf("Son %d combinaciones posibles", co);
	//Se imprime el número de combinaciones
}



