#include <stdio.h>
#define ARMAZEM 3
#define PRODUTO 4

void lerEstoque(int matriz[ARMAZEM][PRODUTO]) {
	int i, j;
	printf("Digite o estoque:\n");
	for(i=0; i<ARMAZEM; i++) { //percorre cada armazem
		printf("ARMAZEM %d:\n", (i+1));
		for(j=0; j<PRODUTO; j++) { //percorre cada produto
			printf("Produto %d: ", j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void lerCusto(float vetor[PRODUTO]) {
	int i;
	printf("\nDigite o custo de cada produto:\n");
	for(i=0; i<PRODUTO; i++) {
		printf("Produto %d: R$ ", (i+1));
		scanf("%f", &vetor[i]);
	}
}

void mostrarEstoque(int matriz[ARMAZEM][PRODUTO]) {
	int i, j;
	printf("\nESTOQUE: \n");
	for(i=0; i<PRODUTO; i++) { //percorre cada produto
		printf("PRODUTO %d:\n", (i+1));
		for(j=0; j<ARMAZEM; j++) { //percorre cada armazem
			printf("Armazem %d: %d\n", j+1, matriz[j][i]);
		}
	}
}

void qtdProdutosArmazem(int matriz[ARMAZEM][PRODUTO]) {
	int i, j, soma_produtos=0;
	printf("\nQuantidade total de produtos por armazém: :\n");
	for(i=0; i<ARMAZEM; i++) { //percorre cada armazem
		printf("ARMAZEM %d: ", i+1);
		for(j=0; j<PRODUTO; j++) { //percorre cada produto
			soma_produtos += matriz[i][j];
		}
		printf("%d\n", soma_produtos);
		soma_produtos = 0;
	}
}

void qtdProdutosTipo(int matriz[ARMAZEM][PRODUTO]) {
	int i, j, soma_produtos_tipo=0;
	printf("\nQuantidade total de produtos por tipo:\n");
	for(i=0; i<PRODUTO; i++) { //percorre cada produto
		printf("PRODUTO %d: ", i+1);
		for(j=0; j<ARMAZEM; j++) { //percorre cada armazem
			soma_produtos_tipo += matriz[j][i];
		}
		printf("%d\n", soma_produtos_tipo);
		soma_produtos_tipo = 0;
	}
}

void custoPorArmazem(int matriz[ARMAZEM][PRODUTO], float vetor[PRODUTO]) {
	int i, j;
	float custo_cada_armazem=0.0;
	printf("\nCusto total por armazém:\n");
	for(i=0; i<ARMAZEM; i++) { //percorre cada armazem
		printf("ARMAZEM %d: ", i+1);
		for(j=0; j<PRODUTO; j++) { //percorre cada produto
			custo_cada_armazem += matriz[i][j]*vetor[j];
		}
		printf("R$ %.2f\n", custo_cada_armazem);
		custo_cada_armazem = 0.0;
	}
}

void custoPorProduto(int matriz[ARMAZEM][PRODUTO], float vetor[PRODUTO]) {
	int i, j;
	float custo_cada_produto=0.0;
	printf("\nCusto total por produto:\n");
	for(i=0; i<PRODUTO; i++) { //percorre cada produto
		printf("PRODUTO %d: ", i+1);
		for(j=0; j<ARMAZEM; j++) { //percorre cada armazem
			custo_cada_produto += matriz[j][i]*vetor[i];
		}
		printf("R$ %.2f\n", custo_cada_produto);
		custo_cada_produto = 0.0;
	}
}
 
int main() {
	
    int estoque[ARMAZEM][PRODUTO];
    float custo_unitario[PRODUTO];
    
    lerEstoque(estoque);
    lerCusto(custo_unitario);
    mostrarEstoque(estoque);
    qtdProdutosArmazem(estoque);
    qtdProdutosTipo(estoque);
    custoPorArmazem(estoque, custo_unitario);
    custoPorProduto(estoque, custo_unitario);
    
    return 0;
}
