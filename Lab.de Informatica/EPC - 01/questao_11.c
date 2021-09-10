#include <stdio.h>

int main() {
	
	float valor_salario = 0.0, tempo_medio = 0.0;
	int tempo_servico, membros = 10, qtd_inferior_24 = 0, qtd_superior_600 = 0, i;
	
	for(i = 0; i < membros; i++) {
		printf("\nInforme o salario: R$");
		scanf("%f", &valor_salario);
		printf("informe o tempo de servico: ");
		scanf("%d", &tempo_servico);
		
		if(tempo_servico < 24) {
			qtd_inferior_24++;
		}
		
		tempo_medio += tempo_servico;
		
		if(valor_salario > 600) {
			qtd_superior_600++;
		}
	}
	
	printf("\n(%d) possui(em) tempo de servico inferior a 24 meses!\n", qtd_inferior_24);
	printf("Tempo medio dos funcionarios e %.2f meses!\n", tempo_medio/membros);
	printf("%.2f%% possuem salario superior a R$600,00\n", (float)((qtd_superior_600*100)/membros));
	
	return 0;
}
