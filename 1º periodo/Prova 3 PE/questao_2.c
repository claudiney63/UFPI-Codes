#include <stdio.h>
#define M 2
#define N 5

int ehNula(int mat[M][N]) {
	int L, C, cont = 0;
	for(L = 0; L < M; L++) {
		for(C = 0; C < N; C++) {
			if(mat[L][C] != 0) {
				cont++;
			}
		}
	}
	if(cont == 0) {
		cont = 1;
	} else {
		cont = 0;
	}
	return cont;
}

int main(){
	int mat[M][N] = {{0,0,1,0,0},{0,0,0,3,0}};
	if (ehNula(mat)) //chamada de ehNula
		printf("MATRIZ NULA\n");
	else
		printf("MATRIZ NAO NULA\n");
	return 0;
}



