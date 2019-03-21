#include <stdio.h>
#include <stdlib.h>

int calculamaximo(int *pm, int n);

int main(){
	int num,*p;
	printf("¿Cuantos enteros quiere introducir?\n");
	scanf("%d",&num);
	p = (int *)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++){
		printf("Introduzca el entero en la posicion %d: ", i);
		scanf("%d", &*(p+i));
	}
	int maximo = calculamaximo(p,num);
	free(p);
	printf("El maximo de los valores introducidos es %d\n",maximo);

	return 0;
}

int calculamaximo(int *pm, int n){
	int max = (*(pm));
	for (int i = 0; i < n; ++i){
		if(*(pm+i)>max){
			max=(*(pm+i));
		}
	}
	return max;
}