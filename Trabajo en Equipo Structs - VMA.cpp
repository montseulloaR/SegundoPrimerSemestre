
//Trabajo Structs con funciones
//Objetivo: 
//Autores: Paulo Vinicio Martinez Roque, Alejandra Montserrat Ulloa Rivera, Jesus Alejandro Martinez Martinez
//Fecha: 28 / 02 / 2019
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<windows.h>
#include<locale.h>
#include<time.h>

void imptabla();
void buscar();
void agregar();
void borrar();
void modificar();

struct datos{
	int clave;
	char nombre[15];
	double precio;
}producto[20];

int main()
{	
	system("color F0");
	setlocale(LC_ALL,"");
	srand(time(0)); 
	
	printf("\tEstructuras Computacionales\n\n");
	printf("\n\t\t-Trabajo de Structs con funciones-\n");
	printf("\n\t+ Paulo Vinicio Martinez Roque");
	printf("\n\t+ Alejandra Montserrat Ulloa Rivera");
	printf("\n\t+ Jesus Alejandro Martinez Martinez");
	Sleep(1000);	
	system("CLS");
	

	//Menu ciclado 
	int flag=0, menu=0;
	do
	{
		printf("\t   OTSO\n");
		printf("\n\t\t -Menú-\n\n");
		printf("\t1.- Mostrar lista de productos\n");
		printf("\t2.- Buscar un producto\n");
		printf("\t3.- Agregar nuevo registro producto\n");
		printf("\t4.- Eliminar un registro de un producto\n");
		printf("\t5.- Modificar un registro de producto\n");
		printf("\t6.- Salir\n");
		printf("\n\tIngresar opción:  ");
		scanf("%d", &menu);
		
	switch(menu)
	{
		case 1: 
				system("cls");
				imptabla(); 
				getchar(); getchar(); system("cls");
			break;
		case 2:
				system("cls");
				buscar();
				getchar(); system("cls");
			break;
		case 3:
				system("cls");
				agregar();
				getchar(); getchar(); system("cls");
			break;
		case 4:
				system("cls");
				borrar();
				getchar(); system("cls");
			break;
		case 5:
				system("cls");
				modificar();
				getchar(); system("cls");
			break;
		case 6:
				flag=1;
				system("cls");
				break;
		default:
			    printf("\t-Opción inexistente-");
                getchar();
				getchar();
				system("cls");	
	}
	
	}while(flag==0);
	system("CLS");
	//Creditos
	printf("\n\n\t\tHecho por:");
	printf("\n\t-Paulo Vinicio Martinez Roque");
	printf("\n\t-Jesus Alejandro Martinez Martinez");
	printf("\n\t-Alejandra Montserrat Ulloa Rivera");
	getchar();
	getchar();
	return 0;
}

void imptabla()
{
	int i;
	printf("\n\tClave\t ||\t   Precio ||\t\tNombre\n");
	printf("    ------------------------------------------------------------------------");
	for (i=0; i<20; i++)
	{
		if(producto[i].clave != 0){
		printf("\n \t %d    |", producto[i].clave);
		printf("| \t$  %.2lf\t|", producto[i].precio);
		printf("| \t%s", producto[i].nombre); }
	}	
}



void buscar()
{
	int i, op, bclave;
	int flagb=0, f;
	char bn[10], a1[10], a2[10];
	do{
	f=0;
	printf("\n       Desea buscar un registro por:");
	printf("\n\n\t1.- Clave");
	printf("\n\t2.- Nombre");
	printf("\n\t3.- Regresar al menu anterior");
	printf("\n\nIngrese Opción de busqueda:  ");
	scanf("%d", &op);
	
	switch(op)
	{
		case 1:
			system("cls");
			printf("\nIngrese la clave que busca:  ");
			scanf("%d", &bclave);
			
			for(i=0; i<20; i++)
			{
				if( bclave == producto[i].clave)
				{
					system("cls");
					printf("\n\tClave\t ||\t   Precio  \t||\t\tNombre\n");	
					printf("    ------------------------------------------------------------------------");
					printf("\n \t %d    |", producto[i].clave);
					printf("| \t$  %.2lf\t|", producto[i].precio);
					printf("| \t%s", producto[i].nombre);
					f=1;	
					getchar(); getchar(); 			
				}	
			}
			if (f==0){
				system("cls");
				printf("\n\n\n\t--No se encontro el registro--"); getchar(); getchar();
			}

			system("cls");
			break;
		case 2:
			system("cls");
			printf("\nIngrese el nombre del producto que busca:  ");
			fflush( stdin );
			scanf("%s", &bn);

			for(i=0; i<20; i++)
			{
				if( strcmp(bn, producto[i].nombre) == 0 )
				{
					system("cls");
					printf("\n\tClave\t ||\t   Sueldo  \t||\t\tNombre\n");
					printf("    ------------------------------------------------------------------------");	
					printf("\n \t %d    |", producto[i].clave);
					printf("| \t$  %.2lf\t|", producto[i].precio);
					printf("| \t%s ", producto[i].nombre);
					f=1;	
					getchar(); getchar(); 
				}	
			}
			if (f==0){
				system("cls");
				printf("\n\n\n\t--No se encontro el registro--"); getchar(); getchar();
			}

			system("cls");
			break;
		case 3:
			flagb=1;
			system("cls");
			break;
		default: 
				printf("\t-Opción inexistente-"); getchar(); getchar(); system("cls");	
	}
	
	}while(flagb==0);
	
	
}

void agregar()
{
	int i, x, y;
	printf("\n\tAgregar nuevo registro\n");
	
	for (i=0; i<20; i++)
	{
		if(producto[i].clave == 0){
			regreso:
			printf("\nIngresa la clave del nuevo producto: ");
			scanf("%d",&x);
			if (x<1000||x>9999)
			{
				printf("\n\n\t--La clave tiene que ser de cuatro cifras--");
				getchar();
				getchar();
				system("cls");
				goto regreso;
			}
			else{producto[i].clave=x;}
			printf("Ingrese el nombre del producto: ");
			fflush( stdin );
			scanf("%s", producto[i].nombre);
			printf("Ingrese el precio del producto: ");
			scanf("%lf", &producto[i].precio);
			printf("\n\t-Registro guardado exitosamente-");
			i=20;
		}
	}

}

void borrar()
{
	int i, eclave;
	printf("\n\tClave\t ||\t   Precio  \t||\t\tNombre\n");
	printf("    ------------------------------------------------------------------------");
	for (i=0; i<20; i++)
	{
		if(producto[i].clave != 0){
		printf("\n \t %d    |", producto[i].clave);
		printf("| \t$  %.2lf\t|", producto[i].precio);
		printf("| \t%s ", producto[i].nombre); }
	}	
	printf("\n\nIngrese la clave del registro que desea borrar: ");
	scanf("%d", &eclave);
	for (i=0; i<20; i++)
	{
		if(producto[i].clave == eclave)
		{
			producto[i].clave = 0;
			producto[i].clave=0;
			memset(producto[i].nombre,'\0',10);
			printf("\n\n\t-Registro borrado con exito-");
			goto salto;
		}
	}
	printf("\n\n\t-No se encontro registro-");
	salto:	
	getchar();
}

void modificar()
{
	int i, mclave, c1, x;
	printf("\n\tClave\t ||\t   Precio  \t||\t\tNombre\n");
	printf("    ------------------------------------------------------------------------");
	for (i=0; i<20; i++)
	{
		if(producto[i].clave != 0){
		printf("\n \t %d    |", producto[i].clave);
		printf("| \t$  %.2lf\t|", producto[i].clave);
		printf("| \t%s", producto[i].nombre); }
	}	
	printf("\n\nIngrese la clave del registro que desea modificar: ");
	scanf("%d", &mclave);
	for (i=0; i<20; i++)
	{
		if(producto[i].clave == mclave)
		{
			printf("\nDe las opciones: \n1.- Clave\n2.- Nombre\n3.- Precio\n4.- Regresar al menu\n\nIngrese campo que quiera modificar:  ");
			scanf("%d", &c1);
			switch(c1)
			{
				case 1:
						regreso:
						printf("\nIngresa la clave del nuevo producto: ");
						scanf("%d",&x);
						if (x<1000||x>9999)
						{
							printf("\n\n\t--La clave tiene que ser de cuatro cifras--");
							getchar();
							getchar();
							system("cls");
							goto regreso;
						}
						else{producto[i].clave=x;}
						printf("\n\t-Registro modificado exitosamente-");
					break;
				case 2:
						printf("\nIngrese el nuevo nombre del producto: ");
						fflush( stdin );
						scanf("%s", producto[i].nombre);
						printf("\n\t-Registro modificado exitosamente-");
					break;
				case 3:
						printf("\nIngrese el nuevo precio del producto: ");
						scanf("%lf", &producto[i].precio);
						printf("\n\t-Registro modificado exitosamente-");
					break;
				case 4:
						goto chao;
					break;
				default:
					printf("\t-Opción inexistente-"); getchar(); getchar(); system("cls");	
			
			}
			goto chao;
		}
		
	}
	printf("\n\n\t-No se encontro registro-");
	chao:
	getchar();	
	
}
