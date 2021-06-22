#include <stdio.h>
#include <string.h>

int main() {
	int copa=0, espada=0, ouro=0, paus=0, i;
	char string[52];
	int numCopa[52], nuEspada[52], numOuro[52], numPaus[52];
	
	scanf("%s", string);
	
	for(i = 0; i < 52; i += 3){
		if(string[i-1] == 'C') {
			copa++;
			numCopa[copa] = atoi(string[i-2]+string[i-3]);
			
		} else if(string[i-1] == 'E') {
			espada++;
			nuEspada[espada] = atoi(string[i-2]+string[i-3]);
			
		} else if(string[i-1] == 'U') {
			ouro++;
			numOuro[ouro] = atoi(string[i-2]+string[i-3]);
			
		} else if(string[i-1] == 'P') {
			paus++;
			numPaus[paus] = atoi(string[i-2]+string[i-3]);
		}
		//printf("%c", string[i-1]);
	}
	
	if(copa != 0) {
		int nDeuError = 1;
		for(i = 1; i < copa; i++) {
			if(i > 1) {
				if(numCopa[i-1] == numCopa[i]) {
					printf("error\n");
					nDeuError = 0;
					break;
				}
			}
		}
		if(nDeuError == 1) {
			printf("%d\n", 13-copa);
		}
	} else {
		printf("%d\n", copa);
	}
	
	if(espada != 0) {
		int nDeuError = 1;
		for(i = 1; i < espada; i++) {
			if(i > 1) {
				if(nuEspada[i-1] == nuEspada[i]) {
					printf("error\n");
					nDeuError = 0;
					break;
				}
			}
		}
		if(nDeuError == 1) {
			printf("%d\n", 13-espada);
		}
	} else {
		printf("%d\n", espada);
	}
	
	printf("%d\n", 13-espada);
	printf("%d\n", 13-ouro);
	printf("%d\n", 13-paus);
	
	return 0;
}
