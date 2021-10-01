#include <stdio.h>

//1 - Preencher um vetor com os números 10 a 20, e depois mostrar os elementos pares
//do vetor de trás para frente.


int main() {
	
	int vetor[11] = {10, 11, 12, 13, 14, 15, 16, 17, 18 , 19, 20}, i;
	
	for(i = 10; i >= 0 ; i--) {
		if(vetor[i]%2 == 0) {
			printf("%d ", vetor[i]);
		}
	}
	
	return 0;
}
