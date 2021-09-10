#include <stdio.h>

int main() {
	
	int n, val = 5;
	int qtd_positivos = 0, qtd_nulos, qtd_negativos, soma_positivos;
	float media_negativos;
	
	while(val--) {
		printf("Informe um valor: ");
		scanf("%d", &n);
		
		if(n > 0) {
			qtd_positivos++;
			soma_positivos += n;
		} else if(n == 0) {
			qtd_nulos++;
		} else if(n < 0) {
			qtd_negativos++;
			media_negativos += n;
		}
	}
	
	if(qtd_negativos == 0) {
		media_negativos = 0;
	} else {
		media_negativos /= qtd_negativos;
	}
	
	printf("\n\nExistem %d valores positivos!\n", qtd_positivos);
	printf("Exitem %d valores negativos!\n", qtd_negativos);
	printf("Exitem %d valores nulos!\n", qtd_nulos);
	printf("Media dos numeros negativos = %.2f\n", media_negativos);
	printf("Soma dos valores positivos = %d!\n", soma_positivos);
	return 0;
}
