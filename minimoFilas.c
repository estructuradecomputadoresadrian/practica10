#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int *matrizi, int filas, int columnas);

void printmatriz(int *matrizp, int filasp, int columnasp);

void filaminima(int *matrizf, int *vectorminf, int columnasf, int filasf);

int main(){
	srand(time(NULL));
	int *matriz, filas, columnas, *vectormin;
	printf("¿Cuantas filas quieres que tenga la matriz?\n");
	scanf("%d",&filas);
	printf("¿Cuantas columnas quieres que tenga la matriz?\n");
	scanf("%d",&columnas);
	vectormin=(int*)malloc(sizeof(int)*columnas);
	matriz=(int*)malloc(sizeof(int)*filas*columnas);
	inicializa(matriz,filas,columnas);
	printmatriz(matriz, filas, columnas);
	filaminima(matriz, vectormin, columnas, filas);
	free(matriz);
	printf("\n");
	int contadoraux=1;
	for (int i = 0; i < columnas; i++){
		printf("El valor minimo de la fila %d es %d.\n", contadoraux, *(vectormin+i));
		contadoraux++;
	}
	printf("\n");

	return 0;
}

void inicializa(int *matrizi, int filasi, int columnasi){
	for (int j = 0; j < filasi ; j++){
		for (int i = 0; i < columnasi; i++){
			*(matrizi+i*filasi+j) = ((rand()%20)-10);
		}
	}
}

void printmatriz(int *matrizp, int filasp, int columnasp){
	printf("La matriz generada es:\n\n");
	for (int j = 0; j < filasp ; j++){
		for (int i = 0; i < columnasp; i++){
			printf("%d\t",*(matrizp+i*filasp+j));
		}
		printf("\n");
	}
}

void filaminima(int *matrizf, int *vectorminf, int columnasf, int filasf){
	for (int j = 0; j < columnasf; j++){
		*(vectorminf+j)=*(matrizf+j*filasf);
		for (int i = 0; i < columnasf; i++){
			if (*(matrizf+i*filasf+j)<*(vectorminf+j)){
				*(vectorminf+j)=*(matrizf+i*filasf+j);
			}		
		}
	}
}