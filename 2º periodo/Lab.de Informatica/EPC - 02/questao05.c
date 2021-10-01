#include <stdio.h>

/*
5 - Escreva um programa que contenha duas variáveis inteiras. Compare seus
endereços e exiba o maior endereço.
*/

int main() {
	int a, b;
	
	printf("Informe dois valores (A e B): ");
	scanf("%d %d", &a, &b);
	
	printf("\nEndereco de A: %d\n", &a);
	printf("Endereco de B: %d", &b);
	
	if(&a > &b) {
		printf("\n\nEndereco de A e maior!");
	} else {
		printf("\n\nEndereco de B e maior!");
	}
	
	return 0;
}
