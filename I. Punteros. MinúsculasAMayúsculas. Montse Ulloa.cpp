//Montserrat Alejandra Ulloa Rivera
//Fecha de entrega: 11/03/2019
//Min�sculas a May�sculas 
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
char cadena[10];
int main(){
	
	char *cad;
	int x;
	
	printf("Escribe una oracion\n");
	gets(cadena); system("cls");
	printf("A que quiere convertir. \n1.Mayusculas \n2. Minusculas\n");
	scanf("%d", &x);
	
	switch(x){
		case 1: {
			for(int i=0; i<10; i++){
				cad = &cadena[i]; // El apuntador 'cad' apunta a la direcci�n de memoria de cadena en la posici�n "i"
				strupr(cad);
			//	printf("%c",cadena[i]);
			}
			break;
		}
		case 2: {
			for(int i=0; i<10; i++){
				cad = &cadena[i]; // El apuntador 'cad' apunta a la direcci�n de memoria de cadena en la posici�n "i"
				strlwr(cad);
			//	printf("%c",cadena[i]);
			}
			break;
		}
	}
	
	printf("Palabra convertida: \n");
	printf("%s\n",cadena);
	system("pause");
	return 0;
	
}
