#include <stdio.h>

int main() {
  int i = 0, num;
  
  printf("Informe um n�mero: ");
  scanf("%d", &num);
  
  while(num--) {
    printf("%d ", i+=2);
  }
  
  return 0;
}
