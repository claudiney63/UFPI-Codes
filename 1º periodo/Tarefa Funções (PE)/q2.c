#include <stdio.h>

void func(float *x, float *y) {
    float maior;
    if(*x > *y) {
        maior = *x;
        *x = *y;
        *y = maior;
    }
    return; 
}

int main() {
    float x, y;
    
    scanf("%f %f", &x, &y);
    func(&x, &y);
    printf("Menor: x = %.1f\n", x);
    printf("Maior: y = %.1f\n", y);
    
    return 0;
}
