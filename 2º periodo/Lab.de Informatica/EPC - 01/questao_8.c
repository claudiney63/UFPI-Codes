#include <stdio.h>

int fat(int num) {
	if(num <= 1) {
		return 1;
	}
	return num * fat(num-1);
}

int main() {
	
	int n;
	
	printf("Informe um valor inteiro: ");
	scanf("%d", &n);
	
	printf("\nFatorial de %d! = %d\n", n, fat(n));
	
	return 0;
}
