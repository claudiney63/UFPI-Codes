#include <stdio.h>
#include <string.h>

int main() {
	
	char palavra[250], palavra2[250];
	int cont = 0, i;
	
	gets(palavra); //recebe a palavra (podendo ter espa�os)
	
	for(i = strlen(palavra)-1; i >= 0 ; i--) { //fazendo a invers�o da palavra
		palavra2[cont] = palavra[i];
		printf("%c", palavra2[cont]); //apresenta a invers�o das palavras
		cont++;
	}
	
	cont = 0;
	
	for(i = 0; i < strlen(palavra2); i++) { //fazendo a comparac�o caso n�o seja
		if(palavra[i] != palavra2[i]) {
			printf("\nNao eh polindromo");
			cont = 1;
			break;
		}
	}
	
	if(cont != 1) { //se for ele apresenta a afirma��o
		printf("\nEh polindromo");
	}				
	
	return 0;
}
