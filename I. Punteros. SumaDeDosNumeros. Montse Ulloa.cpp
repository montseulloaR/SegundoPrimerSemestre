//SumaDe2numerosConPunteros
//Montserrat Alejandra Ulloa Rivera
//7/Marzo/2019

#include <stdio.h>
#include <conio.h>

void suma(int *Num, int *Num2) // <- Esto quiere decir que espero recibir una DIRECCION de memoria como parametro.
{
    int suma;
suma = *Num+*Num2;
printf("Valor de Suma : %d \n", suma);
}
int main(void)
{
int N = 5, N2 = 10;
printf("\n\nDe regreso de la Funcion:\n");
printf("Direccion de N, N2: %X, %X\n", &N, &N2);
printf("Valor de N, N2: %d, %d \n", N, N2);
suma(&N, &N2);
getchar();
return 0;
}
