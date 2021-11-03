//Montserrat Alejandra Ulloa Rivera 
//Lista simple
#include<iostream>
#include<stdlib.h>
#include<windows.h>


struct node
{
	int data;
	node *link;
}*p, *V1, *V2, *V3;

void crearLista()
{
	p =(struct node *)malloc(1*sizeof(struct node)); //Reserva la memoria
	p->data=rand() % 100 + 1;
	p->link=NULL;
}

void random(int e)
{	
	crearLista();
	
	for(int i=0; i<e; i++)
	{	
		p = (struct node *)malloc(1*sizeof(struct node));
		p->data = rand() % 100 + 1;
		p->link = V1; //Se agrega el dato al inicio de la lista
		V1 = p; 
	}
			//Sleep(500);
}

void show(node *V)
{
	if(V==NULL){printf("\nNo hay datos para Mostrar\n"); return;}
	
	while(V->link!=NULL)
	{
		printf(" [%d] ", V->data);
		V=V->link; //Apunta a su liga
	} printf(" [%d] ", V->data); //Imprime el ultimo dato
}



/*void insFinal(int x)
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
		while(q->link!=NULL) /* recorres hasta el final q->link = 0  q=q->link;
		while(t->link!=q) /* recorres hasta el final q->link = 0  t=t->link;
		getchar();
		//getchar();
		t->link=NULL;
		delete(q);
	//Sleep(500);
		
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

void BuscarElemento(int x, int n)
{	
	
	node *q;
	q=p;
	int c=0;
	do{
		c++;
		q=q->link;
		//if(q->link==NULL){cout<<"No se encontro el dato";break;}
		//if(n==q->data){cout<<"El dato se encuentra en la posicion"<<c<<" ";break;}
	}while(n!=q->data);
	Sleep(500);
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
	cout<< "7. Salir"<<endl;
}*/

int main (){
	int e;
	printf("Cuantos elementos desea ordenar:");
	scanf("%d", &e);
	
	random(e);
	show(V1);
	
	/*int x, n, pos, v=1;
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
				v = 0;
				break;
			}
			default: {
				cout<<"Opcion invalida";
				break;
			}
		}
	}while (v!=0);
	*/
}

