#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int *matrizi, int filas, int columnas);

void printmatriz(int *matrizp, int filasp, int columnasp);

int calculaminimo(int *matrizm, int elementos);

int main(){
	srand(time(NULL));
	int *matriz, filas, columnas, elementos;
	printf("¿Cuantas filas quieres que tenga la matriz?\n");
	scanf("%d",&filas);
	printf("¿Cuantas columnas quieres que tenga la matriz?\n");
	scanf("%d",&columnas);
	elementos = filas * columnas;
	matriz=(int*)malloc(sizeof(int)*filas*columnas);
	inicializa(matriz,filas,columnas);
	printmatriz(matriz, filas, columnas);
	int minimo = calculaminimo(matriz, elementos);
	free(matriz);
	printf("\nEl minimo de los valores introducidos es %d\n",minimo);

	return 0;
}

void inicializa(int *matrizi, int filasi, int columnasi){
	for (int j = 0; j < filasi ; j++){
		for (int i = 0; i < columnasi; i++){
			*(matrizi+i*filasi+j) = (1+(rand()%10));
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

int calculaminimo(int *matrizm, int elementosm){
	int min = *(matrizm);
	for (int i = 0; i < elementosm; i++){
		if (min > *(matrizm+i)){
			min = *(matrizm+i);
		}
	}
	return min;
}