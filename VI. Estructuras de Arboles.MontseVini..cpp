//Arbol de busqueda binaria
//Autores: Montserrat Alejandra Ulloa Rivera, Paulo Vinicio Martinez Roque     2"A"  ICI
//Fecha: 04/06/2019
/*Objetivo: Realice un programa en el que:

	1.	Inserte n n�mero de nodos
	2.	Busque o indique si existe o no el n�mero que solicite.
	3.	Obtenga la altura de un nodo
	4.	Obtenga la altura de todo el �rbol
	5.	Indique cu�ntos nodos tiene el �rbol
	6.	Muestre el �rbol por el M�todo de B�squeda Binaria.
	7.	Realice los recorridos por:
		a)	Preorden
		b)	Inorden
		c)	Postorden
	8.	Borre todo el �rbol.
	9.	Borre un nodo.

*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;


//Prototipos
void verArbol(Arbol a, int n);
void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void Mostrar(int *d);
 
main()
{
	setlocale(LC_ALL,"");
	
	Arbol ArbolInt=NULL;
   int altura;
   int nnodos;
   int x;
	
	//Menu ciclado 
	int flag=0, menu=0; 
	
	do
	{
		system("color F0");
		system("CLS");
		printf("\t  \t Arbol binario de busqueda\n");
		printf("\n\t\t -Men�-\n\n");
		printf("\t1.-  Mostrar arbol\n");
		printf("\t2.-  Insertar nodo\n");
		printf("\t3.-  Buscar nodo\n");
		printf("\t4.-  Obtener altura de un nodo\n");
		printf("\t5.-  Obtener la altura del arbol\n");
		printf("\t6.-  Indicar numero de nodos del arbol\n");
		printf("\t7.-  Realizar recorrido por Preorden\n");
		printf("\t8.-  Realizar recorrido por Inorden\n");
		printf("\t9.-  Realizar recorrido por PostOrden\n");
		printf("\t10.- Borrar un nodo\n");
		printf("\t11.- Borrar todo el arbol\n");
		printf("\t12.- Salir\n");
		printf("\n\tIngresar opci�n:  ");
		scanf("%d", &menu);
		
	switch(menu)
	{
		case 1: 
			system("CLS");
			printf("\n");
			verArbol(ArbolInt, 0);
			getchar();
			getchar();
			break;
		case 2:
			printf("\n\tDato a insertar: ");
			scanf("%d", &x);
			Insertar(&ArbolInt, x);
			
			break;
		case 3:
			printf("\n\tDato a buscar: ");
			scanf("%d", &x);
			if (Altura(ArbolInt, x)==-1)
				printf("\n\t-Dato no encontrado-");
			else
				printf("\n\tDato encontrado en altura %d", Altura(ArbolInt, x));
			getchar();
			getchar();
			break;
		case 4:
			printf("\n\tIngrese nodo del que desee saber su altura: ");
			scanf("%d", &x);
			if (Altura(ArbolInt, x)==-1)
				printf("\n\t-Dato no encontrado-");
			else
				printf("\n\tAltura del nodo: %d", Altura(ArbolInt, x));
			getchar();
			getchar();
			break;
		case 5:
			printf("\n\tAltura del arbol: %d\n", AlturaArbol(ArbolInt, &altura));
			getchar();
			getchar();
			break;
		case 6:
			printf("\n\tNumero de nodos del arbol: %d\n", NumeroNodos(ArbolInt, &nnodos));
			getchar();
			getchar();
			break;
		case 7:
			printf("\n\tPreOrden: ");
   			PreOrden(ArbolInt, Mostrar);
			getchar();
			getchar();
			break;
		case 8:
			printf("\n\tInOrden: ");
   			InOrden(ArbolInt, Mostrar);
   			getchar();
   			getchar();
   			break;
   		case 9:
   			printf("\n\tPostOrden: ");
   			PostOrden(ArbolInt, Mostrar);
   			getchar();
   			getchar();
   			break;
   		case 10:
   			printf("\n\tDato a eliminar: ");
			scanf("%d", &x);
			Borrar(&ArbolInt, x);
			printf("\n\t-Nodo eliminado-");
			getchar();
			getchar();
			break;
		case 11:
			Podar(&ArbolInt);
			printf("\n\tArbol eliminado");
			getchar();
			getchar();
			break;
		case 12:
			flag=1;
			break;
		default:
			    printf("\t-Opci�n inexistente-");
                getchar();
				getchar();
				system("cls");	
	}
	
	}while(flag==0);

	Podar(&ArbolInt);
	getchar();
	return 0;
}

/*  Muestra todo el arbor  */
void verArbol(Arbol a, int n)
{
	/* Algoritmo recursivo */
	if(a == NULL)
		return;
	verArbol(a->derecho, n+1);
	
	for (int i=0; i<n; i++)
		cout<<"   ";
		
	cout<< a->dato << endl;
	
	verArbol(a->izquierdo, n+1);	
}


/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol *a)
{
   /* Algoritmo recursivo, recorrido en postorden */
   if(*a) {
      Podar(&(*a)->izquierdo); /* Podar izquierdo */
      Podar(&(*a)->derecho);   /* Podar derecho */
      free(*a);                /* Eliminar nodo */
      *a = NULL;
   }
}

/* Insertar un dato en el �rbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el �rbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

/* Eliminar un elemento de un �rbol ABB */
void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor est� en el �rbol */
   while(!Vacio(actual)) {
      if(dat == actual->dato) { /* Si el valor est� en el nodo actual */
         if(EsHoja(actual)) { /* Y si adem�s es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }
         else { /* Si el valor est� en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo m�s izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo m�s derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
               de que s�lo se eliminan nodos hoja. */
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { /* Todav�a no hemos encontrado el valor, seguir busc�ndolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

/* Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

/* Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}

/* Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

/* Buscar un valor en el �rbol */
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No est� en �rbol */
}



/* Calcular la altura del nodo que contiene el dato dat */
int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; /* No est� en �rbol, devolver -1 */
}

/* Contar el n�mero de nodos */
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Funci�n auxiliar */
   return *contador;
}

/* Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(Arbol nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

/* Calcular la altura del �rbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Funci�n auxiliar */
   return *altura;
}

/* Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
   postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
   altura de la m�xima actual */
void auxAltura(pNodo nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      �rbol, actualizamos la altura actual del �rbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un �rbol es vac�o */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

/* Funci�n de prueba para recorridos del �rbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}

