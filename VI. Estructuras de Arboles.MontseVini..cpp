//Arbol de busqueda binaria
//Autores: Montserrat Alejandra Ulloa Rivera, Paulo Vinicio Martinez Roque     2"A"  ICI
//Fecha: 04/06/2019
/*Objetivo: Realice un programa en el que:

	1.	Inserte n número de nodos
	2.	Busque o indique si existe o no el número que solicite.
	3.	Obtenga la altura de un nodo
	4.	Obtenga la altura de todo el árbol
	5.	Indique cuántos nodos tiene el árbol
	6.	Muestre el árbol por el Método de Búsqueda Binaria.
	7.	Realice los recorridos por:
		a)	Preorden
		b)	Inorden
		c)	Postorden
	8.	Borre todo el árbol.
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
		printf("\n\t\t -Menú-\n\n");
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
		printf("\n\tIngresar opción:  ");
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
			    printf("\t-Opción inexistente-");
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

/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
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

/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) {
      if(dat == actual->dato) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo más derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qué ser un nodo hoja, cerrando el bucle nos aseguramos
               de que sólo se eliminan nodos hoja. */
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

/* Recorrido de árbol en inorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

/* Recorrido de árbol en preorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}

/* Recorrido de árbol en postorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

/* Buscar un valor en el árbol */
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No está en árbol */
}



/* Calcular la altura del nodo que contiene el dato dat */
int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}

/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}

/* Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(Arbol nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Función auxiliar */
   return *altura;
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(pNodo nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}

