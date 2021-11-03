//Montserrat ALejandra Ulloa Rivera
//Objetivo: crear una pila a partir de nodos simplemente enlazados que guarde un string
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

struct node
{
	string data;
	node *link;
}*p;

void crearPila(string x)
{
	p=new node;
	p->data=x;
	p->link=NULL;
}

void push(string x)
{
	node *q;
	q=p; // el auxiliar apunta a la pila
	crearPila(x);
	p->link=q;
}

void pop()
{
	string num;
	node *q;
	q=p;
	
	if (q == NULL)
	{
		cout<<" \nLa pila esta vacia \n";
		Sleep(1000);
		return;
	}
	
	p=q->link;
	num = q->data; //Pasamos el primer valor de la pila
	delete q;
	cout<<"\nElemento:" << num << "que estaba al Inicio de la Pila ha sido eliminado\n";
}

void mostrar_pila()
{
	node *q;
	q=p;
	if ( q == NULL ) // igual a 0
	{
		cout<<"\n La Pila esta Vacia\n";
		Sleep(1000);
		return;
	}
	cout<<" Mostrando Pila "<<endl;
	while ( q != NULL)
	{
		 cout<<"\t"<<q->data<<endl;
		 q=q->link; // el ultimo elemento insertado tiene 0 en link
	}
	cout<<endl;
	Sleep(1000);
}

void vaciar_pila( )
{
	node *q;
	q=p;
	if ( q == NULL)
	{
		cout<<" \nLa Pila ya esta Vacia\n";
		return;
	}
	 
	while( q != NULL)
	{
		p = q->link;
		delete(q);
		q=p;
	}
}

int main(){
	int x;
	string n;
	bool out=false;
	do{
		system("CLS");
		cout << "PILAS CON NUMEROS" << endl;
		cout << "OPCIONES" << endl;
		cout << "1. A\244adir elemento (PUSH)" << endl;
		cout << "2. Eliminar elemento (POP)" << endl;
		cout << "3. Vaciar pila" << endl;
		cout << "4. Mostrar pila" << endl;
		cout << "5. Salir" << endl;
		cin >> x;
	
		switch(x){
			case 1: {
				cout << "Elemento a a\244adir: " << endl;
				cin >> n;
				push(n);
				break;
			}
			
			case 2: {
				pop();
				break;
			}
			
			case 3: {
				vaciar_pila();
				break;
			}
			
			case 4: {
				mostrar_pila();
				break;
			}
			
			case 5: {
				out = true;
				break;
			}
			
			default: {
				cout << "La opción ingresada es incorrecta" << endl;
				break;
			}
		}
	}while(out==false);
	return 0;
	
}
