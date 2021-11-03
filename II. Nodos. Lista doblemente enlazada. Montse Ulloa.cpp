//Montserrat Alejandra Ulloa Rivera 
//Lista doble
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include <ctime>

struct nodo
{
 int dato;
 struct nodo *siguiente;
 struct nodo *anterior;
}*V1, *V2, *V3, *p, *temp2;

void create(int x)
{
	p =(struct nodo *)malloc(1*sizeof(struct nodo));
	p->anterior = NULL;
	p->siguiente = NULL;
	p->dato = x;
}

void random(int e)
{	srand(time(NULL));
	create(rand() % 100 + 1);
	
	for(int i=0; i<e; i++)
	{	
		create(rand() % 100 + 1);
		p->dato = rand() % 100 + 1;
		p->siguiente = V1; //Se agrega el dato al inicio de la lista
		V1 = p; 
	}
	
}

void mostrar(nodo *V)
{
	temp2 = V;
	if (temp2 == NULL)
	{
		printf("\n La lista a mostrar esta vacia \n");
		return;
	}
	 
	while (temp2->siguiente != NULL)
 	{
 		if(temp2->anterior==NULL) {printf("-");}
		printf(" [%d] ", temp2->dato);
		temp2 = temp2->siguiente;
	}
	if(temp2->anterior==NULL) {printf("-");}
	printf(" [%d] ", temp2->dato);
}

void PrimeraParticion(){
	nodo *t1 = V1, *t2, *t3;
	bool v2=true, primero3 = true;
	
	create (t1->dato);
	t2 = p;
	V2 = t2;
	t1 = t1->siguiente;
	do {
		if((t1->siguiente!=NULL)&&(t2->dato < t1->dato)&&(v2 == true)){ 
			printf("a");
			create(t1->dato);
			t2->siguiente = p;
			p->anterior = t2;
			t2 = p;
			t1 = t1->siguiente;
		}
		else if (v2==true&&(t1->siguiente!=NULL)){
			
			if (primero3 == true){
				printf("b");
				create (t1->dato);
				t3 = p;
				V3 = t3;
				t1 = t1->siguiente;				
				primero3 = false;
				v2 = false;
			}
			
			else {
				printf("c");
				v2 = false;
				create(t1->dato);
				t3->siguiente = p;
				t3 = p;
				t1 = t1->siguiente;	
			}

		}
		
		 if((t1->siguiente!=NULL)&&(t3->dato < t1->dato)&&(v2==false)){ 
		 printf("d");
			create(t1->dato);
			t3->siguiente = p;
			p->anterior = t3;
			t3 = p;
			t1 = t1->siguiente;
			
		}	
		else if (v2==false&&(t1->siguiente!=NULL)){
			printf("e");
			create(t1->dato);
			t2->siguiente = p;
			t2 = p;
			v2 = true;
			t1 = t1->siguiente;
			
		}
		printf("\n");
	} while(t1->siguiente!=NULL);
	
	if(v2==false){
		create(t1->dato);
		t2->siguiente = p;
		t2 = p;
	}
	
	if(v2==true){
		create(t1->dato);
		t3->siguiente = p;
		t3 = p;
	}
	printf("\n ");
	mostrar(V2);
	printf("\n ");
	mostrar(V3);
}

void Regresar(){
	nodo *t1 = V1, *t2 = V2, *t3 = V3, *aux;
	bool nuevo = true;
	//bool New3 = true, New2 = true;

	do {
		printf("\n");
			//Inicio de comparación de dos grupos
			if(t2->anterior==NULL&&(t3->anterior==NULL)&&(t1->siguiente!=NULL)){
				if(t2->dato < t3->dato){
					printf(" A ");
					t1->dato = t2->dato;
					if(t2->siguiente!=NULL){t2 = t2->siguiente;}
					t1 = t1->siguiente;
					
					/*if(t2->anterior == NULL){
						while (t3->anterior!=NULL){
							t1->dato = t3->dato;
							if(t3->siguiente!=NULL){t3 = t3->siguiente;}
							t1 = t1->siguiente;
						}
					}*/
					
				}
				
				else if(t3->dato < t2->dato){
					printf(" B ");
					t1->dato = t3->dato;
					if(t3->siguiente!=NULL){t3 = t3->siguiente;}
					t1 = t1->siguiente;
					nuevo = nuevo * false;

					if(t3->anterior == NULL){
						while (t2->anterior!=NULL){
							t1->dato = t2->dato;
							if(t2->siguiente!=NULL){t2 = t2->siguiente;}
							t1 = t1->siguiente;
						}
					}
				}
			}
			
			//PRIMERAS COMPARACIONES
			
			if((t2->dato < t3->dato)&&(t1->siguiente!=NULL)&&(t2->anterior!=NULL)){ 
				t1->dato = t2->dato;
				t1 = t1->siguiente;
				if(t2->siguiente!=NULL){t2 = t2->siguiente;}
				printf(" C ");
				
				if(t2->anterior == NULL){
						while (t3->anterior!=NULL){
							t1->dato = t3->dato;
							if(t3->siguiente!=NULL){t3 = t3->siguiente;}
							t1 = t1->siguiente;
						}
					}
			}

			else if((t3->dato < t2->dato)&&(t1->siguiente!=NULL)&&(t3->anterior!=NULL)) {
				t1->dato = t3->dato;
				t1 = t1->siguiente;
				if(t3->siguiente!=NULL){t3 = t3->siguiente;}
				printf(" D ");
				
				if((t3->anterior == NULL)&&(t2->anterior==NULL)){
							t1->dato = t2->dato;
							if(t2->siguiente!=NULL){t2 = t2->siguiente;}
							t1 = t1->siguiente;
					}
			}
			
			else if((t2->dato<t3->dato)&&(t1->siguiente!=NULL)&&(t3->anterior!=NULL)){
				t1->dato = t2->dato;
				t1 = t1->siguiente;
				if(t2->siguiente!=NULL){t2 = t2->siguiente;}
				printf(" E ");
			}
			
			else if((t3->dato<t2->dato)&&(t1->siguiente!=NULL)&&(t2->anterior!=NULL)){
				t1->dato = t3->dato;
				t1 = t1->siguiente;
				if(t3->siguiente!=NULL){t3 = t3->siguiente;}
				printf(" F ");
			}
			//printf("\n2.si\n");
			
			if(t3->dato < t2->dato&&(t1->siguiente!=NULL)&&(t2->anterior!=NULL)){
				t1->dato = t3->dato;
				t1 = t1->siguiente;
				if(t3->siguiente!=NULL){t3 = t3->siguiente;}
				printf(" G ");
				
				if(t3->anterior == NULL){
						while (t2->anterior!=NULL){
							t1->dato = t2->dato;
							if(t2->siguiente!=NULL){t2 = t2->siguiente;}
							t1 = t1->siguiente;
						}
					}
			}
			else if((t2->dato < t3->dato)&&(t1->siguiente!=NULL)&&(t3->anterior!=NULL)) {
				t1->dato = t2->dato;
				t1 = t1->siguiente;
				if(t2->siguiente!=NULL){t2 = t2->siguiente;}
				printf(" H ");
				
				if(t2->anterior == NULL){
						while (t3->anterior!=NULL){
							t1->dato = t3->dato;
							if(t3->siguiente!=NULL){t3 = t3->siguiente;}
							t1 = t1->siguiente;
						}
					}
			}
			
			else if((t2->dato<t3->dato)&&(t1->siguiente!=NULL)&&(t2->anterior!=NULL)){
				t1->dato = t2->dato;
				t1 = t1->siguiente;
				if(t2->siguiente!=NULL){t2 = t2->siguiente;}
				printf(" I ");
			}
			
			else if((t3->dato<t2->dato)&&(t1->siguiente!=NULL)&&(t3->anterior!=NULL)){
				t1->dato = t3->dato;
				t1 = t1->siguiente;
				if(t3->siguiente!=NULL){t3 = t3->siguiente;}
				printf(" J ");
			}
			
			
	printf("\n");		
	mostrar(V1);

	}while (t1->siguiente!=NULL);
	printf("\n");
	mostrar(V1);
}


int main() 
{ 
	int e;
	printf("Cuantos elementos desea ordenar: ");
	scanf("%d", &e);
	system("cls");
	
    random(e);   
    // Find the maximum element 
    //int max = arr[0]; 
    /*for (int i = 1; i < len; i++) 
        if (a[i] > max) 
           max = a[i]; */
  
    printf("||Vector aleatorio con %d elementos||\n", e); 
    mostrar(V1); 
    system("pause");
    PrimeraParticion();
    Regresar();
    
  /*
    printf("\n||Vector ordenado|| \n"); 
    printArray(arr, e); */
    return 0; 
} 
