# 2 – Faça um programa que receba 10 valores e depois mostre o maior valor, o
# menor valor e a média dos valores.

cont = 10
media = 0
menor = 0
maior = 0

while cont > 0 :
    num = float(input("Informe um número: "))
    media += num
    
    if menor > num :
        menor = num
    if maior < num :
        maior = num
    
    cont -= 1

print("Menor: ", menor)
print("Maior: ", maior)
print("Média: ", media)