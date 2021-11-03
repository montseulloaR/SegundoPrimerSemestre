#include <bits/stdc++.h>

int main (){
	int op, i;
	printf("1. Tabla de verdad de la conjuncion \n2. Tabla de verdad de la disyuncion \n3. Salir\nSelección: ");
	scanf("%d",&op);
	
	switch (op)
	{case 1: printf("\np   q   r\tp ^ q ^ r\n0   0   0\t    0\n0   1   0\t    0\n0   0   1\t    0\n0   1   1\t    0\n");
			printf("1   0   0\t    0\n1   1   0\t    0\n1   0   1\t    0\n1   1   1\t    1\n");
			break;
	case 2:
		printf("\np   q\tp v q\n0   0\t  0\n0   1\t  1\n");
		printf("1   0 \t  1\n1   1\t  1\n");
		break;
	case 3:
		break;
	}
	
	system("pause");
	return 0;
}
