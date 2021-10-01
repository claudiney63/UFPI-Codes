#include <stdio.h>

int main() {
	
	int qtd_jogos, pontos_finais=0, placar_time1, placar_time2;
	
	scanf("%d", &qtd_jogos);
	
	while(qtd_jogos != 0) {
		scanf("%d %d", &placar_time1, &placar_time2);
		if(placar_time1 > placar_time2) {
			pontos_finais += 3;
		} else if (placar_time1 == placar_time2 && placar_time1!=0) {
			pontos_finais += 1;
		}
		qtd_jogos--;
	}
	
	printf("\n%d\n", pontos_finais);
	
	return 0;
}
