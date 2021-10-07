# 3 – Faça um programa que receba 10 coordenadas (x, y) e salve em um tupla e
# salve as tuplas dentro de uma lista. Depois leia a lista e calcule a distância de
# cada coordenada para a origem.

i = 0
lista_de_tuplas = []

while i < 3 :
    x = float(input("Informe a coordenada x: "))
    y = float(input("Informe a coordenada y: "))
    tupla_de_coordenadas = (x, y)
    lista_de_tuplas.insert(i, tupla_de_coordenadas)
    i += 1

i = 0
while i < 3 :
    x = lista_de_tuplas[i][0]
    y = lista_de_tuplas[i][1]
    distancia = (((x - 0)*(x - 0)) + ((y - 0)*(y - 0)))
    print(f"{i+1}ª coordenada distancia: {distancia}")
    i += 1
    