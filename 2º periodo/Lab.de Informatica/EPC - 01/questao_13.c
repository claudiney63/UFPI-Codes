#include <stdio.h>

int main() {
	
	int valores = 10, n, i, soma_impares = 0, qtd_valores_pares = 0;
	
	for(i = 0; i < valores; i++) {
		printf("Informe um valor inteiro: ");
		scanf("%d", &n);
		
		if((n%2) != 0) {
			soma_impares += n;
		} else {
			if(n != 0) {
				qtd_valores_pares++;
			}
		}
	}
	
	printf("\nSoma dos imapares : (%d)\n", soma_impares);
	printf("Quantidade de pares : (%d)\n", qtd_valores_pares);
	
	return 0;
}
