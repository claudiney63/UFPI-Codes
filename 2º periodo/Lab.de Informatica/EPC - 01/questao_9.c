#include <stdio.h>
#define TAM 10

int main() {
	
	char nome[50];
	int idade;
	float altura;
	int sexo; //1 - masculino, 2 - feminino
	float maior_altura = 0, media_altura_mulheres = 0, porcentagem_mulheres = 0;
	int qtd_homens = 0, cont, divisor_media_altura_mulheres = 0, cont_char;
	char qual_nome[50];
	
	for(cont = 0; cont < TAM; cont++) {
		printf("Informe o nome da %d pessoa: ", cont+1);
		scanf("%s", nome);
		printf("Informe o idade da %d pessoa: ", cont+1);
		scanf("%d", &idade);
		printf("Informe o altura da %d pessoa: ", cont+1);
		scanf("%f", &altura);
		printf("Informe o sexo(1-Masulino / 2-Feminino) da %d pessoa: ", cont+1);
		scanf("%d", &sexo);
		printf("\n\n");
		
		if(maior_altura < altura) { //verificando maior altura
			maior_altura = altura;
			for(cont_char = 0; cont_char < 50; cont_char++) {
				qual_nome[cont_char] = nome[cont_char];
			}
		}
		if(sexo == 2) { //pegando alturas das mulheres
			media_altura_mulheres += altura;
			divisor_media_altura_mulheres++;
			porcentagem_mulheres += 1.0;
		}
		if(sexo == 1) { //pegando quantidae de homens
			qtd_homens++;
		}
	}
	
	printf("Maior altura = %.2f da pessoa (%s)\n", maior_altura, qual_nome);
	printf("Media da altura das mulheres = %.2f\n", media_altura_mulheres/divisor_media_altura_mulheres);
	printf("Quantidade de homens : (%d)\n", qtd_homens);
	printf("Porcentagem de Mulheres : (%.1f%%)\n", (porcentagem_mulheres*100)/TAM);
	
	return 0;
}
