#include <stdio.h>

int main() {
	int qtd_clientes = 10, i, num_credor = 0;
	float media_saldo, saldo, porcentagem_devedor = 0;
  
	for(i = 0; i < qtd_clientes; i++) {
		printf("Informe o saldo de um cliente: R$");
		scanf("%f", &saldo);
		media_saldo += saldo;
		
		if(saldo < 0.0) {
			porcentagem_devedor++;
		} else if(saldo >= 0.0) {
			num_credor++;
		}
	}
	
	printf("\n%.2f%% dos clientes possuem saldo devedor!\n", (float)(porcentagem_devedor*100)/qtd_clientes);
	printf("Numero de clientes credores : (%d)\n", num_credor);
	printf("Saldo medio dos clientes : (R$%.2f)\n", (float)media_saldo/qtd_clientes);
  
	return 0;
}
