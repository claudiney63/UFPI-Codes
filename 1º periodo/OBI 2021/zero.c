#include <stdio.h>

int main() {
	int N, X, i, soma=0, cont=-1;
	scanf("%d", &N);
	int vetor[N], remove0[N];
	for(i = 0; i < N; i++) {
		scanf("%d", &X);
		if(X != 0) {
			vetor[i] = X;
			soma += vetor[i];
			printf("Soma: %d\n", soma);
			cont++;
			remove0[cont] = i;
		} else {
			soma -= vetor[remove0[cont]];
			printf("Soma: %d\n", soma);
			cont--;
		}
	}
	printf("%d\n", soma);
	
	return 0;
}
