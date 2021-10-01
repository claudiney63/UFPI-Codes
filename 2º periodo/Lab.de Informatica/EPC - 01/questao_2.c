#include <stdio.h>

int main() {
  int i = 0, num;
  
  printf("Informe um número: ");
  scanf("%d", &num);
  
  while(num--) {
    printf("%d ", i+=2);
  }
  
  return 0;
}
