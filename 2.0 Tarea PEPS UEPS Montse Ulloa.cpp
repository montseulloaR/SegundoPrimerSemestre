#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h>
#include <windows.h>
//Montserrat Alejandra Ulloa Rivera
//Peps y ueps
int vec[10];
int main(){
	int x, e, num, n=0, sal=0, tem;
	do {
		system("cls");
		for(int i=0; i<9; i++){printf("[%d]", vec[i]);}
		printf("\n1. Valor\n");
		printf("2. UEPS\n");
		printf("3. PEPS\n");
		printf("4. Salir\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("Numero: ");
				scanf("%d",&num);
				vec[n]=num;
				n++;
				break;
				
			case 2:
				vec[n]=0;
				n--;
				break;
			
			case 3: 
				vec[0]=0;
				for(int i=0; i<9; i++){vec[i]=vec[i+1];}
				break;	
			case 4: sal=2;
		}
	}while(sal!=2);
	system("pause");
	return 0;
}
