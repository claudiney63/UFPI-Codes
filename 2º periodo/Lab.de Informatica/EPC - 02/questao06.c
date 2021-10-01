#include <stdio.h>
/*
6 - Faça um programa que leia 2 valores inteiros e chame uma função que receba
estas 2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada
passando duas variáveis A e B por exemplo e, após a execução da função, A vai
conter o valor de B e B o valor de A.
*/

void funcao(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main() {
	
	int valor1, valor2;
	
	printf("Informe dois valores (A e B): ");
	scanf("%d %d", &valor1, &valor2);
	
	funcao(&valor1, &valor2);
	
	printf("\nValor 1: %d\n", valor1);
	printf("Valor 2: %d", valor2);
	
	
	return 0;
}
