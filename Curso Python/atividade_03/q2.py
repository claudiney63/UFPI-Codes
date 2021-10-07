# 2 – Faça um programa que receba 10 valores e depois mostre o maior valor, o
# menor valor e a média dos valores.

cont = 10
media = 0
maior = 0
menor = 0

while cont > 0 :
    num = float(input("Informe um número: "))
    media += num
    
    if cont == 10 :
        menor = num
    if cont == 9 :
        maior = num
        if menor > maior :
            aux = menor
            menor = maior
            maior = aux
    else :
        auxNum = num
        if menor > auxNum :
            menor = auxNum
        if maior < auxNum :
            maior = auxNum

    cont -= 1

print("Menor: ", menor)
print("Maior: ", maior)
print("Média: ", media/10)