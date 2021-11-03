//Montserrat Alejandra Ulloa Rivera 
//Lista simple
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

struct node
{
	int data;
	node *link;
}*p, *q;

void crearLista(int x)
{
	p=new node; //Reserva la memoria
	//q=new node;
	p->data=x;
	p->link=NULL;
}

void insInicio(int x)
{	
	if(p==NULL){crearLista(x);}
	else
	q=p; // la lista
	p=new node;
	p->data=x;
	p->link=q;
	//Sleep(500);
}

void insFinal(int x)
{
	node *q,*t;
	if(p==NULL){crearLista(x);}
	else
	{
		q=p; // ya hay elementos toda la lista p la pasas a q
		while(q->link!=NULL) // recorres hasta el final q->link = 0
			q=q->link;
		t=new node; // creas nodo
		t->data=x; // inserta dato
		t->link=NULL; // link = 0
		q->link=t; // el ultimo nodo = t
	}
	//Sleep(500);
}

void elmInicio()
{
	node *q;
	q=p; // la lista
	if(p==NULL){cout<<"\nNo hay valores para eliminar\n"; Sleep(700);}
	else 
		p=p->link;
		delete(q);
	//Sleep(500);
}

void elmFinal()
{
	node *q, *t;
	q=p; // la lista
	t=p;
	if(p==NULL){cout<<"\nNo hay valores para eliminar\n"; Sleep(700); return;}
	else
		while(q->link!=NULL) /* recorres hasta el final q->link = 0 */ q=q->link;
		while(t->link!=q) /* recorres hasta el final q->link = 0 */ t=t->link;
		getchar();
		//getchar();
		t->link=NULL;
		delete(q);
	//Sleep(500);
		
}

void show()
{
	node *q;
	q=p;
	if(q==NULL){cout<<"\nNo hay datos para Mostrar\n"; return;}
		while(q->link!=NULL)
		{
			cout<<"  "<<q->data<<" ";
			q=q->link; //Apunta a su liga
		}cout<<"  "<<q->data<<" "; //Imprime el ultimo dato
}

void insAntes(int x, int pos)
{	
	node *q;
	node * t =new node;
	//node * r =new node;
	q=p;
	if(p==NULL){crearLista(x);return;}
	for(int i=1; i<pos-1; i++){
		q=q->link;
		if(q->link==NULL){cout<<"La posicion dada no existe"; Sleep(700); break;}
	}
	t->link=q->link;
	t->data=x;
	q->link=t;
	//Sleep(500);
}

void insDesp(int x, int pos)
{	
	
	node *q;
	node * t =new node;
	node * r =new node;
	q=p;
	if(p==NULL){crearLista(x);return;}
	for(int i=1; i<pos; i++){
		cout<<q->data;
		q=q->link;
		if(q->link==NULL){cout<<"La posicion dada no existe"; Sleep(700); break;}
	}
	t->data=x;
	r=q->link;
	q->link=t;
	t->link=r;
	//Sleep(500);
}

void BuscarElemento(int n)
{	
	
	node *q;
	q=p;
	int c=0;
	do{
		c++;
		if(q->link==NULL){cout<<"No se encontro el dato";break;}
		if(n==q->data){cout<<"El dato se encuentra en la posicion "<<c<<" ";break;}
		q=q->link;
	}while(n!=q->data);
	Sleep(700);
}

void menu(){
	show();
	cout<<endl<< "       OPCIONES";
	cout<<endl<< "1. Insertar al inicio"<<endl;
	cout<< "2. Insertar al final"<<endl;
	cout<< "3. Eliminar al inicio"<<endl;
	cout<< "4. Eliminar al final"<<endl;
	cout<< "5. Insertar antes"<<endl;
	cout<< "6. Insertar despues"<<endl;
	cout<< "7. Buscar Elemento"<<endl;
	cout<< "8. Salir"<<endl;
	
}

int main (){
	int x, n, pos, v=1;
	do{
		system("cls");
		menu();
		cin >> x;
		system("cls");
		menu();
		switch(x){
			case 1:{
				cout<<"Dato a insertar:";
				cin >> n;
				insInicio(n);
				break;
			}
			
			case 2:{
				cout<<"Dato a insertar:";
				cin >> n;
				insFinal(n);
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
				cout<<"Posicion: ";
				cin >> pos;
				cout<<"Dato a insertar:";
				cin >> n;
				insAntes(n, pos);
				break;
			}
			
			case 6:{
				cout<<"Posicion: ";
				cin >> pos;
				cout<<"Dato a insertar:";
				cin >> n;
				insDesp(n, pos);
				break;
			}
			
			case 7: {
				cout<<"Elemento a buscar: ";
				cin >> n;
				BuscarElemento(n);
				break;
			}
			case 8: {
				v = 0;
				break;
			}
			default: {
				cout<<"Opcion invalida";
				break;
			}
		}
	}while (v!=0);
}

