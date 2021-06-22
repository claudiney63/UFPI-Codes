#include <stdio.h>
/*
//------ Version 1 -----//

void calcValor(float valorProduto, float valorCusto, int qtd) {
    return printf("Valor Ganho: R$ %.2f", (valorProduto - valorCusto)*(float)qtd);
}

int main() {
    float valorProduto, valorCusto;
    int qtd;
    
    scanf("%f %f %d", &valorProduto, &valorCusto, &qtd);
    calcValor(valorProduto, valorCusto, qtd);
    
    return 0;
}
*/

/*
//------ Version 2 -----//

float calcValor() {
    float valorProduto, valorCusto;
    int qtd;
    scanf("%f %f %d", &valorProduto, &valorCusto, &qtd);
    return (valorProduto - valorCusto)*(float)qtd;
}

int main() {
    printf("Valor Ganho: R$ %.2f", calcValor()); 
    return 0;
}
*/
