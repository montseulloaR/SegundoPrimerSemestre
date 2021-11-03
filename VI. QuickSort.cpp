#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int nums[20], op;

void fillArray(){
	for(int i = 0; i < 50; i++) nums[i] = rand() % 1000;

	cout << "Arreglo inicializado" << endl;
}

void menu(){
	printf("\nMenu Quick Sort:\n\n1. Ordenamiento por QuickSort\n2. Mostrar arreglo\n3. Reinicializar vector\n4. Salir\nTu seleccion: ");
	scanf("%d", &op);
}

void print(int ord){
	if(ord == 0) cout << "Vector desordenado:\n" << endl;
	if(ord == 1) cout << "Vector ordenado:\n" << endl;
    if(ord == 2) cout << "Tu vector:\n" << endl;

	for(int i = 0; i < 20; i++) printf("%d ", nums[i]);

    cout << endl;
}

void quicksort(int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(vec[i]<=vec[pivot]&&i<last)
            i++;
         while(vec[j]>number[pivot])
            j--;
         if(i<j){
            temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
         }
      }

      temp=vec[pivot];
      vec[pivot]=vec[j];
      vec[j]=temp;
      quicksort(first,j-1);
      quicksort(j+1,last);

   }
}
int main()
{
    srand(time(0));

	fillArray();
	print(0);

    while(op != 4){
    	menu();

    	switch(op){
    		case 1:
    			quickSort(0, 19);
    			system("CLS");
    			print(1);
    		break;
            case 2:
                print(2);
            break;
    		case 3:
    			fillArray();
    			print(0);
    		break;
    		case 4:
    			cout << "Adios :)" << endl;
    		break;
    		default:
    			cout << "Opcion invalida, intente de nuevo" << endl;
    		break;
    	}

    	cout << endl;
    	system("PAUSE");
    	system("CLS");
    }
}
