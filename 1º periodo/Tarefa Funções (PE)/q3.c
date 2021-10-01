#include <stdio.h>

int ehTriangulo(float a, float b, float c) {
    if(a<(b+c) && b<(a+c) && c<(a+b)) {
        return 1;
    } else {
        return 0;
    }
}

float lePositivo() {
    float valor;
    do{
        scanf("%f", &valor);
    }while(valor<=0);
    return valor;
}

int tipoTriangulo(float a, float b, float c) {
    if(a==b && b==c && c==a){
      return 1;
    } else if((a!=b && b==c) || (b!=a && a==c) || (c!=b && b==a)) {
      return 2;
    } else if(a!=b && b!=c && a!=c) {
      return 3;
    } else {
      return 0;
    }
}

int main() {
    int n;
    float a, b, c;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        a = lePositivo();
        b = lePositivo();
        c = lePositivo();
        if(ehTriangulo(a, b, c)==0 || tipoTriangulo(a, b, c)==0) {
            printf("Nao eh um triangulo\n");
        } else {
           switch(tipoTriangulo(a, b, c)) {
               case 1: printf("triangulo equilátero\n");
               break;
               case 2: printf("triangulo isósceles\n");
               break;
               case 3: printf("triangulo escaleno\n");
               break;
           }
        }
    }
    return 0;
}
