#include <stdio.h>
#define TAM 10

void insereRespostas(char respo[TAM]) {
	int i;
	for(i = 0; i < TAM; i++) {
		printf("\nQual a respota da questao %d?\nInforme: ", i+1);
		do {
			scanf(" %c", &respo[i]);
			if(respo[i] != 'a' && respo[i] != 'b' && respo[i] != 'c' && respo[i] != 'd' && respo[i] != 'e') {
				printf("\n!! LETRA INVALIDA, INFORME UM VALOR VALIDO: ");
			}
		} while(respo[i] != 'a' && respo[i] != 'b' && respo[i] != 'c' && respo[i] != 'd' && respo[i] != 'e');
	}
}

int corrigeProva(char respA[TAM], char respP[TAM]) {
	int qtdCorretas = 0, i;
	for(i = 0; i < TAM; i++) {
		if(respA[i] == respP[i]) {
			qtdCorretas++;
		}
	}
	return qtdCorretas;
}

int main(){
	char respP[TAM]; //respostas corretas da prova
	char respA[TAM]; //respostas do aluno
	int res;//quantidade de questões certas
	
	printf("Gabarito da Prova\n");
    insereRespostas(respP); //chamada de insereRespostas
    
	printf("Resposta do Aluno\n");
	insereRespostas(respA); //chamada de insereRespostas
	
    res = corrigeProva(respA, respP); //chamada de corrigeProva
    printf("%d questoes corretas\n", res);
    
    return 0;
}


