//Montserrat ALejandra Ulloa Rivera
//Objetivo: crear una cola a partir de nodos simplemente enlazados
#include <iostream>
#include <stdlib.h>
#include <windows.h>
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
	node *q,*t;
	if(p==NULL)
	{
		p=new node;
		p->data=x;
		p->link=NULL;
	}
	else
	{ //El auxiliar apunta a la cola
		q=p; // ya hay elementos, q apunta a toda la cola
		while(q->link!=NULL) // Recorres la cola hasta el final q->link = 0
		q=q->link;
		t=new node; // creas nodo
		t->data=x; // inserta dato
		t->link=NULL; // link = 0
		q->link=t; // el ultimo nodo = t
	}
	cout<<" Elemento: " <<x<<" ha sido Insertado. "<<endl;
	Sleep(1000);
}


void pop()
{
	string num;
	node *q;
	q=p;
	if(q==NULL)
	{
		cout<<" \nLa cola esta Vacia\n";
		Sleep(1000);
		return;
	}
	num=q->data;
	p=q->link;
	delete q;
	cout<<"\nElemento: "<<num<<" al Inicio de la cola ha sido Eliminado!!\n"<<endl;
	Sleep(1000);
}

void mostrar_cola()
{
	node *q;
	q=p;
	if(q==NULL) // Llego al final de la Cola
	{
		cout<<"\n La Cola esta Vacia.. \n";
		Sleep(1000);
		return;
	}
	cout<<" Mostrando Elementos en la Cola "<<endl;
	while(q!=NULL)
	{
		 cout<<" "<<q->data<<" ";
		 q=q->link; // el ultimo elemento insertado tiene 0 en link
	}
	cout<<endl;
	Sleep(1000);
}


void vaciar_cola( )
{
	 node *q;
	
	 if ( p == NULL)
	 {
		cout<<" \nLa Cola esta Vacia\n";
		Sleep(1000);
		return;
	 }
	 while( p != NULL)
	 {
		q=p;
		p = q->link;
		delete(q);
	 }
	 cout<<"\n LA COLA YA SE ELIMINO....\n ";
	 Sleep(1000);
}


int main(){
	int x;
	string num;
	bool out=false;
	do{
		system("CLS");
		cout << "COLAS CON NUMEROS" << endl;
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
				cin >> num;
				push(num);
				break;
			}
			
			case 2: {
				pop();
				break;
			}
			
			case 3: {
				vaciar_cola();
				break;
			}
			
			case 4: {
				mostrar_cola();
				break;
			}
			
			case 5: {
				out = true;
				break;
			}
			
			default: {
				cout << "La opcion ingresada es incorrecta" << endl;
				Sleep(1000);
				break;
			}
		}
	}while(out==false);
	return 0;
	
}

