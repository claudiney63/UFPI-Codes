#include <stdio.h>
#include <string.h>

int main() {
	
	char palavra[250];
	
	gets(palavra); //recebe a palavra (podendo ter espa�os)
	
	int i, tamStr = strlen(palavra);
	
	tamStr /= 2;
	
	for(i = 0; i < tamStr; i++) { //imprimindo cada caractere, mas sem vogal
		char carac = palavra[i];
		if(carac != 'a' && carac != 'e' && carac != 'i' && carac != 'o' && carac != 'u') {
			printf("%c", palavra[i]);
		}
	}

	
	return 0;
}
