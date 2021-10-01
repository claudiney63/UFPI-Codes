#include <stdio.h>
#include <string.h>
#define QTD_CARROS 10000

typedef struct {
	char marca[5];
	int ano;
	char cor[10];
	float preco;
	char data_aquisicao[11];
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

int cadastrarCarro(Carro carros[QTD_CARROS], int *posicao) {
	int i = *posicao;
	printf("\n----- CARRO %d -----\n", i+1);
	printf("Marca: ");
	scanf("%s", carros[i].marca);
	printf("Ano: ");
	scanf("%d", &carros[i].ano);
	printf("Cor: ");
	scanf("%s", carros[i].cor);
	printf("Preco: ");
	scanf("%f", &carros[i].preco);	
	printf("Data de Aquisicao(DD/MM/AAAA): ");
	scanf(" %s", carros[i].data_aquisicao);
	do {
		printf("Placa: ");
		scanf("%s", &carros[i].placa);
		if(procuraPlaca(carros, carros[i].placa, i) != -1) {
			printf("!! Informe uma placa nao existente !! \n");
		}
	} while(procuraPlaca(carros, carros[i].placa, i) != -1);
	return 1;
}

void localizarCarro(Carro carros[QTD_CARROS], int *posicaoFinal) {
	char placa[8];
	int tem_igual = 0, i;
	printf("\nInforme uma placa para pesquisar: ");
	scanf(" %s", &placa);
	printf("\n");
	for(i = 0; i < *posicaoFinal; i++) {
		if(strcmp(carros[i].placa, placa) == 0) {
			imprimiCaracteristicas(carros, i);
			tem_igual = 1;
			break;
		}
	}
	if(tem_igual == 0) {
		printf("Nao existe carro com essa placa informada!\n");
	}
}

void removerCarro(Carro carros[QTD_CARROS], int *posicaoFinal) {
	int i, posicao_remover, tem_placa = 0;
	char placa[8];
	printf("\nInforme uma placa: ");
	scanf("%s", placa);
	do{
		for(i = 0; i < *posicaoFinal; i++) {
			if(strcmp(carros[i].placa, placa) == 0) {
				posicao_remover = i;
				tem_placa = 1;
				break;
			}
		}
		if(tem_placa == 0) {
			printf("\n!! Informe uma placa existente, tente novamente !!\n");
		} else {
			printf("\n!! Carro com indice %d removido com sucesso !!\n", posicao_remover);
		}
	} while(tem_placa == 0);
	
	for(i = posicao_remover; i < *posicaoFinal; i++) {
		if(i < *posicaoFinal-1) {
			strcpy(carros[i].marca, carros[i+1].marca);
			carros[i].ano = carros[i+1].ano;
			strcpy(carros[i].cor, carros[i+1].cor);
			carros[i].preco = carros[i+1].preco;
			strcpy(carros[i].data_aquisicao, carros[i+1].data_aquisicao);
			strcpy(carros[i].placa, carros[i+1].placa);
		}
	}
	//*posicaoFinal--;
}

void relatorios(Carro carros[QTD_CARROS], int *posicao) {
	int opcao, pos = *posicao;
	do{
		printf("\n---- MENU RELATORIOS ----\n");
		printf("1 - Listar carros\n");
		printf("2 - Listar carros por limite de preco\n");
		printf("3 - Listar carros por limite de ano\n");
		printf("4 - Listar carros de uma marca\n");
		printf("5 - Listar carros de marca e ano\n");
		printf("0 - Sair\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1: listarCarros(carros, &pos);
				break; 
			case 2: carrosPorLimitePreco(carros, &pos);
				break;
			case 3: carrosPorLimiteAno(carros, &pos);
				break;
			case 4: carrosPorMarca(carros, &pos);
				break;
			case 5: carrosMarcaAno(carros, &pos);
				break;
			default: opcao = 0;
		}
		printf("\n");
	} while(opcao != 0);
}

int listarCarros(Carro carros[QTD_CARROS], int *posicaoFinal) {
	int i;
	printf("\n---- LISTA DE CARROS ----");
	for(i = 0; i < *posicaoFinal; i++) {
		imprimiCaracteristicas(carros, i);
		printf("Placa: %s", carros[i].placa);
		printf("\n");
	}
	return 1;
}

int carrosPorLimitePreco(Carro carros[QTD_CARROS], int *posicaoFinal) {
	int i, temCarro = 0;
	float preco;
	printf("\nInforme um preco: ");
	scanf("%f", &preco);
	for(i = 0; i < *posicaoFinal; i++) {
		if(carros[i].preco <= preco) {
			imprimiCaracteristicas(carros, i);
			printf("Placa: %s\n", carros[i].placa);
			temCarro = 1;
		}	
	}
	if(temCarro == 0) { printf("\n !! Nao possuem carro com esse limite de preco !!\n");}
	return 2;
}

int carrosPorLimiteAno(Carro carros[QTD_CARROS], int *posicaoFinal) {
	int i, ano, temCarro = 0;
	printf("\nInforme um ano: ");
	scanf("%d", &ano);
	for(i = 0; i < *posicaoFinal; i++) {
		if(carros[i].ano <= ano) {
			imprimiCaracteristicas(carros, i);
			printf("Placa: %s\n", carros[i].placa);
			temCarro = 1;
		}	
	}
	if(temCarro == 0) { printf("\n !! Nao possuem carro com esse limite de ano !!\n");}
	return 3;
}

int carrosPorMarca(Carro carros[QTD_CARROS], int *posicaoFinal) {
	int i, temCarro = 0;
	char marca[5];
	printf("\nInforme uma marca: ");
	scanf("%s", &marca);
	for(i = 0; i < *posicaoFinal; i++) {
		if(strcmp(carros[i].marca, marca) == 0) {
			imprimiCaracteristicas(carros, i);
			printf("Placa: %s\n", carros[i].placa);
			temCarro = 1;
		}	
	}
	if(temCarro == 0) { printf("\n !! Nao possuem carro com essa marca !!\n");}
	return 4;
}

int carrosMarcaAno(Carro carros[QTD_CARROS], int *posicaoFinal) {
	char marca[5];
	int ano, i, temCarro = 0;
	printf("\nInforme uma marca: ");
	scanf("%s", &marca);
	printf("Informe um ano: ");
	scanf("%d", &ano);
	for(i = 0; i < *posicaoFinal; i++) {
		if(strcmp(carros[i].marca, marca) == 0 && carros[i].ano <= ano) {
			imprimiCaracteristicas(carros, i);
			printf("Placa: %s\n", carros[i].placa);
			temCarro = 1;
		}	
	}
	if(temCarro == 0) { printf("\n !! Nao possuem carro com essa marca e limite de ano !!\n");}
	return 5;
}

int imprimiCaracteristicas(Carro carros[QTD_CARROS], int i) {
	printf("\n----- CARRO %d -----\n", i+1);
	printf("Marca: %s\n", carros[i].marca);
	printf("Ano: %d\n", carros[i].ano);
	printf("Cor: %s\n", carros[i].cor);
	printf("Preco: R$ %.2f\n", carros[i].preco);
	printf("Data de Aquisicao: %s\n", carros[i].data_aquisicao);
	return 0;
}

int menu(Carro carros[QTD_CARROS], int *posicao) {
	int opcao, pos = *posicao;
	printf("---- MENU PRINCIPAL ----\n");
	printf("1 - Cadastrar carro\n");
	printf("2 - Localizar carro\n");
	printf("3 - Remover carro\n");
	printf("4 - Relatorios\n");
	printf("0 - Sair\n");
	printf("Escolha: ");
	scanf("%d", &opcao);
	switch(opcao) {
		case 1: cadastrarCarro(carros, &pos);
			break;
		case 2: localizarCarro(carros, &pos);
			break;
		case 3: removerCarro(carros, &pos);
			break;
		case 4: relatorios(carros, &pos);
			break;
		default: opcao = 0;
	}
	printf("\n");
	return opcao;
}

int main() {
	Carro carros[QTD_CARROS];
	int posicao, opcao;
	while((opcao = menu(carros, &posicao)) != 0){
		if(opcao == 1) {
			posicao++;
		} 
		if(opcao == 3) {
			posicao--;
		}
	};	
	return 0;
}
