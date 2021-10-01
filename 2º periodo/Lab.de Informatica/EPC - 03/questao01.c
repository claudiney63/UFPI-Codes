#include <stdio.h>
#include <string.h>

int main() {
	
	char palavra[250];
	
	scanf("%s", palavra); //recebe a palavra (sem espaços)
	
	int i, j, tamStr = strlen(palavra); //recebe quantas caracteres possui
	
	for(i = 1; i <= tamStr; i++) {
		printf("\n");
		
		for(j = 0; j < i; j++) {
			printf("%s ", palavra);
		}
	}
	
	return 0;
}
