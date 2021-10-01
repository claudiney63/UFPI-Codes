#include <stdio.h>

int main() {
  int i = -1, num;
  
  printf("Informe um número: ");
  scanf("%d", &num);
  
  while(num--) {
    printf("%d ", i+=3);
  }
  
  return 0;
}
