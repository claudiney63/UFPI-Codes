#include <stdio.h>

int main() {
	
	int vagoes, capacidade, total_caixas;
	float porcentagem;
	
	scanf("%d %d %d", &vagoes, &capacidade, &total_caixas);
	
	if(total_caixas > capacidade*vagoes) {
		printf("\nTransporte recusado!\n");
	} else {
		if(total_caixas/capacidade != 0) {
			printf("\n%d - 100.00%%\n", (total_caixas/capacidade));
		}
		if(((total_caixas%capacidade)*100)/capacidade != 0) {
			porcentagem = ((total_caixas%capacidade)*100)/capacidade;
			printf("1 - %.2f%%\n", porcentagem);
		}
	}
	
	return 0;
}
