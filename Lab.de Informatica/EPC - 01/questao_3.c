#include <stdio.h>

int main() {
  int i = -1, num;
  
  printf("Informe um n�mero: ");
  scanf("%d", &num);
  
  while(num--) {
    printf("%d ", i+=3);
  }
  
  return 0;
}
