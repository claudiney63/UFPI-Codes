#include <stdio.h>
#include <math.h>

/*
3 - Escreva uma função que calcule e retorne a distância entre dois pontos (x1, y1) e
(x2, y2). Todos os números e valores de retorno devem ser do tipo float.
*/


int main() {
	
	float x1, x2, y1, y2, distancia;
	
	printf("Informe o ponto x1: ");
	scanf("%f", &x1);
	printf("Informe o ponto x2: ");
	scanf("%f", &x2);
	printf("Informe o ponto y1: ");
	scanf("%f", &y1);
	printf("Informe o ponto y2: ");
	scanf("%f", &y2);
	
	distancia = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
	
	printf("\nDistancia entre os dois pontos (x1, y1) e (x2, y2): %.2f\n", distancia);
	
	return 0;
}
