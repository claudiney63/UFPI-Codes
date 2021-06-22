#include <stdio.h>

int leNaoNegativo() {
    int valor;
    do{
        scanf("%d", &valor);
    }while(valor<0);
    return valor;
}

int somaDivisores(int num) {
    int soma=0;
    for(int i = 1; i<=num-1; i++) {
        if(num%i==0) {
            soma += i;
        }
    }
    return soma;
}

int saoAmigos(int x, int y) {
    if(somaDivisores(x) == y && somaDivisores(y) == x) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    
    if(saoAmigos(leNaoNegativo(), leNaoNegativo()) == 1) {
        printf("São amigos\n");
    } else {
        printf("Não são amigos\n");
    }
    
    return 0;
}
