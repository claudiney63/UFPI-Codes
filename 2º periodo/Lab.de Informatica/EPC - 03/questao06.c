#include <stdio.h>
#include <string.h>

int main() {
	
	char senha[250], senha2[250] = "Batatinha Frita 1, 2, 3";
	int i, cont = 0;
	
	gets(senha);
	
	for(i = 0; i < strlen(senha2); i++) { //fazendo a comparacão caso não seja
		if(senha[i] != senha2[i]) {
			printf("\nSenha Incorreta!");
			cont = 1;
			break;
		}
	}
	
	if(cont != 1) { //se for ele apresenta a afirmação
		printf("\nSenha correta!");
	}				
	
	
	return 0;
}
