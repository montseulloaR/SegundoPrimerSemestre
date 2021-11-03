//FechasDePunteros
//Montserrat Alejandra Ulloa Rivera
//7/Marzo/2019
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct fechas{
	int dia, mes, anio;
};

int main() {
	
	struct fechas fecha , *pfecha;
	pfecha=&fecha;
	cout <<"Ingrese el dia"<< endl;
	cin >> (*pfecha).dia;
	cout <<"Ingrese el mes"<< endl;
	cin >> (*pfecha).mes;
	cout <<"Ingrese el anio"<< endl;
	cin >> (*pfecha).anio;
	
	cout << "La fecha ingresada es " << pfecha->dia << "/" << pfecha->mes << "/" << pfecha->anio << endl;
	getch();
}
