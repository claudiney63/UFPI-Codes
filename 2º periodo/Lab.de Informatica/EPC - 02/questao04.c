#include <stdio.h>

/*
4 - Escreva um programa que leia 5 valores inteiros e imprima para cada um o
seu correspondente valor absoluto. Para obter o valor absoluto do número utilize
a função Absoluto especificada abaixo:
Nome: Absoluto
Descrição: Retorna o valor absoluto do número fornecido.
Entrada: int n
Saída: (int) O respectivo valor absoluto de n.
*/

int absoluto(int n) {
	if(n < 0) {
		return n *= -1;
	} else {
		return n;
	}
}

int main() {
	
	int valores[5], i;
	
	for(i = 0; i < 5; i++) {
		printf("Informe um valor: ");
		scanf("%d", &valores[i]);
		printf("Valor absoluto: %d\n\n", absoluto(valores[i]));
	}
	
	return 0;
}
