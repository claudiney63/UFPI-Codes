# 1 – Faça um programa que leia seis valores inteiros e depois mostre na tela os
# valores.

i = 0
valores = []
while i < 6 :
    valor = int(input("Informe um número: "))
    valores.insert(i, valor)
    i += 1

print("Valores: ", valores)