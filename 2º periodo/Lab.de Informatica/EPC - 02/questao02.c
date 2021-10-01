#include <stdio.h>

/* 2 - Dadas as temperaturas que foram registradas diariamente durante uma semana,
deseja-se determinar em quantos dias dessa semana a temperatura esteve acima
da média. Escreva um programa (utilizando vetores) para calcular esta
informação. */

int main() {
	
	int i;
	float temperatura[7], somaValores = 0.0, media;
	
	for(i = 0; i < 7; i++) {
		printf("Informe a temperatura do dia %d: ", i+1);
		scanf("%f", &temperatura[i]);
		somaValores += temperatura[i];
		printf("\n");
	}
	
	media = somaValores/i;
	
	printf("Media: %.2f\n\n", media);

	for(i = 0; i < 7; i++) {
		if(temperatura[i] > media) {
			printf("No dia %d teve temperatura de %.2f,", i+1, temperatura[i]);
			printf(" acima da media: %.2f\n\n", media);
		}
	}
	
	return 0;
}
