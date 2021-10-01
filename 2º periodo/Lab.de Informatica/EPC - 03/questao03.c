#include <stdio.h>
#include <string.h>

int main() {
	
	char palavra[250], palavra2[250];
	int cont = 0, i;
	
	gets(palavra); //recebe a palavra (podendo ter espaços)
	
	for(i = strlen(palavra)-1; i >= 0 ; i--) { //fazendo a inversão da palavra
		palavra2[cont] = palavra[i];
		printf("%c", palavra2[cont]); //apresenta a inversão das palavras
		cont++;
	}
	
	cont = 0;
	
	for(i = 0; i < strlen(palavra2); i++) { //fazendo a comparacão caso não seja
		if(palavra[i] != palavra2[i]) {
			printf("\nNao eh polindromo");
			cont = 1;
			break;
		}
	}
	
	if(cont != 1) { //se for ele apresenta a afirmação
		printf("\nEh polindromo");
	}				
	
	return 0;
}
