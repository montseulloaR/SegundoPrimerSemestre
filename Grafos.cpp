#include <stdio.h>
#include <stdlib.h>
#define OR 15

int m[OR][OR], r, c, n, g[OR], mayor=0;
int h;
int main (int argc, char*argv[]){
    printf("Almacena las adyacencias de un grafo \n");
    printf("Introduce el orden del grafo (n<=15):  ");
    scanf("%d", &n);
    printf("Introduce 1 si hay adyacencia o 0 si no la hay:\n");
    
    for (r=0; r<n; r++){
        m[r][r]=0;
        for (c=r+1; c<n; c++){
            printf("%d a %d ", r+1, c+1);
            scanf("%d",&m[r][c]);
            m[c][r]=m[r][c];	
        	if(m[r][c]==1)
            	{g[r]+=1;
				g[c]+=1;}
		}	
    }
    
    for (r=0; r<n; r++){
    	if (g[r]>mayor)
    	{mayor=g[r];}
        printf("Grado del nodo %d: %d\n", r+1, g[r]);
    }
    
    printf("El grado del grafo es %d: \n", mayor);
system("pause");
return 0;
}
