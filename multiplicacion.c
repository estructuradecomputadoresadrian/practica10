#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int *matrizi, int tamanioi);

void multiplicar(int *mmatrizA, int *mmatrizB, int *mmatrizC, int tamaniom);

void printMatriz(int *matrizp, int tamaniop);

int main(){
	srand(time(NULL));
	int tamanio, *matrizA, *matrizB, *matrizC;
	printf("Introduce el tamaño del cual quieres las matrices cuadradas: ");
	scanf("%d",&tamanio);
	matrizA=(int*)malloc(sizeof(int)*tamanio*tamanio);
	matrizB=(int*)malloc(sizeof(int)*tamanio*tamanio);
	matrizC=(int*)malloc(sizeof(int)*tamanio*tamanio);
	inicializa(matrizA,tamanio);
	inicializa(matrizB,tamanio);
	printf("\nLa primera matriz generada aleatoriamente es:\n");
	printMatriz(matrizA, tamanio);
	printf("\n");
	printf("La segunda matriz generada aleatoriamente es:\n");
	printMatriz(matrizB, tamanio);
	printf("\nLa multiplicacion de ambas matrices da como resultado la siguiente matriz:\n");
	multiplicar(matrizA, matrizB, matrizC, tamanio);
	printMatriz(matrizC,tamanio);
	return 0;
}

void inicializa(int *matrizi, int tamanioi){
	for (int j = 0; j < tamanioi ; j++){
		for (int i = 0; i < tamanioi; i++){
			*(matrizi+i*tamanioi+j) = (1+(rand()%10));
		}
	}
}


void printMatriz(int *matrizp, int tamaniop){
	for (int j = 0; j < tamaniop ; j++){
		for (int i = 0; i < tamaniop; i++){
			printf("%d\t",*(matrizp+i*tamaniop+j));
		}
		printf("\n");
	}
}

void multiplicar(int *mmatrizA, int *mmatrizB, int *mmatrizC, int tamaniom){
	for(int i=0;i<tamaniom;i++){
      	for(int j=0;j<tamaniom;j++){
          	*(mmatrizC+i*tamaniom+j)=0;
          	for(int k=0;k<tamaniom;k++){
          		*(mmatrizC+i*tamaniom+j)=(*(mmatrizC+i*tamaniom+j))+((*(mmatrizB+i*tamaniom+k))*(*(mmatrizA+k*tamaniom+j)));
          	}
      	}
  	}
}

