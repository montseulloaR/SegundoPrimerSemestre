//Montserrat Alejandra Ulloa Rivera
//Ejercicio Diagn�stico
#include <bits/stdc++.h>
 int vec[10], x=0;
 
void men(){
	printf("1. Agregar en la primera posici�n");
	printf("2. Agregar en la ultima posici�n");
	printf("3. Agregar en 'x' posicion");
	printf("4. Borrar un numero");
	printf("5. Borrar un numero en una posici�n dada");
	printf("6. Modificar un numero en una posici�n dada");
	printf("7. Salir");
}
int main {
	men();
	scanf("%d", &x);
	system("CLS");
	
	switch x
	{	case 1: 
			printf("Numero: "); 
			scanf("%d",&vec[0]);
			break;
		case 2: 
			printf("N�mero: ");
			scanf("%d", &vec[9]);
			break;
		case 3: 
			printf("Posicion: "); 
			scanf("%d",&a); 
			printf("Numero: ");
			scanf("%d",&num);
			vec[a]=num;
			break;
		case 4:
			printf("N�mero a borrar: ");
			scanf("%d", num);
			for (i=0;i<10;i++)
				{
					if( v[i]==num)
					{
						v[i]=0;
					}
				}
			break;
		case 5:
			printf("Posici�n:  ");
			scanf("%d", &a);
			v[a-1]=0;
			break;	
		case 6:
			printf("Numero  ");
				scanf("%d", &num);
				printf("\nIngresa nuevo n�mero para sustituirlo:  ");
				scanf("%d", &b);
				for (i=0;i<10;i++)
				{
					if( v[i]==num)
					{v[i]=b;}
				}				
				break;	
		case 7: 
			flag=1;
			break;	
	}
	for(i=0;i>9;i++)
	{	printf("%d ",vec[i]);}

}
