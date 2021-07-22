#include <stdio.h>
#define TAM 100

typedef struct{                                                           
	int mat; //matricula
	int ano; //ano de admissão
	float sal; //salario
	int anoNasc; //ano nascimento
}tFunc;

int existeMatricula(tFunc vet[TAM], int posicaoAtual) {
	int i, cont = 0;
	for(i = 0; i <= posicaoAtual-1; i++) {
		if(vet[i].mat == vet[i+1].mat) {
			cont++;
		}
	}
	if(cont == 0) {
		return 0;
	} else {
		return 1;
	}
}

int cadastrar(tFunc vet[TAM]) {
	int i, ultimoAnoAdmissao = 0;
	for(i = 0; i < TAM; i++) {
		printf("---- Funcionario (%d) ----\n", i+1);
		printf("Matricula: ");
		do{
			scanf(" %d", &vet[i].mat);
			if(existeMatricula(vet, i) == 1) {
			    printf("\nMATRICULA JA EXISTE, DIGITE NOVAMENTE: ");
			}
		} while(existeMatricula(vet, i) == 1 && i != 0); //so faz depois do primeiro funcionario
		printf("Ano de Admissao: ");
		scanf("%d", &vet[i].ano);
		if(ultimoAnoAdmissao < vet[i].ano) {
			ultimoAnoAdmissao = vet[i].ano;
		}
		printf("Salario: ");
		scanf("%f", &vet[i].sal);
		printf("Ano de Nascimento: ");
		scanf("%d", &vet[i].anoNasc);
		printf("\n\n");
	}
	return ultimoAnoAdmissao;
}

void calculaMedia(tFunc vet[TAM], int anoA, int anoB, float *media) {
	int i, cont = 0;
	*media = 0.0;
	for(i = 0; i < TAM; i++) {
		if(vet[i].anoNasc >= anoA && vet[i].anoNasc <= anoB) {
			*media += (float)vet[i].sal;
			cont++;
		}
	}
	*media /= cont;
}

void maisRecentes(tFunc vet[TAM], int anoAdmissao) {
	int i;
	for(i = 0; i < TAM; i++) {
		if(vet[i].ano == anoAdmissao) {
			printf("---- Funcionario (%d) ----\n", i+1);
			printf("Matricula: %d\n\n", vet[i].mat);
		}
	}
}

int main(){
	tFunc vet[TAM];
	int anoA, anoB; //anos limites da faixa etária
	float media; //media dos salários na faixa etária
	int aux, anoContratacao; 
	
	anoContratacao = cadastrar(vet); //chamada de cadastra
	printf("Relatorio da media dos salarios:\n");
	printf("Digite os anos limites da faixa etaria: ");
	scanf("%d %d", &anoA, &anoB);
	
	if (anoA>anoB){
		aux = anoA;
		anoA = anoB;
		anoB = aux;
	}	
	
	calculaMedia(vet, anoA, anoB, &media); //chamada de calculaMedia
	printf("\nMEDIA = %.2f\n", media);
	printf("\nRelatorio dos funcionarios mais recentes:\n");
	maisRecentes(vet, anoContratacao); //chamada do maisRecentes
	return 0;
}

