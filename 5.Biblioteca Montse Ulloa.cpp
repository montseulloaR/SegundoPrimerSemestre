#include <stdio.h>
#include<windows.h> 
//MOntserrat Alejnadra Ulloa Rivera
struct autor {
    char nomb[25];
    char ape[35];
};

struct tema {  
    char modulo[4];
    char area[20];
};

struct libros {
    char nom_lib[70];
    struct autor aut;
    struct tema tem;
};

int main() {
    int n;
    struct libros lib[100];
    printf("Number of books\n");
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        printf("Book #%d", i+1); 
        printf("\n\tName: ");
        gets(lib[i].nom_lib);
        printf("\n\tAuthor ");
        printf("\n\t\tFirst Name: ");
        gets(lib[i].aut.nomb);
        printf("\t\tLast Name: ");
        gets(lib[i].aut.ape);
        printf("\n\tTopic: ");
        printf("\n\t\tModule: ");
        gets(lib[i].tem.modulo);
        printf("\t\tArea: ");
        gets(lib[i].tem.area);
        Sleep(500);
        system("cls");
    }
    
    printf("LIBROS DISPONIBLES");
    for(int i=0; i<n; i++){
    	printf("\n %s", lib[i].nom_lib);
    	printf("\n\tAuthor: %s %s", lib[i].aut.nomb, lib[i].aut.ape);
    	printf("\n\tModule: %s", lib[i].tem.modulo);
    	printf("\n\tArea: %s", lib[i].tem.area);
	}
    return 0;
}
