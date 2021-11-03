//Montserrat Alejandra Ulloa Rivera
//Uso de Structs 
#include <stdio.h>

struct fechas {
    int dia;
    int mes;
    int anio;
}; 

struct fechas fecha1, fecha2, fecha3;


int main() {
	
	
	printf("Ingresar fecha: %d\n", 1);
    printf("Dia: "); scanf("%d",&fecha1.dia);
	printf("Mes: "); scanf("%d",&fecha1.mes);
	printf("Anio: "); scanf("%d",&fecha1.anio);
    
    printf("Ingresar fecha: %d\n", 2);
    printf("Dia: "); scanf("%d",&fecha2.dia);
	printf("Mes: "); scanf("%d",&fecha2.mes);
	printf("Anio: "); scanf("%d",&fecha2.anio);
	
	printf("Ingresar fecha: %d\n", 3);
    printf("Dia: "); scanf("%d",&fecha3.dia);
	printf("Mes: "); scanf("%d",&fecha3.mes);
	printf("Anio: "); scanf("%d",&fecha3.anio);
    
  	printf("Fechas ingresadas: \n");
  	printf("\t %d/%d/%d\n", fecha1.dia,fecha1.mes,fecha1.anio );
  	printf("\t %d/%d/%d\n", fecha2.dia,fecha2.mes,fecha2.anio );
  	printf("\t %d/%d/%d\n", fecha3.dia,fecha3.mes,fecha3.anio );
    return 0;
}
