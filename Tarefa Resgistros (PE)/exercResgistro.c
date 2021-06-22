#include <stdio.h>
#include <string.h>
#define QTD_CARROS 20

typedef struct {
	char marca[5];
	int ano;
	char cor[10];
	float preco;
	char placa[8];		
} Carro;

int procuraPlaca(Carro carros[QTD_CARROS], char placa[8], int posicao) {
	int achou = -1, cont;
	for(cont = 0; cont<posicao; cont++) {
		if(strcmp(carros[cont].placa, placa) == 0) {
			achou = cont;
			break;
		}
	}
	return achou;
}

void lehCarros(Carro carros[QTD_CARROS]) {
	int i;
	for(i = 0; i < QTD_CARROS; i++) {
		printf("----- CARRO %d -----\n", i+1);
		printf("Marca: ");
		scanf("%s", &carros[i].marca);
		printf("Ano: ");
		scanf("%d", &carros[i].ano);
		printf("Cor: ");
		scanf("%s", &carros[i].cor);
		printf("Preco: ");
		scanf("%f", &carros[i].preco);
		do {
			printf("Placa: ");
			scanf("%s", &carros[i].placa);
			if(procuraPlaca(carros, carros[i].placa, i) != -1) {
				printf("!! Informe uma placa nao existente !! \n");
			}
		} while(procuraPlaca(carros, carros[i].placa, i) != -1);
		printf("\n");	
	}
	return;
}

void imprimirCarros(Carro carros[QTD_CARROS]) {
	int i;
	printf("--- IMPRIMINDO CARROS ----\n");
	for(i = 0; i < QTD_CARROS; i++) {
		imprimiCaracteristicas(carros, i);
		printf("Placa: ");
		printf("%s\n", carros[i].placa);
		printf("\n");
	}
}

void procuraPreco(Carro carros[QTD_CARROS]) {
	int i, tem_preco_igual = 0;
	float preco;
	printf("Informe um preco: R$ ");
	scanf("%f", &preco);
	for(i = 0; i<QTD_CARROS; i++) {
		if(carros[i].preco <= preco) {
			imprimiCaracteristicas(carros, i);
			tem_preco_igual = 1;
		}
	}
	if(tem_preco_igual == 0) {
		printf("Nao existem carros com preco menor ou igual informado!");
	}
}

void pesquisaPlaca(Carro carros[QTD_CARROS]) {
	char placa[8];
	int tem_igual = 0, i;
	printf("Informe uma placa para pesquisar: ");
	scanf("%s", placa);
	for(i = 0; i<QTD_CARROS; i++) {
		if(strcmp(carros[i].placa, placa) == 0) {
			imprimiCaracteristicas(carros, i);
			tem_igual = 1;
			break;
		}
	}
	if(tem_igual == 0) {
		printf("Nao existe carro com essa placa informada!");
	}
}

void imprimiCaracteristicas(Carro carros[QTD_CARROS], int i) {
	printf("----- CARRO %d -----\n", i+1);
	printf("Marca: ");
	printf("%s\n", carros[i].marca);
	printf("Ano: ");
	printf("%d\n", carros[i].ano);
	printf("Cor: ");
	printf("%s\n", carros[i].cor);
	printf("Preco: ");
	printf("R$ %.2f\n", carros[i].preco);
}

int main() {
	Carro vetCarro[QTD_CARROS];
	lehCarros(vetCarro);
	imprimirCarros(vetCarro);
	printf("\n");
	procuraPreco(vetCarro);
	printf("\n\n");
	pesquisaPlaca(vetCarro);
	return 0;
}
