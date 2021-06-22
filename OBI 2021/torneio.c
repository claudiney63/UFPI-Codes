#include <stdio.h>

int main() {
	int linhas = 6;
	char vence_ou_perde, vencidas = 0;
	
	while(linhas--) {
		scanf(" %c", &vence_ou_perde);
		if(vence_ou_perde == 'V') {
			vencidas++;
		}
	}
	
	if(vencidas == 5 || vencidas==6) {
		printf("1\n");
	} else if (vencidas == 3 || vencidas == 4) {
		printf("2\n");
	} else if (vencidas == 1 || vencidas == 2) {
		printf("3\n");
	} else {
		printf("-1\n");
	}
	
	return 0;
}
