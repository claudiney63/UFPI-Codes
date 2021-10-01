#include <stdio.h>

int main() {
  int idade, menos_30 = 0, membros = 10;
  float media_idades = 0;
  
  while(membros--) {
    printf("\nInforme a idade de um membro: ");
    scanf("%d", &idade);
    if(idade < 30) {
      menos_30++;
    }
    media_idades = media_idades + idade;
  }
  
  printf("\nMembros com menos de 30 anos: %d", menos_30);
  printf("\nMedia das Idades: %f", media_idades/10);
  return 0;
}
