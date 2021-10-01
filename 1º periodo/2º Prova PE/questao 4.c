#include <stdio.h>

int main() {
	
	int dia, mes, ano, cod_prod=0, dia_val, mes_val, ano_val, produto = 1;
	int qtd_produtos = 0, qtd_produtos_vencidos = 0;
	
	while(1) {
		printf("\n----- PRODUTO: %d -----\n", produto++);
		printf("Data visita: ");
		scanf("%d %d %d", &dia, &mes, &ano);
		
		printf("\nCodigo produto: ");
		scanf("%d", &cod_prod);
		if(cod_prod < 0) {
			break;
		} else {
			qtd_produtos++;
		}
		
		printf("\nData de validade: ");
		scanf("%d %d %d", &dia_val, &mes_val, &ano_val);
		
		if(ano_val < ano) {
			qtd_produtos_vencidos++;
			printf("\nProduto fora da validade!\n\n");
		} else if(ano_val == ano) {
			if(mes_val < mes) {
				qtd_produtos_vencidos++;
				printf("\nProduto fora da validade!\n\n");
			} else if(mes_val == mes) {
				if(dia_val<dia) {
					qtd_produtos_vencidos++;
					printf("\nProduto fora da validade!\n\n");
				}
			}
		}
	}
	
	if(qtd_produtos_vencidos == 0) {
		printf("\nIsento de Multas!\n");
	} else if(((100*qtd_produtos_vencidos)/qtd_produtos) <= 10){
		printf("\nMulta de R$ 1.000\n");
	} else if(((100*qtd_produtos_vencidos)/qtd_produtos) > 10 && ((100*qtd_produtos_vencidos)/qtd_produtos) <= 30){
		printf("\nMulta de R$ 10.000\n");
	} else if(((100*qtd_produtos_vencidos)/qtd_produtos) > 30){
		printf("\nMulta de R$ 100.000\n");
	}
	
	return 0;
}
