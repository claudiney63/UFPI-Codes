#include <stdio.h>

int main() {
	
	int x, y, i, result = 0;
	
	printf("Informe um valor: ");
	scanf("%d", &x);
	printf("Informe outro valor: ");
	scanf("%d", &y);
	
	for(i = 0; i < y; i++) {
		result += x;
	}
	
	printf("\n%d x %d = %d", x, y, result);
	
	return 0;
}
