#include <stdio.h>

int main() {
	
	int N, i;
	float A = 0.0;
	
	printf("Informe um numero positivo inteiro: ");
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
		A += ((float)(N-i)/(i+1));
	}
	
	printf("\nValor de A = %f", A);
	
	return 0;
}
