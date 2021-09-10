#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main() {
  int graus;
  float result;
  
  for(graus = 0; graus <= 360; graus+=5) {
    result = graus * (PI/180);
    printf("O seno de %d graus é %f\n", graus, sin(result));
  }
  return 0;
}
