#include <stdio.h>
#include <string.h>

int main() {
	
	char string[250], string2[250];
	
	gets(string);
	gets(string2);
	
	int i, j, cont = 0, aux;
	
	for(i = 0; i < strlen(string); i++) { //inicia uma caractere da primeira string
		aux = i; //guarda a posica de inicio
		for(j = 0; j < strlen(string2); j++) {
			if(string[aux] == string2[j]) { //faz a comparacao com cada letra ate o fim da string2
				cont++;
				aux++;
			} else {
				cont = 0;
				break;
			}
		}
		aux = 0;
		if(cont == strlen(string2)) { //caso cont percorreu toda a segunda string sinal que tudo era igual
			break;
		}
	}
	
	if(cont != 0) { 
		printf("\nSUBSTRING");
	} else {
		printf("\nNAO SUBSTRING");
	}
	
	return 0;
}
