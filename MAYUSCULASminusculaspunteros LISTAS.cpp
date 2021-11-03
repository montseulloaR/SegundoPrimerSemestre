#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main ()
{
	char n[30];
	char *p;
	p=n;
	printf("Escribe una palabra: ");
	scanf("%s",n);
	
	for(int i=0;i<30;i++)
		p[i]=tolower(p[i]);
		printf("Esta es la palabra en minusculas \n %s \n",p);
	
	for(int i=0;i<30;i++)
		p[i]=toupper(p[i]);
		printf("Esta es la palabra en mayusculas \n %s \n",p);
	
	
}
