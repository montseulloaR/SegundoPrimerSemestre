#include <bits/stdc++.h>
//Montserrat Alejandra Ulloa Rivera
//Ejercicio diangóstico 2
int vec[10], x, on=0, pos=0, num, sal=0, tem;
int main(){
	do{
		system("cls");
		for(int i=0; i<9; i++)printf("[%d]",vec[i]);
	
		printf("\n1.Agregar al final\n");
		printf("2. Agregar en cierta posicion\n");
		printf("3. Borrar un número\n");
		printf("4. Borrar una posicion\n");
		printf("5. SALIR\n");
		scanf("%d",&x);

		
		switch (x){
			case 1: 
				printf("Numero: ");
				scanf("%d",&vec[on]);
				on++;	
				break;
			case 2: 
			on++;
				printf("Posicion: ");
				scanf("%d",&pos);
				vec[pos];
				printf("Numero: ");
				scanf("%d",&num);
				for(int i=9; i>pos; i--){
					vec[i]=vec[i-1];
				}
				vec[pos]=num;
				break;
			case 3:	
				printf("Numero: ");
				scanf("%d", &num);
				for(int i=0; i<9; i++)
					{if(vec[i]==num){vec[i]=0; on--;}
				}
				for(int i=0; i<9; i++)
					{for(int j=i; j<10; j++){
					    if(vec[j]>0 && i!=j && vec[i]==0){
							vec[i]=vec[j];
							vec[j]=0;
						}
					}
				}
				break;
			case 4:
				printf("Posicion: ");
				scanf("%d", &pos);
				if(pos<on)on--;
				vec[pos-1]=0;
				for(int i=0; i<9; i++)
					{for(int j=i; j<10; j++){
					    if(vec[j]>0 && i!=j && vec[i]==0){
							vec[i]=vec[j];
							vec[j]=0;
						}
					}
				}
				break;
			case 5:
				sal=2;
				break;						
		}
	}while(sal!=2);
	system("cls");
	printf("Gracias.\n");
system("pause");
return 0;		
}
