#include <stdio.h>

int main() {
	
	int alunos = 4, idade, i, idade_media = 0;
	float altura, altura_media = 0.0;
	
	for(i = 0; i < alunos; i++) {
		printf("\nInforme a idade: ");
		scanf("%d", &idade);
		printf("Informe a altura(m): ");
		scanf("%f", &altura);
		
		if(altura < 1.70) {
			idade_media += idade;
		}
		
		if(idade > 20) {
			altura_media += altura;
		}
	}
	
	printf("\nIdade media quem possui menos de 1,70m : (%d)\n", idade_media/alunos);
	printf("Altura media das pessoas com mais de 20 anos : (%.2fm)\n", altura_media/alunos);
	
	return 0;
}
