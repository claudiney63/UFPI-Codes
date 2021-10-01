#include <stdio.h>
#include <math.h>

int main() {
  int valores_x;
  float valor_x, valor_y;
  
  printf("Quantos valores de (x) deseja inserir? : ");
  scanf("%d", &valores_x);
  
  while(valores_x--) {
    printf("Informe o valor de um X : ");
    scanf("%f", &valor_x);
    valor_y = sqrt(((valor_x*valor_x)+3)/2);
    printf("\nResult: %f\n\n", valor_y);
  }
  
  return 0;
}
