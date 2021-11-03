#include <stdio.h>
#include <stdlib.h>

int i, n;
short f;

int main(int argc, double *argv[]) {
	printf("Este programa calcula el factorial de n y el tamaño de un tipo de dato\n");
    printf("El tamano de un short es: %g bytes\n", sizeof(f));
    
    f=1;
    printf("Introduce el valor de n: \n");
    scanf("%d",&n);
    
    for (i=1; i<=n; i++)
	{
        f=f*i;
        printf("Número: %d /t Factorial: %g\n", i, f);
    }
    system("pause");
    return 0;
}
