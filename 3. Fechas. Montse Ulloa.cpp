//Montserrat Alejandra Ulloa Rivera
//Fecha de entrega: 11/03/2019
//Mostrar fecha con apuntador
#include <stdio.h>

struct fechas {
    int dia;
    int mes;
    int anio;
}; 


int main() {
	struct fechas fecha;	
	int *dia, *mes, *anio;
	dia = &fecha.dia;
	mes = &fecha.mes;
	anio = &fecha.anio;
	printf("Ingrese una fecha dd/mm/aa\n");
    printf("Dia: "); scanf("%d",&fecha.dia);
	printf("Mes: "); scanf("%d",&fecha.mes);
	printf("Anio: "); scanf("%d",&fecha.anio);
    
  	printf("Fechas ingresadas: \n");
  	printf("\t %d/%d/%d\n", *dia,*mes,*anio);

    return 0;
}
