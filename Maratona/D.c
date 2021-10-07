#include <stdio.h>
#include <string.h>

int main() {
	
	int qtdPontos, i, kiraNum = 0, lNum = 0;
	char jogador[10];
	
	scanf("%d", &qtdPontos);
	
	for(i = 0; i < qtdPontos; i++) {
		scanf("%s", jogador);
		!strcmp(jogador, "Kira") ?
			kiraNum++ :
			lNum++;	
	}
	
	if(kiraNum > lNum) {
		printf("Kira eh melhor que L!!!\n");
	} else {
		printf("L eh melhor que Kira!!!\n");
	}
	
	return 0;
}
