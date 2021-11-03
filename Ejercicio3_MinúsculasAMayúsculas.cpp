//Montserrat Alejandra Ulloa Rivera
//Fecha de entrega: 11/03/2019
//Minúsculas a Mayúsculas 
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
				cad = &cadena[i]; // El apuntador 'cad' apunta a la dirección de memoria de cadena en la posición "i"
				strupr(cad);
			//	printf("%c",cadena[i]);
			}
			break;
		}
		case 2: {
			for(int i=0; i<10; i++){
				cad = &cadena[i]; // El apuntador 'cad' apunta a la dirección de memoria de cadena en la posición "i"
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
