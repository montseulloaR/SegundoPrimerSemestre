#include <bits/stdc++.h>

int main(){
    
    int num, peso, p = 0, s, cont = 0;
    
    printf("Inserte el numero de simbolos: ");
    scanf("%d", &num); 
	printf("Inserte el peso: ");   
    scanf("%d", &peso); 
	printf("Cadena\tPeso\n");
    
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            for(int k = 0; k < num; k++){
                    
                cont++;
                s = i + j + k;
                if(s == peso) p++;
                printf("%d%d%d\t%d\n", i, j, k, s);
            
            }
        }
    }
    
    printf("El numero de cadenas con peso: %d de las %d posibilidades es: %d", peso, cont, p);
}

/* Conclusión personal: 
Creo que quizá haya una forma más optimizada de hacer el código anterior, pero fue realizado según las bases que se han dado
hasta este punto en los diferentes cursos relacionados con la programación. Pero a final de cuentas el onjetivo de la 
practica se cumplió :D */

