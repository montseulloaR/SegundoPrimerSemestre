//Montserrat Alejandra Ulloa Rivera 
//Colas con lista doble
#include<iostream>
#include<stdlib.h>
#include<windows.h>

struct nodo
{
 int dato;
 struct nodo *siguiente;
 struct nodo *anterior;
}*adelante, *pnodo, *atras, *temp2;

void create()
{
	 int data;
	 pnodo =(struct nodo *)malloc(1*sizeof(struct nodo));
	 pnodo->anterior = NULL;
	 pnodo->siguiente = NULL;
	 printf("Valor: ");
	 scanf("%d", &data);
	 pnodo->dato = data;
}

void inserta_fin()
{
	 if (adelante == NULL)
	 {
	 create();
	 adelante = pnodo;
	 atras = adelante;
	 }
	 else
	 {
	 create();
	 atras->siguiente = pnodo;
	 pnodo->anterior = atras;
	 atras = pnodo;
	 }
}

void mostrarA()
{
	 temp2 = adelante;
	 if (temp2 == NULL)
	 {
		 printf("\n La lista a mostrar esta vacia \n");
		 return;
	 }
	 
	 while (temp2->siguiente != NULL)
	 {
		 printf(" [%d] ", temp2->dato);
		 temp2 = temp2->siguiente;
	 }
	 printf(" [%d] ", temp2->dato);
}

void vaciarPila(){
    temp2 = adelante;
     if (temp2 == NULL)
     {
         printf("\n La lista esta vacia \n");
     }

     while (temp2->siguiente != NULL)
     {
         temp2 = adelante->siguiente;
		 free(adelante);
		 adelante=temp2;
     }
     adelante=NULL;
}

void elmInicio()
{
	temp2=adelante;
	if(adelante==NULL){printf("\nNo hay valores para eliminar\n"); Sleep(700); return;}
	if(adelante->siguiente==NULL){adelante=NULL; return;}
	else 
		adelante=adelante->siguiente;
		adelante->anterior=NULL;
		free(temp2);
	//Sleep(500);
}

void menu(){
	mostrarA();
	printf( "\n    OPCIONES COLAS\n");
	printf(  "1. Agregar elemento (PUSH)\n");
	printf(  "2. Eliminar elemento (POP)\n");
	printf(  "3. Vaciar cola\n");
	printf(  "4. Mostrar cola\n");
	printf(  "5. Salir\n");
}

int main (){
	int x, n;
	bool salir=false;
	do{
		system("cls");
		menu();
		scanf("%d", &x);
		system("cls");
		menu();
		switch(x){
			case 1:{
				inserta_fin();
				break;
			}

			case 2:{
				elmInicio();
				break;
			}

			case 3:{
				vaciarPila();
				break;
			}

			case 4: {
				mostrarA();
				break;
			}

			case 5: {
				salir = true;
				break;
			}

			default: {
				printf( "Opcion invalida");
				break;
			}
		}
	}while (salir!=true);
}

