#include <stdio.h>

int main() {
	
	int n, i, media = 0, divisor = 0;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	
	for(i = 0; i <= n; i++) {
		if((i%2) != 0 && i >= 0) {
			media += i;
			divisor++;
		}
	}
	
	printf("\nMedia : (%.1f)\n", (float)media/divisor);
	
	return 0;
}
