#include <stdio.h>
#define TAM 5

typedef struct{                                                           
	int mat; //matricula
	int ano; //ano de admissão
	float sal; //salario
	int anoNasc; //ano nascimento
}tFunc;

int existeMatricula(tFunc vet[TAM], int posicaoAtual, int matriAtual) {
	int i;
	for(i = 0; i <= posicaoAtual; i++) {
		if(vet[i].mat == matriAtual) {
			return 1;
		}
	}
	return 0;
}

void cadastrar(tFunc vet[TAM], int vetorAnos[TAM]) {
	int i, ultimoAnoAdmissao = 0, matriAtual;
	for(i = 0; i < TAM; i++) {
		printf("---- Funcionario (%d) ----\n", i+1);
		printf("Matricula: ");
		do {
			scanf("%d", &vet[i].mat);
		} while(existeMatricula(vet, i, matriAtual));
		printf("Ano de Admissao: ");
		scanf("%d", &vet[i].ano);
		vetorAnos[i] = vet[i].ano;
		printf("Salario: ");
		scanf("%f", &vet[i].sal);
		printf("Ano de Nascimento: ");
		scanf("%d", &vet[i].anoNasc);
		printf("\n");
	}
	return;
}

void calculaMedia(tFunc vet[TAM], int anoA, int anoB, float *media) {
	int i, cont = 0;
	*media = 0.0;
	for(i = 0; i < TAM; i++) {
		if(vet[i].anoNasc >= anoA && vet[i].anoNasc <= anoB) {
			*media += vet[i].sal;
			cont++;
		}
	}
	*media = *media / (float)cont;
}

void maisRecentes(tFunc vet[TAM], int anosContratacao[TAM]) {
	int i, anosMaisRecentes, x, y, aux;
	for(x = 0; x < TAM; x++) { //colocando os anos em ordem crescente
		for(y = x; y < TAM; y++) {
			if(anosContratacao[x] > anosContratacao[y]) {
				aux = anosContratacao[x];
				anosContratacao[x] = anosContratacao[y];
				anosContratacao[y] = aux;
			}
		}
	}
	printf("Quantos anos mais recentes deseja: ");
	scanf("%d", &anosMaisRecentes);
	for(i = TAM-1; i > TAM-anosMaisRecentes-1; i--) { //começa do maior ate o tamanho menos o quantidade anos que o user escolheu
		printf("%d : ", anosContratacao[i]);
		for(x = 0; x < TAM; x++) {
			if(vet[x].ano == anosContratacao[i]) {
				printf("%d ", vet[x].mat);
			}
		}
		printf("\n");
	}
}

int main(){
	tFunc vet[TAM];
	int anoA, anoB; //anos limites da faixa etária
	float media; //media dos salários na faixa etária
	int aux, anosContratacao[TAM]; 
	
	cadastrar(vet, anosContratacao); //chamada de cadastra

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
	maisRecentes(vet, anosContratacao); //chamada do maisRecentes
	return 0;
}
