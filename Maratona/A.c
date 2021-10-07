#include <stdio.h>
#include <string.h>

/*
6 3
100 fallen
96 yuri
99 fnx
50 gaules
38 lindinho
101 dadinho
*/

int main() {
	
	int N, Q, i, j, aux;
	
	scanf("%d %d", &N, &Q);
	
	char M[N][10];
	int V[N];
	
	for(i = 0; i < N; i++) {
		scanf("%d %s", &V[i], &M[i]);
	}
	
	for(i = 0; i < N; i++) {
		for(j = 1; j < N-1; j++) {
			if(V[i] > V[j]) {
				aux = V[i];
				V[i] = V[j];
				V[j] = aux;
				aux = i;
				strcpy(M[i], M[j]);
				strcpy(M[j], M[aux]);
			}
		}
	}
	
	for(i = 0; i < N; i++) {
		printf("%d %s\n", V[i], M[i]);
	}
	
	return 0;
}
