#include <stdio.h>

int main() {
  int alunosQtd, i;
  
  printf("Informe quantos alunos receberam nota: ");
  scanf("%d", &alunosQtd);
  
  float notas1, notas2;
  
  for(i = 0; i < alunosQtd; i++) {
    printf("Aluno - %d\n", i+1);
    printf("Nota 1: ");
    scanf("%f", &notas1);
    printf("\nNota 2: ");
    scanf("%f", &notas2);
    printf("\n====================\n");
    printf("Media Aluno %d: %.2f", i+1, (notas1+notas2)/2);
    printf("\n====================\n\n");
  } 
  
  return 0;
}
