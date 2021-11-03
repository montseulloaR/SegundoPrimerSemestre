//Montserrat Alejandra Ulloa Rivera 
//Lista doble
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

void inserta_ini()
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
	 pnodo->siguiente = adelante;
	 adelante->anterior = pnodo;
	 adelante = pnodo;
 }
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

void mostrarD()
{
 temp2 = atras;
 if (temp2 == NULL)
 {
	 printf("\n La lista a mostrar esta vacia \n");
	 Sleep(2000);
	 return;
 }

 while (temp2->anterior != NULL)
 {
	 printf(" [%d]", temp2->dato);
	 temp2 = temp2->anterior;
 }
 printf(" [%d] ", temp2->dato);
 Sleep(700);
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

void elmFinal()
{
	temp2=atras;
	if(adelante==NULL){printf( "\nNo hay valores para eliminar\n"); Sleep(700); return;}
	if(adelante->siguiente==NULL){adelante=NULL; return;}
	else
		atras=atras->anterior;
		atras->siguiente=NULL;
		temp2->anterior=NULL;
		free(temp2);
	//Sleep(500);
		
}

void BuscarElemento(int n)
{	
	if (adelante == NULL){printf("La lista esta vacia, no hay datos para buscar"); Sleep(2000); return;}
	temp2=adelante;
	int c=1;
	do
	{
		if(temp2->siguiente==NULL){printf( "No se encontro el dato"); Sleep(700); return;}
		temp2=temp2->siguiente;
		c++;
	}while(n!=temp2->dato);
	printf( "El dato se encuentra en la posicion: %d", c);
	Sleep(700);
}

void insAntes(int pos){
	if (adelante == NULL){printf("La lista esta vacia, no se puede insertar antes"); Sleep(2000); return;}
	temp2=adelante;
		create();
		for(int i=1; i<pos-1; i++){
			temp2=temp2->siguiente;
			if(temp2->siguiente==NULL){printf("La posicion dada no existe"); free(pnodo); Sleep(1000); return;}
		}
		pnodo->anterior=temp2;
		pnodo->siguiente=temp2->siguiente;
		temp2->siguiente=pnodo;
		temp2=temp2->siguiente;
		pnodo=pnodo->siguiente;
		pnodo->anterior=temp2;
	//Sleep(500);
}

void insDespues(int pos){
	if (adelante == NULL){printf("La lista esta vacia, no se puede insertar despues"); Sleep(2000); return;}
	temp2=adelante;
		create();
		for(int i=1; i<pos; i++){
			temp2=temp2->siguiente;
			if(temp2->siguiente==NULL){printf("La posicion dada no existe"); free(pnodo); Sleep(1000); return;}
		}
		pnodo->anterior=temp2;
		pnodo->siguiente=temp2->siguiente;
		temp2->siguiente=pnodo;
		temp2=temp2->siguiente;
		pnodo=pnodo->siguiente;
		pnodo->anterior=temp2;
	//Sleep(500);
}

void menu(){
	mostrarA();
	printf( "\n       OPCIONES\n");
	printf(  "1. Insertar al inicio \n");
	printf(  "2. Insertar al final \n");
	printf(  "3. Eliminar al inicio \n");
	printf(  "4. Eliminar al final \n");
	printf(  "5. Insertar antes \n");
	printf(  "6. Insertar despues \n");
	printf(  "7. Buscar Dato \n");
	printf(  "8. Mostrar lista desde el ultimo dato hasta el primero\n");
	printf(  "9. Salir \n");
}

int main (){
	int x, n, pos, v=1;
	do{
		system("cls");
		menu();
		scanf("%d", &x); 
		system("cls");
		menu();
		switch(x){
			case 1:{
				inserta_ini();
				break;
			}
			
			case 2:{
				inserta_fin();
				break;
			}
			
			case 3:{
				elmInicio();
				break;
			}
			
			case 4:{
				elmFinal();
				break;
			}
			
			case 5:{
				printf( "Posicion: ");
				scanf("%d", &pos);
				fflush(stdin);
				insAntes(pos);
				break;
			}
			
			case 6:{
				printf( "Posicion: ");
				scanf("%d", &pos);
				fflush(stdin);
				insDespues(pos);
				break;
			}
			
			case 7: {
				printf("Elemento a buscar: ");
				scanf("%d", &n);
				BuscarElemento(n);
				break;
			}
			
			case 8: {
				mostrarD();
				break;
			}
			
			case 9: {
				v = 0;
				break;
			}
			
			default: {
				printf( "Opcion invalida");
				break;
			}
		}
	}while (v!=0);
}

