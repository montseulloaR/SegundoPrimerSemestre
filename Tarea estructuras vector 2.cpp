#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

int vec[10]={0,0,0,0,0,0,0,0,0,0}; 
int i;

void mostrar(){
	for (i=0; i<10; i++){
		printf("%d ", vec[i]);
	}
}

int main(){
	int opc, flag=1, cont=0,j, num, pos,comp=0;
		for (i=0; i<10; i++){
		vec[i]=0;
	}
	do{
	
		printf("                   \n\n\nMenu principal\n\n");
		printf("        1* Agrega al final  \n");
		printf("        2* Agregar en cierta posicion\n");
		printf("        3* Borrar un numero\n");
		printf("        4* Borrar en una posicion\n");
		printf("        5* Salir\n");
		
		printf("\n\n\n");
		printf("Dame una opcion: ");
		scanf("%d",&opc);
		switch (opc){
			case 1:
				printf("Dame el numero a agregar: ");
				scanf("%d",&num);
				
				
				for(i=9; i>cont; i--){
					vec[i]=vec[i-1];
				}
				vec[cont]=num;
				if(cont<10){
					cont++;
				}	
				mostrar();			
			break;
			case 2:
				printf("Dame el numero a agregar: ");
				scanf("%d",&num);
				printf("Dame la posicion: %d",cont);
				scanf("%d",&pos);
				for(i=9; i>pos; i--){
					vec[i]=vec[i-1];
				}
				vec[pos-1]=num;
				if(cont<10){
					for(i=0;i<10;i++){
                        if(vec[i]>0 && flag==1){
                            comp++;
                            printf("%d",comp);
                            system("PAUSE");
                        }else{
                        	flag=0;
						}
                    }
                    if(comp>cont){
                        cont++;
                    }
				}
				flag=1;
                comp=0;	
                mostrar();
			break;
			case 3:
				printf("Dame el numero a borrar: ");
				scanf("%d",&num);
				for(i=0;i<10;i++){
					if (vec[i]==num){
						vec[i]=0;
						cont--;
					}
				}
				for(i=0;i<9;i++){
					for(j=i;j<10;j++){
						if(vec[j]>0 && i!=j && vec[i]==0){
							vec[i]=vec[j];
							vec[j]=0;
							j=15;
						}
					}
				}
				mostrar();
			break;
			case 4:
				printf("Dame la posicion a borrar: ");
				scanf("%d",&pos);
				for(i=pos-1; i<10; i++){
                    if(i<9){
                        vec[i]=vec[i+1];
                    }else if(i==9){
                        vec[i]=0;
                    }    
                }
				cont--;
				mostrar();
			break;
		}
	}while(opc!=5);
	system("pause");
	return 0;
}
