#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
struct libreria {
    char autor[75];
    char nombre [100];
    unsigned long precio;
}*libros;

int main() {     
    int num, i, precio;
    
    printf("Cuantos libros desea ingresar: \n");
    scanf("%d",&num); fflush(stdin);
    
    libros=(struct libreria*)malloc(num*sizeof(struct libreria));
    
    for(i=0;i<num;i++){
        printf("Nombre %d: ", i+1);
        gets(libros[i]->nombre); fflush(stdin);  
        printf("Autor %d: ", i+1);
        gets(libros[i].autor); fflush(stdin);
        printf("Precio %d: ", i+1);
        scanf("%lu", &libros[i].precio); 
        precio=precio+libros[i].precio; fflush(stdin);
    }
    
    printf("Resumen de libros:\n");
    for(i=0; i<num;i++){
    	printf("\t%s de %s\n", libros[i].nombre, libros[i].autor);
	}
	printf("\t\tTotal: %d",precio);
    
    free(libros);
}





