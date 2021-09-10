#include <stdio.h>

int main() {
	
	int i;
	float valor_h = 1/1;
	
	for(i = 2; i <= 10; i++) {
		if(i%2 == 0) {
			valor_h = valor_h - ((float)i/(i*i));
		} else {
			valor_h = valor_h + ((float)i/(i*i));
		}
	}
	
	printf("%f", valor_h);
	
	return 0;
}
