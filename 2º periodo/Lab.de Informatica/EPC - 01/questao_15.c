#include <stdio.h>

int main() {
	
	int i, soma = 0;
	
	for(i = 86; i < 907; i++) {
		printf("%d\n", i);
		if(i%2 == 0) {
			soma += i;
		}
	}
	
	printf("\nSoma : (%d)\n", soma);
	
	return 0;
}
