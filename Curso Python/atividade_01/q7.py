# 7 – Escreva um programa que leia as coordenadas x e y de pontos do R^2 e calcule
# sua distância da origem (0, 0). Use a fórmula da distância.

import math

x1 = float(input("Digite a coordenada X1: "))

x2 = float(input("Digite a coordenada X2: "))

y1 = float(input("Digite a coordenada Y1: "))

y2 = float(input("Digite a coordenada Y2: "))

distancia = (((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)))

print("A distancia entre os pontos é: ", math.sqrt(distancia))