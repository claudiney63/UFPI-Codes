#include <stdio.h>

int main() {
	
	int curso, motivo_escolha, ano_nascimento, i;
	int qtd_aptidao = 0, aluno_mais_novo = 0;
	
	for(i = 0; i<300; i++) {
		do {
			printf("1 - Administracao\n");
			printf("2 - Computacao\n");
			printf("3 - Direito\n");
			printf("Escolha: ");
			scanf("%d", &curso);
			if(curso <= 0 || curso>=4) {
				printf("\nDigite um valor valido!\n");
			}
			printf("\n");
		} while(curso <= 0 || curso>=4);
		
		printf("1 - Remuneracao\n");
		printf("2 - Aptidao\n");
		printf("3 - Outros\n");
		printf("Escolha: ");
		scanf("%d", &motivo_escolha);
		if(motivo_escolha == 2) {
			qtd_aptidao++;
		}
		printf("\n");
		
		printf("Qual seu ano de nascimento: ");
		scanf("%d", &ano_nascimento);
		printf("\n");
		if(curso == 2 && i>0) {
			if(ano_nascimento > aluno_mais_novo) {
				aluno_mais_novo = ano_nascimento;
			}
		} else {
			aluno_mais_novo = ano_nascimento;
		}
	}
	
	printf("%d aluno(s) escolheu(ram) o curso por aptidao!\n", qtd_aptidao);
	printf("%d esse e o ano de nascimento do aluno mais novo da computacao!\n", aluno_mais_novo);
	
	return 0;
}
